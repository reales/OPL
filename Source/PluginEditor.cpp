/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.7

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

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
    //[/UserPreSize]

    setSize (860, 580);


    //[Constructor] You can add your own custom stuff here..
    int w,h;
    w = pluginSettings.getUserSettings()->getIntValue("Width");
    if(w==0)
        w=860;
    h = pluginSettings.getUserSettings()->getIntValue("Height");
    if(h==0)
        h=580;
    setSize(w,h);
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

