/*
  ==============================================================================

    SynthVoice.cpp
    Created: 28 Sep 2021 8:42:17pm
    Author:  screamLab

  ==============================================================================
*/

#include "SynthVoice.h"
#include <math.h>


bool SynthVoice::canPlaySound(juce::SynthesiserSound* sound)
{
	return dynamic_cast<SynthSound*>(sound) != nullptr;
}

void SynthVoice::startNote(int midiNoteNumber, float velocity, juce::SynthesiserSound* sound, int currentPitchWheelPosition)
{
	noteMidiNumber = midiNoteNumber;
	frequency = juce::MidiMessage::getMidiNoteInHertz(midiNoteNumber);
	currentAngle = 0.f;
	angleIncrement = frequency / getSampleRate() * juce::MathConstants<float>::twoPi;
	tailOff = 0.0;
}

void SynthVoice::stopNote(float velocity, bool allowTailOff)
{
	if (allowTailOff)
	{
		if (tailOff == 0.0)
			tailOff = 1.0;
	}
	else
	{
		clearCurrentNote();
		level = 0;
		currentAngle = 0.f;
	}
}

void SynthVoice::pitchWheelMoved(int newPitchWheelValue)
{
	// handle pitch wheel moved midi event
}

void SynthVoice::controllerMoved(int controllerNumber, int newControllerValue)
{
	// handle midi control change
}

void SynthVoice::renderNextBlock(juce::AudioBuffer <float> &outputBuffer, int startSample, int numSamples)
{
	if (tailOff > 0.0)
	{
		for (int i = startSample; i < (startSample + numSamples); i++)
		{
			/*
			//sine wave
			float value = std::sin(currentAngle) * level * tailOff;

			outputBuffer.addSample(0, i, value);
			outputBuffer.addSample(1, i, value);
			*/

			/*
			//square wave
			float value = (std::sin(currentAngle) >= 0 ? 1 : -1) ;
			value = value * level * tailOff;

			outputBuffer.addSample(0, i, value);
			outputBuffer.addSample(1, i, value);
			*/

			/*
			//sawtooth wave
			if (currentAngle > juce::MathConstants<float>::twoPi)
			{
				currentAngle = currentAngle - juce::MathConstants<float>::twoPi;
			}
			float value = (1 / juce::MathConstants<float>::pi * currentAngle - 1) * level * tailOff;

			outputBuffer.addSample(0, i, value);
			outputBuffer.addSample(1, i, value);
			*/
			
			//triangle wave
			if (currentAngle > juce::MathConstants<float>::twoPi)
			{
				currentAngle = currentAngle - juce::MathConstants<float>::twoPi;
			}
			if (currentAngle < 1 / 2 * juce::MathConstants<float>::pi)
			{
				float value = 2 / juce::MathConstants<float>::pi * currentAngle * level * tailOff;
				outputBuffer.addSample(0, i, value);
				outputBuffer.addSample(1, i, value);
			}
			else if (1 / 2 * juce::MathConstants<float>::pi < currentAngle < 3 / 2 * juce::MathConstants<float>::pi) {
				float value = (-2 / juce::MathConstants<float>::pi * currentAngle + 2) * level * tailOff;
				outputBuffer.addSample(0, i, value);
				outputBuffer.addSample(1, i, value);
			}
			else if (currentAngle > 3 / 2 * juce::MathConstants<float>::pi) {
				float value = (2 / juce::MathConstants<float>::pi * currentAngle - 4) * level * tailOff;
				outputBuffer.addSample(0, i, value);
				outputBuffer.addSample(1, i, value);
			}

			currentAngle += angleIncrement;
			tailOff *= 0.99;

			\

			if (tailOff <= 0.05)
			{
				clearCurrentNote();
				angleIncrement = 0.0;
				level = 0.0;
				break;
			}

		}

	}
	else
	{
		for (int i = startSample; i < (startSample + numSamples); i++)
		{
			/*
			//sine wave
			float value = std::sin(currentAngle) * level;

			outputBuffer.addSample(0, i, value);
			outputBuffer.addSample(1, i, value);
			*/
			
			/*
			//square wave
			float value = ((std::sin(currentAngle) >= 0) ? 1 : -1);
		    value = value * level;

			outputBuffer.addSample(0, i, value);
			outputBuffer.addSample(1, i, value);
			*/

			/*
			//sawtooth wave
			if (currentAngle > juce::MathConstants<float>::twoPi)
			{
				currentAngle = currentAngle - juce::MathConstants<float>::twoPi;
			}
			float value = (1 / juce::MathConstants<float>::pi * currentAngle - 1) * level ;

			outputBuffer.addSample(0, i, value);
			outputBuffer.addSample(1, i, value);
			*/

			//triangle wave
			if (currentAngle > juce::MathConstants<float>::twoPi)
			{
				currentAngle = currentAngle - juce::MathConstants<float>::twoPi;
			}
			if (currentAngle < 1 / 2 * juce::MathConstants<float>::pi)
			{
				float value = 2 / juce::MathConstants<float>::pi * currentAngle * level;
				outputBuffer.addSample(0, i, value);
				outputBuffer.addSample(1, i, value);
			}
			else if (1 / 2 * juce::MathConstants<float>::pi < currentAngle < 3 / 2 * juce::MathConstants<float>::pi) {
				float value = (-2 / juce::MathConstants<float>::pi * currentAngle + 2) * level ;
				outputBuffer.addSample(0, i, value);
				outputBuffer.addSample(1, i, value);
			}
			else if (currentAngle > 3 / 2 * juce::MathConstants<float>::pi) {
				float value = (2 / juce::MathConstants<float>::pi * currentAngle - 4) * level;
				outputBuffer.addSample(0, i, value);
				outputBuffer.addSample(1, i, value);
			}

			currentAngle += angleIncrement;
		}
	}
}

void SynthVoice::setLevel(float newLevel)
{
	level = newLevel;
}

/*
void SynthVoice::logger(std::string msg)
{
	std::string filePath = "C:/Users/s1976/source/squ_log.txt";
	std::ofstream ofs(filePath.c_str(), std::ios_base::out | std::ios_base::app);
	ofs << msg << '\n';
	ofs.close();
}
*/