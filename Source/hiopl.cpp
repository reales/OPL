#include "Hiopl.h"

#include <assert.h>

// A higher level wrapper around the DOSBox OPL emulator.

Hiopl::Hiopl(int buflen) {
	adlib = new DBOPL::Handler();
	Buf32 = new Bit32s[buflen];
}

void Hiopl::Generate(int length, short* buffer) {
	//printf("Generating %d samples\n", length);
	adlib->Generate(length, Buf32);
	for (int i = 0; i < length; i++) {
		buffer[i] = (short)(Buf32[i]);
	}
}

void Hiopl::Generate(int length, float* buffer) {
	// This would be better done using Juce's built in audio format conversion.
	adlib->Generate(length, Buf32);
	for (int i = 0; i < length; i++) {
		buffer[i] = (float)(Buf32[i])/32768.0f;
	}
}

void Hiopl::SetSampleRate(int hz) {
	adlib->Init(hz);
	_WriteReg(0x20,0x32);	// modulator multiplier 2
	_WriteReg(0x23,0x21);	// carrier multiplier 1
	_WriteReg(0x40,0x1a);	// modulator level
	_WriteReg(0x43,0x09);	// carrier level
	_WriteReg(0x60,0x84);	// AD
	_WriteReg(0x63,0x84);	// AD
	_WriteReg(0x80,0x29);	// SR
	_WriteReg(0x83,0x44);	// SR
	_WriteReg(0xe3,0x00);	// wave select
	_WriteReg(0xe0,0x02);	// wave select
	_WriteReg(0xc0,0x06);	// carrier self-feedback level
}

void Hiopl::_WriteReg(Bit32u reg, Bit8u value) {
	adlib->WriteReg(reg, value);
	regCache[reg] = value;
}

void Hiopl::_ClearRegBits(Bit32u reg, Bit8u mask) {
	_WriteReg(reg, regCache[reg] & ~mask);
}

void Hiopl::SetWaveform(int ch, int osc, Waveform wave) {
	assert(_CheckParams(ch, osc));
	_WriteReg(0xe0+2*ch+osc, (Bit8u)wave);
}

Waveform Hiopl::GetWaveform(int ch, int osc) {
	assert(_CheckParams(ch, osc));
	return static_cast<Waveform>(regCache[0xe0+2*ch+osc]);
}

void Hiopl::KeyOn(int ch, float frqHz) {
	unsigned int fnum, block;
	_milliHertzToFnum((unsigned int)(frqHz * 1000.0), &fnum, &block);
	_WriteReg(0xa0, fnum % 0x100);
	_WriteReg(0xb0, 0x20|((block&0x7)<<2)|(0x3&(fnum/0x100)));
	//_WriteReg(0xa0, 0x8b);
	//_WriteReg(0xb0, 0x26);
}

void Hiopl::KeyOff(int ch) {
	_ClearRegBits(0xb0, 0x20);
}

// from libgamemusic, opl-util.cpp
void Hiopl::_milliHertzToFnum(unsigned int milliHertz,
	unsigned int *fnum, unsigned int *block, unsigned int conversionFactor)
{
	// Special case to avoid divide by zero
	if (milliHertz == 0) {
		*block = 0; // actually any block will work
		*fnum = 0;
		return;
	}
	// Special case for frequencies too high to produce
	if (milliHertz > 6208431) {
		*block = 7;
		*fnum = 1023;
		return;
	}

	// This is a bit more efficient and doesn't need log2() from math.h
	if (milliHertz > 3104215) *block = 7;
	else if (milliHertz > 1552107) *block = 6;
	else if (milliHertz > 776053) *block = 5;
	else if (milliHertz > 388026) *block = 4;
	else if (milliHertz > 194013) *block = 3;
	else if (milliHertz > 97006) *block = 2;
	else if (milliHertz > 48503) *block = 1;
	else *block = 0;

	// Slightly more efficient version
	*fnum = ((unsigned long long)milliHertz << (20 - *block)) / (conversionFactor * 1000.0) + 0.5;
	if ((*block == 7) && (*fnum > 1023)) {
		// frequency out of range, clipping to maximum value.
		*fnum = 1023;
	}
	assert(*block <= 7);
	assert(*fnum < 1024);
	return;
}

Hiopl::~Hiopl() {
	delete Buf32;
};

bool Hiopl::_CheckParams(int ch, int osc) {
	return ch >= 0 && ch < CHANNELS && osc >= 0 && osc < OSCILLATORS;
}