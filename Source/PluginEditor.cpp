/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 6.0.7

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
PluginEditor::PluginEditor (AdlibBlasterAudioProcessor* ownerFilter)
    : AudioProcessorEditor (ownerFilter)
{
    //[Constructor_pre] You can add your own custom stuff here..
    PropertiesFile::Options options;
    options.applicationName = ProjectInfo::projectName;
    options.osxLibrarySubFolder = "Application Support";
    options.filenameSuffix      = ".settings";
    options.storageFormat = PropertiesFile::storeAsXML;
    #if JUCE_LINUX
    options.folderName          = "~/.config";
    #else
    options.folderName          = "";
    #endif
    pluginSettings.setStorageParameters (options);

    //[/Constructor_pre]

    comp.reset (new PluginGui (ownerFilter));
    addAndMakeVisible (comp.get());
    comp->setName ("Main GUI");

    comp->setBounds (0, 0, 860, 580);


    //[UserPreSize]
    setResizable(true, true);
    
    // Get the screen height and set the max height to screen height minus some pixels
    auto totalHeight = juce::Desktop::getInstance().getDisplays().getPrimaryDisplay()->totalArea.getHeight();
    int maxHeight = totalHeight - 100; // Subtracting 100 pixels for operating space
    int maxWidth = static_cast<int>(maxHeight * 1.4828); // Maintaining aspect ratio
    
    setResizeLimits(860, 580, maxWidth, maxHeight); // Minimum size 860x580, maximum size based on screen height

    // Set initial size with aspect ratio maintained
    int w = 1438, h = 970;
    int userWidth = pluginSettings.getUserSettings()->getIntValue("Width");
    int userHeight = pluginSettings.getUserSettings()->getIntValue("Height");
    if (userWidth != 0 && userHeight != 0) {
        w = userWidth;
        h = userHeight;
    }
    setSize(w, h);
    //[UserPreSize]

    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

PluginEditor::~PluginEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    comp = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    pluginSettings.getUserSettings()->setValue("Width", getWidth());
    pluginSettings.getUserSettings()->setValue("Height", getHeight());
    pluginSettings.saveIfNeeded();
    //[/Destructor]
}

//==============================================================================
void PluginEditor::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::black);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void PluginEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    Path path; // the only reason we use a Path is that it implements the handy getTransformToScaleToFit()
    path.addRectangle(0, 0, comp->getWidth(), comp->getHeight());
    auto transform = path.getTransformToScaleToFit(getLocalBounds().toFloat(), true, Justification::centred);

    comp->setTransform(transform);
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    // Lock the aspect ratio
    int width = getWidth();
    int height = static_cast<int>(width / 1.4828);
    if (height > getHeight()) {
        height = getHeight();
        width = static_cast<int>(height * 1.4828);
    }
    setSize(width, height);
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="PluginEditor" componentName=""
                 parentClasses="public AudioProcessorEditor" constructorParams="AdlibBlasterAudioProcessor* ownerFilter"
                 variableInitialisers=" AudioProcessorEditor (ownerFilter)" snapPixels="8"
                 snapActive="1" snapShown="1" overlayOpacity="0.330" fixedSize="0"
                 initialWidth="860" initialHeight="580">
  <BACKGROUND backgroundColour="ff000000"/>
  <GENERICCOMPONENT name="Main GUI" id="63d69ee5cf07179d" memberName="comp" virtualName=""
                    explicitFocusOrder="0" pos="0 0 860 580" class="PluginGui" params="ownerFilter"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

