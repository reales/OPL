#include "IntFloatParameter.h"


IntFloatParameter::IntFloatParameter(juce::String name, int min, int max)
:FloatParameter(name)
{
	this->min = min;
	this->max = max;
}

IntFloatParameter::~IntFloatParameter(void)
{
}

int IntFloatParameter::getParameterValue(void)
{
	int range = max - min;
	int i = (int)(this->value * range) + min;
	if (i > range)
		i = range;
	return i;
}

void IntFloatParameter::setParameterValue(int i)
{
	this->value = (float)(i - min)/(float)(max - min);
	if (this->value < 0.0f)
		this->value = 0.0f;
	else if (this->value > 1.0f)
		this->value = 1.0f;
}

juce::String IntFloatParameter::getParameterText(void)
{
	return juce::String(this->getParameterValue());
}
