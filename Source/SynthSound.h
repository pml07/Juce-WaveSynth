/*
  ==============================================================================

    SynthSound.h
    Created: 28 Sep 2021 8:42:03pm
    Author:  screamLab

  ==============================================================================
*/

#pragma once
class SynthSound : public juce::SynthesiserSound
{

public:
	bool appliesToNote(int midiNoteNumber) override
	{
		return true;
	}

	bool appliesToChannel(int midiNoteNumber) override
	{
		return true;
	}
};