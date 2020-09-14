/*
  ==============================================================================

    iOSPluginEditorWrapper.h
    Created: 2 Sep 2020 6:31:15pm
    Author:  Javier Andoni Aizpuru Rodríguez

  ==============================================================================
*/

#pragma once

#include "JuceHeader.h"
#include "ScrollbarManager.h"

class iOSPluginEditorWrapper :
public juce::AudioProcessorEditor
{
public:

    iOSPluginEditorWrapper(juce::AudioProcessor& p, juce::AudioProcessorEditor* e);
    
    ~iOSPluginEditorWrapper();
    
    void paint (juce::Graphics& g) override;
    
    void resized() override;
    
    void setInitialScrollbarWidth(int);
    
    AudioProcessorEditor* getEditor();
    
private:
    
    void disableViewportDragOnSliderDrag(juce::Component& c);
    
    double initialW, initialH, ratio, previousW;
    
    int initialScrollBarWidth { 20 };
    
    bool isStandaloneWrapper { false };
    
    std::unique_ptr<juce::Viewport> viewport { nullptr };
    
    std::unique_ptr<ScrollbarManager> scrollbarManager { nullptr };
    
    juce::PluginHostType hostType;

};
