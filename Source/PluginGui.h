/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.3.2

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <array>
#include "JuceHeader.h"
#include "PluginProcessor.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
	This is a GUI for the OPL2 VST plugin, created in Juce.
                                                                    //[/Comments]
*/
class PluginGui  : public AudioProcessorEditor,
                   public FileDragAndDropTarget,
                   public DragAndDropContainer,
                   public Timer,
                   public ComboBox::Listener,
                   public Slider::Listener,
                   public Button::Listener
{
public:
    //==============================================================================
    PluginGui (AdlibBlasterAudioProcessor* ownerFilter);
    ~PluginGui();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void updateFromParameters();
    bool isInterestedInFileDrag (const StringArray& files) override;
    void fileDragEnter (const StringArray& files, int x, int y) override;
    void fileDragMove (const StringArray& files, int x, int y) override;
    void fileDragExit (const StringArray& files) override;
    void filesDropped (const StringArray& files, int x, int y) override;
	void timerCallback() override;
	void setRecordButtonState(bool recording);
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void buttonClicked (Button* buttonThatWasClicked) override;

    // Binary resources:
    static const char* full_sine_png;
    static const int full_sine_pngSize;
    static const char* half_sine_png;
    static const int half_sine_pngSize;
    static const char* abs_sine_png;
    static const int abs_sine_pngSize;
    static const char* quarter_sine_png;
    static const int quarter_sine_pngSize;
    static const char* camel_sine_png;
    static const int camel_sine_pngSize;
    static const char* alternating_sine_png;
    static const int alternating_sine_pngSize;
    static const char* square_png;
    static const int square_pngSize;
    static const char* logarithmic_saw_png;
    static const int logarithmic_saw_pngSize;
    static const char* channeloff_png;
    static const int channeloff_pngSize;
    static const char* channelon_png;
    static const int channelon_pngSize;
    static const char* toggle_off_sq_png;
    static const int toggle_off_sq_pngSize;
    static const char* toggle_on_sq_png;
    static const int toggle_on_sq_pngSize;
    static const char* line_border_horiz_png;
    static const int line_border_horiz_pngSize;
    static const char* line_border_vert_png;
    static const int line_border_vert_pngSize;
    static const char* algo_switch_off_png;
    static const int algo_switch_off_pngSize;
    static const char* algo_switch_on_png;
    static const int algo_switch_on_pngSize;
    static const char* algo_switch_on2_png;
    static const int algo_switch_on2_pngSize;
    static const char* algo_switch_on3_png;
    static const int algo_switch_on3_pngSize;
    static const char* twoopAm_png;
    static const int twoopAm_pngSize;
    static const char* twoopFm_png;
    static const int twoopFm_pngSize;
    static const char* bassdrum_png;
    static const int bassdrum_pngSize;
    static const char* snare_png;
    static const int snare_pngSize;
    static const char* disabled_png;
    static const int disabled_pngSize;
    static const char* tom_png;
    static const int tom_pngSize;
    static const char* hihat_png;
    static const int hihat_pngSize;
    static const char* cymbal_png;
    static const int cymbal_pngSize;
    static const char* adlib_png;
    static const int adlib_pngSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	static const uint32 COLOUR_MID = 0xff007f00;
	static const uint32 COLOUR_RECORDING = 0xffff0000;
	AdlibBlasterAudioProcessor* processor;
	std::array<ScopedPointer<TextButton>, Hiopl::CHANNELS> channels;
	TooltipWindow tooltipWindow;
#if JUCE_MAC
    File instrumentLoadDirectory = File::getSpecialLocation(File::userDocumentsDirectory).getChildFile("discoDSP").getChildFile("OPL"); // File();
    File instrumentSaveDirectory = File::getSpecialLocation(File::userDocumentsDirectory).getChildFile("discoDSP").getChildFile("OPL"); // File();
#endif
#if JUCE_IOS
    File instrumentLoadDirectory = File::getSpecialLocation(File::userDocumentsDirectory); // File();
    File instrumentSaveDirectory = File::getSpecialLocation(File::userDocumentsDirectory); // File();
#endif
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<GroupComponent> groupComponent2;
    std::unique_ptr<GroupComponent> groupComponent4;
    std::unique_ptr<GroupComponent> groupComponent11;
    std::unique_ptr<GroupComponent> groupComponent10;
    std::unique_ptr<GroupComponent> groupComponent9;
    std::unique_ptr<GroupComponent> groupComponent;
    std::unique_ptr<ComboBox> frequencyComboBox;
    std::unique_ptr<Label> frequencyLabel;
    std::unique_ptr<Slider> aSlider;
    std::unique_ptr<Label> aLabel;
    std::unique_ptr<Slider> dSlider;
    std::unique_ptr<Label> dLabel;
    std::unique_ptr<Slider> sSlider;
    std::unique_ptr<Label> dLabel2;
    std::unique_ptr<Slider> rSlider;
    std::unique_ptr<Label> rLabel;
    std::unique_ptr<Slider> attenuationSlider;
    std::unique_ptr<Label> attenuationLabel;
    std::unique_ptr<Label> dbLabel;
    std::unique_ptr<ImageButton> sineImageButton;
    std::unique_ptr<ImageButton> halfsineImageButton;
    std::unique_ptr<ImageButton> abssineImageButton;
    std::unique_ptr<ImageButton> quartersineImageButton;
    std::unique_ptr<Label> waveLabel;
    std::unique_ptr<ToggleButton> tremoloButton;
    std::unique_ptr<ToggleButton> vibratoButton;
    std::unique_ptr<ToggleButton> sustainButton;
    std::unique_ptr<ToggleButton> keyscaleEnvButton;
    std::unique_ptr<Label> dbLabel2;
    std::unique_ptr<ComboBox> frequencyComboBox2;
    std::unique_ptr<Label> frequencyLabel3;
    std::unique_ptr<Slider> aSlider2;
    std::unique_ptr<Label> aLabel2;
    std::unique_ptr<Slider> dSlider2;
    std::unique_ptr<Label> dLabel3;
    std::unique_ptr<Slider> sSlider2;
    std::unique_ptr<Label> dLabel4;
    std::unique_ptr<Slider> rSlider2;
    std::unique_ptr<Label> rLabel2;
    std::unique_ptr<Slider> attenuationSlider2;
    std::unique_ptr<Label> attenuationLabel2;
    std::unique_ptr<Label> dbLabel3;
    std::unique_ptr<ImageButton> sineImageButton2;
    std::unique_ptr<ImageButton> halfsineImageButton2;
    std::unique_ptr<ImageButton> abssineImageButton2;
    std::unique_ptr<ImageButton> quartersineImageButton2;
    std::unique_ptr<Label> waveLabel2;
    std::unique_ptr<ToggleButton> tremoloButton2;
    std::unique_ptr<ToggleButton> vibratoButton2;
    std::unique_ptr<ToggleButton> sustainButton2;
    std::unique_ptr<ToggleButton> keyscaleEnvButton2;
    std::unique_ptr<Label> frequencyLabel4;
    std::unique_ptr<GroupComponent> groupComponent3;
    std::unique_ptr<Slider> tremoloSlider;
    std::unique_ptr<Label> frequencyLabel5;
    std::unique_ptr<Label> dbLabel5;
    std::unique_ptr<Slider> vibratoSlider;
    std::unique_ptr<Label> frequencyLabel6;
    std::unique_ptr<Label> dbLabel6;
    std::unique_ptr<Slider> feedbackSlider;
    std::unique_ptr<Label> frequencyLabel7;
    std::unique_ptr<ComboBox> velocityComboBox;
    std::unique_ptr<ComboBox> velocityComboBox2;
    std::unique_ptr<Label> attenuationLabel4;
    std::unique_ptr<ImageButton> alternatingsineImageButton;
    std::unique_ptr<ImageButton> camelsineImageButton;
    std::unique_ptr<ImageButton> squareImageButton;
    std::unique_ptr<ImageButton> logsawImageButton;
    std::unique_ptr<ImageButton> alternatingsineImageButton2;
    std::unique_ptr<ImageButton> camelsineImageButton2;
    std::unique_ptr<ImageButton> squareImageButton2;
    std::unique_ptr<ImageButton> logsawImageButton2;
    std::unique_ptr<Label> dbLabel4;
    std::unique_ptr<ComboBox> keyscaleAttenuationComboBox2;
    std::unique_ptr<ComboBox> keyscaleAttenuationComboBox;
    std::unique_ptr<GroupComponent> groupComponent5;
    std::unique_ptr<Slider> emulatorSlider;
    std::unique_ptr<Label> emulatorLabel;
    std::unique_ptr<Label> emulatorLabel2;
    std::unique_ptr<ToggleButton> recordButton;
    std::unique_ptr<TextButton> exportButton;
    std::unique_ptr<TextButton> loadButton;
    std::unique_ptr<Label> versionLabel;
    std::unique_ptr<ImageButton> ToggleButtonOffExample;
    std::unique_ptr<ImageButton> ToggleButtonOnExample;
    std::unique_ptr<Label> label;
    std::unique_ptr<Label> label2;
    std::unique_ptr<ImageButton> LineBorderButton1C;
    std::unique_ptr<ImageButton> LineBorderButton1A;
    std::unique_ptr<ImageButton> LineBorderButton1B;
    std::unique_ptr<Label> label3;
    std::unique_ptr<ImageButton> LineBorderButton1C2;
    std::unique_ptr<ImageButton> LineBorderButton1A2;
    std::unique_ptr<ImageButton> LineBorderButton1B2;
    std::unique_ptr<ImageButton> LineBorderButton1C3;
    std::unique_ptr<ImageButton> LineBorderButton1B3;
    std::unique_ptr<ImageButton> algoSwitchButtonOffEx1;
    std::unique_ptr<ImageButton> algoSwitchButtonOffEx2;
    std::unique_ptr<ImageButton> algoSwitchButtonOnEx1;
    std::unique_ptr<ImageButton> algoSwitchButtonOnEx2;
    std::unique_ptr<Label> label4;
    std::unique_ptr<Label> label5;
    std::unique_ptr<Label> label6;
    std::unique_ptr<Label> label7;
    std::unique_ptr<Label> label8;
    std::unique_ptr<ImageButton> algoSwitchButtonOn2Ex1;
    std::unique_ptr<ImageButton> algoSwitchButtonOn2Ex2;
    std::unique_ptr<Label> label9;
    std::unique_ptr<Label> label10;
    std::unique_ptr<ImageButton> algoSwitchButtonOn3Ex1;
    std::unique_ptr<ImageButton> algoSwitchButtonOn3Ex2;
    std::unique_ptr<Label> label11;
    std::unique_ptr<Label> label12;
    std::unique_ptr<ImageButton> TwoOpAMButton;
    std::unique_ptr<ImageButton> TwoOpFMButton;
    std::unique_ptr<Label> label13;
    std::unique_ptr<Label> label14;
    std::unique_ptr<Label> label15;
    std::unique_ptr<Label> label16;
    std::unique_ptr<Label> label17;
    std::unique_ptr<GroupComponent> groupComponent6;
    std::unique_ptr<ImageButton> algoSwitchButtonOnEx3;
    std::unique_ptr<Label> label18;
    std::unique_ptr<ImageButton> algoSwitchButtonOffEx3;
    std::unique_ptr<Label> label19;
    std::unique_ptr<ImageButton> TwoOpAMButton2;
    std::unique_ptr<Label> label20;
    std::unique_ptr<Label> label21;
    std::unique_ptr<Label> label22;
    std::unique_ptr<ImageButton> algoSwitchButtonOffEx4;
    std::unique_ptr<Label> label23;
    std::unique_ptr<ImageButton> algoSwitchButtonOn3Ex3;
    std::unique_ptr<Label> label24;
    std::unique_ptr<ImageButton> TwoOpFMButton2;
    std::unique_ptr<Label> label25;
    std::unique_ptr<Label> label26;
    std::unique_ptr<GroupComponent> groupComponent7;
    std::unique_ptr<ImageButton> algoSwitchButtonOffEx5;
    std::unique_ptr<Label> label27;
    std::unique_ptr<ImageButton> algoSwitchButtonOn3Ex4;
    std::unique_ptr<Label> label28;
    std::unique_ptr<GroupComponent> groupComponent8;
    std::unique_ptr<Label> frequencyLabel9;
    std::unique_ptr<Label> label29;
    std::unique_ptr<Label> label30;
    std::unique_ptr<Label> frequencyLabel10;
    std::unique_ptr<Label> attenuationLabel5;
    std::unique_ptr<ImageButton> fmButton;
    std::unique_ptr<ImageButton> additiveButton;
    std::unique_ptr<ImageButton> bassDrumButton;
    std::unique_ptr<ImageButton> snareDrumButton;
    std::unique_ptr<ImageButton> disablePercussionButton;
    std::unique_ptr<ImageButton> tomTomButton;
    std::unique_ptr<ImageButton> cymbalButton;
    std::unique_ptr<ImageButton> hiHatButton;
    std::unique_ptr<Label> dbLabel7;
    std::unique_ptr<Label> dbLabel8;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginGui)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
