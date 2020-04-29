# discoDSP OPL FM synth plugin for macOS AU / VST / VST3 / Standalone #

![OPL AU plugin](https://www.discodsp.com/img/opl.png)

This instrument provides an emulated OPL sound chip. It provides all features of the OPL2, and some features of the OPL3. It is a slightly modified JUCEOPLVSTi build compiled for macOS only. -[The original coder and author is Bruce Sutherland](http://bsutherland.github.io/JuceOPLVSTi/).

## Binaries ##

**Release 1.0.0**

 https://github.com/reales/OPL/releases/download/1.0/OPL10Mac.zip 

 - Built with JUCE 5.4.7
 - Notarized and code signed.

## What's an OPL? ##

The OPL is a digital sound synthesis chip developed by Yamaha in the mid 1980s. Among other products, it was used in sound cards for PC, including the Ad Lib card and early Sound Blaster series.

At a technical level: the emulator has channels comprised of 2 oscillators each. Each pair of oscillators is usually combined via phase modulation (basically frequency modulation). Each oscillator can produce one of eight waveforms (sine, half sine, absolute sine, quarter sine, alternating sine, camel sine, square, logarithmic sawtooth), and has an ADSR envelope controlling its amplitude. The unusual waveforms give it a characteristic sound.

## How do I use it? ##

Each instance of the plugin emulates an entire OPL chip, but with this plugin, essentially you are just working with two operators: the carrier and modulator.

Some documentation which may be useful:

- [Introduction to FM Synthesis](https://www.youtube.com/watch?v=ziFv00PegJg) (not specific to the OPL, but a great primer)
- [OPL2 on Wikipedia](http://en.wikipedia.org/wiki/Yamaha_YM3812)
- [Original Yamaha datasheet](http://www.alldatasheet.com/datasheet-pdf/pdf/84281/YAMAHA/YM3812.html)
- [AdLib programming guide](http://www.shipbrook.net/jeff/sb.html) Dates back to 1991!
- [Another programming guide](http://www.ugcs.caltech.edu/~john/computer/opledit/tech/opl3.txt) This one is for the OPL3, but most of the information still applies.

## What can it do? ##

Here are some examples:

- [Demo showing how parameters affect sound](https://www.youtube.com/watch?v=yU0CWQ66Z28)Thanks estonoesunusuario!
- [Dune 2 music reproduced using the plugin](https://www.youtube.com/watch?v=w6Lu0C_vZwQ)Great work by Ion Claudiu Van Damme
- [Tyrian remix](https://www.youtube.com/watch?v=ZGwhKVFMCqM) by Block35 Music
- [Syndicate theme](https://www.youtube.com/watch?v=HI7U5XxTSW0) demo I created for the first release
- (your link here...)

### SBI FIles ###

SBI files are an instrument file format developed by Creative Labs back in the day for the Sound Blaster. Essentially they work as presets for this plugin. Just drag and drop them into the plugin window!

I've collected a bunch of presets in this repository. I've also added support for saving SBI files. Please contribute!

It's possible to extract SBI instruments from games using [DOSBox 0.7.2](https://sourceforge.net/projects/dosbox/files/dosbox/0.72/) and [DRO2MIDI](https://github.com/Malvineous/dro2midi) by Malvineous.

1. Run the game in DOSBox.
2. Start capturing OPL output with ctrl+alt+F7. Output will be recorded to a .dro file.
3. Run DRO2MIDI:
  `dro2midi -s input_capture.dro output_midi.mid`

Note data will be extracted to .mid, instruments will be extracted to .sbi files.

### Percussion ###

Percussion mode is now supported! This mode is not very well documented, even in the original Yamaha documentation. Here are some tips on using it based on experimentation and looking at the DOSBox source code.

- Bass drum: Uses both operators. Essentially just doubles output amplitude?
- Snare: Uses carrier settings. Abs-sine waveform recommended.
- Tom: Uses modulator settings. Sine waveform recommended.
- Cymbal: Uses carrier settings. Half-sine recommended.
- Hi-hat: Uses modulator settings. Half-sine recommended.

Also, some [much more detailed notes](http://midibox.org/forums/topic/18625-opl3-percussion-mode-map/) on percussion mode based on experimentation with real hardware!
