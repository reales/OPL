#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class FloatParameter
{
public:
    FloatParameter(juce::String name);
	virtual ~FloatParameter(void);
	float getParameter(void);
	void setParameter(float value);
    juce::String getName(void);
    virtual juce::String getParameterText(void) = 0;
protected:	
	float value;
private:
    juce::String name;
};
