/*
  ==============================================================================

    SynthVoice.h
    Created: 28 Sep 2021 8:42:17pm
    Author:  screamLab

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "SynthSound.h"
#include <fstream>
#include <iostream>
#include <string>


class SynthVoice : public juce::SynthesiserVoice
{
public:
	bool canPlaySound(juce::SynthesiserSound* sound) override;

	void startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition) override;

	void stopNote(float velocity, bool allowTailOff) override;

	void pitchWheelMoved(int newPitchWheelValue) override;

	void controllerMoved(int controllerNumber, int newControllerValue) override;

	void renderNextBlock(juce::AudioBuffer <float> &outputBuffer, int startSample, int numSamples) override;

	void setLevel(float newLevel);
	
	void logger(std::string msg);

private:
	float level;
	float frequency;
	int noteMidiNumber;
	float currentAngle;
	float angleIncrement;
	float tailOff;
};
