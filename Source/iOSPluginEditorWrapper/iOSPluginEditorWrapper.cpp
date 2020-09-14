/*
  ==============================================================================

    iOSPluginEditorWrapper.cpp
    Created: 2 Sep 2020 8:09:38pm
    Author:  Javier Andoni Aizpuru Rodríguez

  ==============================================================================
*/

#include "iOSPluginEditorWrapper.h"

iOSPluginEditorWrapper::iOSPluginEditorWrapper(juce::AudioProcessor& p, juce::AudioProcessorEditor* e) :
AudioProcessorEditor(p)
{
    viewport = std::make_unique<Viewport>();
    
    disableViewportDragOnSliderDrag(*e);
        
    viewport->setViewedComponent(e, true);
    
    scrollbarManager = std::make_unique<ScrollbarManager>(*viewport.get());
    
    addAndMakeVisible(viewport.get());
    
    initialW = e->getWidth();
    
    previousW = initialW;
    
    initialH = e->getHeight();
    
    ratio = initialW / initialH;
    
    if (p.wrapperType == juce::AudioProcessor::wrapperType_Standalone || hostType.isGarageBand())
        isStandaloneWrapper = true;
        
    auto resizable = !isStandaloneWrapper;
    setResizable(resizable, resizable);
    
    e->setResizable(false, false);
    
    setSize(initialW, initialH);
}

iOSPluginEditorWrapper::~iOSPluginEditorWrapper()
{
    scrollbarManager.reset();
    viewport.reset();
}

void iOSPluginEditorWrapper::paint (juce::Graphics& g)
{
    g.fillAll(Colours::black);
};
void iOSPluginEditorWrapper::resized()
{
    
    if (hostType.isGarageBand())
    {
        auto parent = getParentComponent();
        auto parentWidth = parent->getWidth();
        
        if (parentWidth != getWidth())
            setSize(parentWidth, getHeight());
    };
    
    auto localBounds = getLocalBounds();
    
    viewport->setBounds(localBounds);
    
    auto editorWidth = localBounds.getWidth();
    
    auto calculateHeight = [this, &editorWidth] ()
    {
        return ceil(static_cast<float>(editorWidth) / ratio);
    };
    
    auto editor = viewport->getViewedComponent();
    auto factor = editorWidth / initialW;
    auto t = juce::AffineTransform::scale(factor);
    editor->setTransform(t);
    
    //Set correct scrollbar view position
    
    auto editorHeight = calculateHeight();
    auto scrollbarFactor = editorWidth / previousW;
    auto t2 = juce::AffineTransform::scale(scrollbarFactor);
    auto viewportPosition = viewport->getViewPosition();
    viewportPosition.applyTransform(t2);
    
    auto containerHeight = localBounds.getHeight();
    
    if (editorHeight > containerHeight)
    {
        auto diff = editorHeight - containerHeight;
        auto gapProportion = editorHeight * 0.05f;
        
        if (diff < gapProportion)
            viewportPosition = juce::Point<int>();
    }
    
    viewport->setViewPosition(viewportPosition);
    
    //Adding scrollbar manager constrainers
    auto constraintWidth = initialScrollBarWidth * factor;
    
    scrollbarManager->removeAllConstraints();
    scrollbarManager->addConstraint(0, 0, constraintWidth, editorHeight);
    scrollbarManager->addConstraint(editorWidth - constraintWidth, 0, constraintWidth, editorHeight);
        
    if (isStandaloneWrapper)
    {
        //Center vertically if editor doesn't cover whole screen area
        auto height = getHeight();
        
        if (editorHeight < height)
            viewport->setTopLeftPosition(0, (height - editorHeight) / 2);
    }
    else
    {
        //Setting window resize limits
        auto minW = ceil(initialW * 0.25f);
        auto minH = ceil(initialH * 0.25f);
        auto maxW = initialW * 4;
        
        if (editorHeight < minH)
            editorHeight = minH;
        
        setResizeLimits(minW, minH, maxW, editorHeight);
    }
    
    previousW = editorWidth;
};

void iOSPluginEditorWrapper::setInitialScrollbarWidth(int width)
{
    initialScrollBarWidth = width;
}

void iOSPluginEditorWrapper::disableViewportDragOnSliderDrag(juce::Component& component)
{
    auto sliderList = std::vector<Component*>();
    
    std::function<void(Component&, std::vector<Component*>&)> addSlidersToVector;
    
    addSlidersToVector = [&addSlidersToVector] (Component& c, std::vector<Component*>& v)
    {
        if (auto slider = dynamic_cast<juce::Slider*>(&c))
            v.push_back(slider);
        else for (auto child : c.getChildren())
            addSlidersToVector(*child, v);
    };
    
    addSlidersToVector(component, sliderList);

    for (auto slider : sliderList)
        slider->setViewportIgnoreDragFlag(true);
    
}

AudioProcessorEditor* iOSPluginEditorWrapper::getEditor()
{
    return static_cast<AudioProcessorEditor*>(viewport->getViewedComponent());
}
