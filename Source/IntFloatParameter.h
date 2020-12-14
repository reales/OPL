#pragma once
#include "FloatParameter.h"
class IntFloatParameter :
	public FloatParameter
{
public:
    IntFloatParameter(juce::String name, int min, int max);
	~IntFloatParameter(void);
    juce::String getParameterText(void);
	int getParameterValue(void);
	void setParameterValue(int i);
private:
	int min;
	int max;
};

