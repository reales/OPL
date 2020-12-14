/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 6.0.5

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <array>
#include "JuceHeader.h"
#include "PluginProcessor.h"
#include "OPLLookAndFeel.h"
#include "ChannelButtonLookAndFeel.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
	This is a GUI for the OPL2 VST plugin, created in Juce.
                                                                    //[/Comments]
*/
class PluginGui  : public Component,
                   public FileDragAndDropTarget,
                   public DragAndDropContainer,
                   public Timer,
                   public juce::ComboBox::Listener,
                   public juce::Slider::Listener,
                   public juce::Button::Listener
{
public:
    //==============================================================================
    PluginGui (AdlibBlasterAudioProcessor* ownerFilter);
    ~PluginGui() override;

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
    bool showLoadMenu();
    bool loadBrowserFile();
    void loadPreNextFile(bool pre = true);

    void syncGUI();

    void sliderDragStarted (Slider* sliderThatWasMoved) override;
    void sliderDragEnded (Slider* sliderThatWasMoved) override;

    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void comboBoxChanged (juce::ComboBox* comboBoxThatHasChanged) override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;

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
    static const char* gui_svg;
    static const int gui_svgSize;


private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    bool updateFromHost = true;

    void loadandUpdateInstrument(String path);
class OPLComboBoxLookAndFeelMethods:
    public OPLLookAndFeel
{
    virtual PopupMenu::Options getOptionsForComboBoxPopupMenu (ComboBox& comBox, Label& label) override{
            PopupMenu::Options options = OPLLookAndFeel::getOptionsForComboBoxPopupMenu(comBox, label);
#if JUCE_IOS
        if (PluginHostType::getPluginLoadedAs() == AudioProcessor::wrapperType_AudioUnitv3)
            {
                if (options.getTargetComponent() != nullptr)
                return options.withParentComponent(options.getTargetComponent()->getTopLevelComponent());
            }
#endif
return options;
    };
};

    std::unique_ptr<OPLComboBoxLookAndFeelMethods> oplComboBoxLookAndFeel;

	static const uint32 COLOUR_MID = 0xff007f00;
	static const uint32 COLOUR_RECORDING = 0xffff0000;
	AdlibBlasterAudioProcessor* processor;
	std::array<ScopedPointer<TextButton>, Hiopl::CHANNELS> channels;
	TooltipWindow tooltipWindow;
    PopupMenu menuLoad;
    Array<File> allSbiFiles;

#if!JUCE_IOS
    File instrumentLoadDirectory = File::getSpecialLocation(File::userDocumentsDirectory).getChildFile("discoDSP").getChildFile("OPL"); // File();
    File instrumentSaveDirectory = File::getSpecialLocation(File::userDocumentsDirectory).getChildFile("discoDSP").getChildFile("OPL"); // File();
#endif
#if JUCE_IOS
        File instrumentLoadDirectory = File::getSpecialLocation (File::invokedExecutableFile).getParentDirectory().getChildFile("sbi"); // File();
        File instrumentSaveDirectory = File::getSpecialLocation(File::userDocumentsDirectory); // File();

#endif

    std::unique_ptr<OPLLookAndFeel> oplLookAndFeel;
    std::unique_ptr<ChannelButtonLookAndFeel> channelButtonLookAndFeel;

    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::GroupComponent> groupComponent2;
    std::unique_ptr<juce::GroupComponent> groupComponent4;
    std::unique_ptr<juce::GroupComponent> groupComponent11;
    std::unique_ptr<juce::GroupComponent> groupComponent10;
    std::unique_ptr<juce::GroupComponent> groupComponent9;
    std::unique_ptr<juce::GroupComponent> groupComponent;
    std::unique_ptr<juce::ComboBox> frequencyComboBox;
    std::unique_ptr<juce::Label> frequencyLabel;
    std::unique_ptr<juce::Slider> aSlider;
    std::unique_ptr<juce::Label> aLabel;
    std::unique_ptr<juce::Slider> dSlider;
    std::unique_ptr<juce::Label> dLabel;
    std::unique_ptr<juce::Slider> sSlider;
    std::unique_ptr<juce::Label> dLabel2;
    std::unique_ptr<juce::Slider> rSlider;
    std::unique_ptr<juce::Label> rLabel;
    std::unique_ptr<juce::Slider> attenuationSlider;
    std::unique_ptr<juce::Label> attenuationLabel;
    std::unique_ptr<juce::Label> dbLabel;
    std::unique_ptr<juce::ImageButton> sineImageButton;
    std::unique_ptr<juce::ImageButton> halfsineImageButton;
    std::unique_ptr<juce::ImageButton> abssineImageButton;
    std::unique_ptr<juce::ImageButton> quartersineImageButton;
    std::unique_ptr<juce::Label> waveLabel;
    std::unique_ptr<juce::ToggleButton> tremoloButton;
    std::unique_ptr<juce::ToggleButton> vibratoButton;
    std::unique_ptr<juce::ToggleButton> sustainButton;
    std::unique_ptr<juce::ToggleButton> keyscaleEnvButton;
    std::unique_ptr<juce::Label> dbLabel2;
    std::unique_ptr<juce::ComboBox> frequencyComboBox2;
    std::unique_ptr<juce::Label> frequencyLabel3;
    std::unique_ptr<juce::Slider> aSlider2;
    std::unique_ptr<juce::Label> aLabel2;
    std::unique_ptr<juce::Slider> dSlider2;
    std::unique_ptr<juce::Label> dLabel3;
    std::unique_ptr<juce::Slider> sSlider2;
    std::unique_ptr<juce::Label> dLabel4;
    std::unique_ptr<juce::Slider> rSlider2;
    std::unique_ptr<juce::Label> rLabel2;
    std::unique_ptr<juce::Slider> attenuationSlider2;
    std::unique_ptr<juce::Label> attenuationLabel2;
    std::unique_ptr<juce::Label> dbLabel3;
    std::unique_ptr<juce::ImageButton> sineImageButton2;
    std::unique_ptr<juce::ImageButton> halfsineImageButton2;
    std::unique_ptr<juce::ImageButton> abssineImageButton2;
    std::unique_ptr<juce::ImageButton> quartersineImageButton2;
    std::unique_ptr<juce::Label> waveLabel2;
    std::unique_ptr<juce::ToggleButton> tremoloButton2;
    std::unique_ptr<juce::ToggleButton> vibratoButton2;
    std::unique_ptr<juce::ToggleButton> sustainButton2;
    std::unique_ptr<juce::ToggleButton> keyscaleEnvButton2;
    std::unique_ptr<juce::Label> frequencyLabel4;
    std::unique_ptr<juce::GroupComponent> groupComponent3;
    std::unique_ptr<juce::Slider> tremoloSlider;
    std::unique_ptr<juce::Label> frequencyLabel5;
    std::unique_ptr<juce::Label> dbLabel5;
    std::unique_ptr<juce::Slider> vibratoSlider;
    std::unique_ptr<juce::Label> frequencyLabel6;
    std::unique_ptr<juce::Label> dbLabel6;
    std::unique_ptr<juce::Slider> feedbackSlider;
    std::unique_ptr<juce::Label> frequencyLabel7;
    std::unique_ptr<juce::ComboBox> velocityComboBox;
    std::unique_ptr<juce::ComboBox> velocityComboBox2;
    std::unique_ptr<juce::Label> attenuationLabel4;
    std::unique_ptr<juce::ImageButton> alternatingsineImageButton;
    std::unique_ptr<juce::ImageButton> camelsineImageButton;
    std::unique_ptr<juce::ImageButton> squareImageButton;
    std::unique_ptr<juce::ImageButton> logsawImageButton;
    std::unique_ptr<juce::ImageButton> alternatingsineImageButton2;
    std::unique_ptr<juce::ImageButton> camelsineImageButton2;
    std::unique_ptr<juce::ImageButton> squareImageButton2;
    std::unique_ptr<juce::ImageButton> logsawImageButton2;
    std::unique_ptr<juce::Label> dbLabel4;
    std::unique_ptr<juce::ComboBox> keyscaleAttenuationComboBox2;
    std::unique_ptr<juce::ComboBox> keyscaleAttenuationComboBox;
    std::unique_ptr<juce::GroupComponent> groupComponent5;
    std::unique_ptr<juce::Slider> emulatorSlider;
    std::unique_ptr<juce::Label> emulatorLabel;
    std::unique_ptr<juce::Label> emulatorLabel2;
    std::unique_ptr<juce::ToggleButton> recordButton;
    std::unique_ptr<juce::TextButton> exportButton;
    std::unique_ptr<juce::TextButton> loadButton;
    std::unique_ptr<juce::Label> versionLabel;
    std::unique_ptr<juce::ImageButton> ToggleButtonOffExample;
    std::unique_ptr<juce::ImageButton> ToggleButtonOnExample;
    std::unique_ptr<juce::Label> label;
    std::unique_ptr<juce::Label> label2;
    std::unique_ptr<juce::ImageButton> LineBorderButton1C;
    std::unique_ptr<juce::ImageButton> LineBorderButton1A;
    std::unique_ptr<juce::ImageButton> LineBorderButton1B;
    std::unique_ptr<juce::Label> label3;
    std::unique_ptr<juce::ImageButton> LineBorderButton1C2;
    std::unique_ptr<juce::ImageButton> LineBorderButton1A2;
    std::unique_ptr<juce::ImageButton> LineBorderButton1B2;
    std::unique_ptr<juce::ImageButton> LineBorderButton1C3;
    std::unique_ptr<juce::ImageButton> LineBorderButton1B3;
    std::unique_ptr<juce::ImageButton> algoSwitchButtonOffEx1;
    std::unique_ptr<juce::ImageButton> algoSwitchButtonOffEx2;
    std::unique_ptr<juce::ImageButton> algoSwitchButtonOnEx1;
    std::unique_ptr<juce::ImageButton> algoSwitchButtonOnEx2;
    std::unique_ptr<juce::Label> label4;
    std::unique_ptr<juce::Label> label5;
    std::unique_ptr<juce::Label> label6;
    std::unique_ptr<juce::Label> label7;
    std::unique_ptr<juce::Label> label8;
    std::unique_ptr<juce::ImageButton> algoSwitchButtonOn2Ex1;
    std::unique_ptr<juce::ImageButton> algoSwitchButtonOn2Ex2;
    std::unique_ptr<juce::Label> label9;
    std::unique_ptr<juce::Label> label10;
    std::unique_ptr<juce::ImageButton> algoSwitchButtonOn3Ex1;
    std::unique_ptr<juce::ImageButton> algoSwitchButtonOn3Ex2;
    std::unique_ptr<juce::Label> label11;
    std::unique_ptr<juce::Label> label12;
    std::unique_ptr<juce::ImageButton> TwoOpAMButton;
    std::unique_ptr<juce::ImageButton> TwoOpFMButton;
    std::unique_ptr<juce::Label> label13;
    std::unique_ptr<juce::Label> label14;
    std::unique_ptr<juce::Label> label15;
    std::unique_ptr<juce::Label> label16;
    std::unique_ptr<juce::Label> label17;
    std::unique_ptr<juce::GroupComponent> groupComponent6;
    std::unique_ptr<juce::ImageButton> algoSwitchButtonOnEx3;
    std::unique_ptr<juce::Label> label18;
    std::unique_ptr<juce::ImageButton> algoSwitchButtonOffEx3;
    std::unique_ptr<juce::Label> label19;
    std::unique_ptr<juce::ImageButton> TwoOpAMButton2;
    std::unique_ptr<juce::Label> label20;
    std::unique_ptr<juce::Label> label21;
    std::unique_ptr<juce::Label> label22;
    std::unique_ptr<juce::ImageButton> algoSwitchButtonOffEx4;
    std::unique_ptr<juce::Label> label23;
    std::unique_ptr<juce::ImageButton> algoSwitchButtonOn3Ex3;
    std::unique_ptr<juce::Label> label24;
    std::unique_ptr<juce::ImageButton> TwoOpFMButton2;
    std::unique_ptr<juce::Label> label25;
    std::unique_ptr<juce::Label> label26;
    std::unique_ptr<juce::GroupComponent> groupComponent7;
    std::unique_ptr<juce::ImageButton> algoSwitchButtonOffEx5;
    std::unique_ptr<juce::Label> label27;
    std::unique_ptr<juce::ImageButton> algoSwitchButtonOn3Ex4;
    std::unique_ptr<juce::Label> label28;
    std::unique_ptr<juce::GroupComponent> groupComponent8;
    std::unique_ptr<juce::Label> frequencyLabel9;
    std::unique_ptr<juce::Label> label29;
    std::unique_ptr<juce::Label> label30;
    std::unique_ptr<juce::Label> frequencyLabel10;
    std::unique_ptr<juce::Label> attenuationLabel5;
    std::unique_ptr<juce::ImageButton> fmButton;
    std::unique_ptr<juce::ImageButton> additiveButton;
    std::unique_ptr<juce::ImageButton> bassDrumButton;
    std::unique_ptr<juce::ImageButton> snareDrumButton;
    std::unique_ptr<juce::ImageButton> disablePercussionButton;
    std::unique_ptr<juce::ImageButton> tomTomButton;
    std::unique_ptr<juce::ImageButton> cymbalButton;
    std::unique_ptr<juce::ImageButton> hiHatButton;
    std::unique_ptr<juce::Label> dbLabel7;
    std::unique_ptr<juce::Label> dbLabel8;
    std::unique_ptr<juce::TextButton> previousButton;
    std::unique_ptr<juce::TextButton> nextButton;
    std::unique_ptr<juce::Drawable> drawable1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PluginGui)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

