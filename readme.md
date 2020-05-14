# discoDSP OPL FM synth plugin #

This instrument provides an emulated OPL sound chip. It provides all features of the OPL2, and some features of the OPL3. It is a slightly modified JUCEOPLVSTi build compiled for macOS only. [The original coder and author is Bruce Sutherland](http://bsutherland.github.io/JuceOPLVSTi/).

## Binaries ##

**Release 1.1**

**Windows** https://github.com/reales/OPL/releases/download/v1.1/OPL11Windows.zip

**Mac** https://github.com/reales/OPL/releases/download/v1.1/OPL11Mac.zip

**Linux** https://github.com/reales/OPL/releases/download/v1.1/OPL11Windows.zip

 - AU / VST / VST3 / Standalone.
 - Built with JUCE 5.4.7
 - Notarized and code signed.

## What's an OPL? ##

The OPL is a digital sound synthesis chip developed by Yamaha in the mid 1980s. Among other products, it was used in sound cards for PC, including the Ad Lib card and early Sound Blaster series.

At a technical level: the emulator has channels comprised of 2 oscillators each. Each pair of oscillators is usually combined via phase modulation (basically frequency modulation). Each oscillator can produce one of eight waveforms (sine, half sine, absolute sine, quarter sine, alternating sine, camel sine, square, logarithmic sawtooth), and has an ADSR envelope controlling its amplitude. The unusual waveforms give it a characteristic sound.

## How do I use it? ##

Each instance of the plugin emulates an entire OPL chip, but with this plugin, essentially you are just working with two operators: the carrier and modulator.

Some documentation which may be useful:

- [OPL2 on Wikipedia](http://en.wikipedia.org/wiki/Yamaha_YM3812)
- [Original Yamaha datasheet](http://www.alldatasheet.com/datasheet-pdf/pdf/84281/YAMAHA/YM3812.html)

## What can it do? ##

Here are some examples:

- [Demo showing how parameters affect sound](https://www.youtube.com/watch?v=yU0CWQ66Z28) Thanks estonoesunusuario!
- [Tyrian remix](https://www.youtube.com/watch?v=ZGwhKVFMCqM) by Block35 Music

### SBI Files ###

SBI files are an instrument file format developed by Creative Labs back in the day for the Sound Blaster. Essentially they work as presets for this plugin. Just drag and drop them into the plugin window!

### Percussion ###

Percussion mode is now supported! This mode is not very well documented, even in the original Yamaha documentation. Here are some tips on using it based on experimentation and looking at the DOSBox source code. Also, some [much more detailed notes](http://midibox.org/forums/topic/18625-opl3-percussion-mode-map/) on percussion mode based on experimentation with real hardware!

- Bass drum: Uses both operators. Essentially just doubles output amplitude?
- Snare: Uses carrier settings. Abs-sine waveform recommended.
- Tom: Uses modulator settings. Sine waveform recommended.
- Cymbal: Uses carrier settings. Half-sine recommended.
- Hi-hat: Uses modulator settings. Half-sine recommended.


