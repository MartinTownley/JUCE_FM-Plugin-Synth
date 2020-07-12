/*==============================================================================

    SynthVoice.h
    Created: 2 Jan 2020 7:20:22pm
    Author:  sierra

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthSound.h"

#include "maximilian.h"


class SynthVoice : public SynthesiserVoice
{
public:
    
    
    
    bool canPlaySound (SynthesiserSound* sound)
    {
        // Trying to cast the sound as the class SynthSound, if it's successful it'll return true.
        return dynamic_cast <SynthSound*> (sound) != nullptr;
    }
    //==========================================
    
    void setADSR (float ATTACK_ID, float DECAY_ID, float SUSTAIN_ID, float RELEASE_ID)
    {
        adsrParams.attack =  ATTACK_ID;
        adsrParams.decay =  DECAY_ID;
        adsrParams.sustain =  SUSTAIN_ID;
        adsrParams.release = RELEASE_ID;
    }
    //==========================================
    
    void setADSRSampleRate (double sampleRate)
    {
        adsr.setSampleRate (sampleRate);
    }
    
    
    //==========================================
    void setFMParams (float HARMDIAL_ID, float MODINDEX_ID)
    {
        // Harmonicity Radio
        harmRatio = (int(HARMDIAL_ID));

        // Modulation Index
        modIndex =  MODINDEX_ID;
        
    }
    
    //==========================================
    
    void setOscType (float selection)
    {
//        std::cout << *selection << std::endl;
        modulator1Type = (int(selection));
    }
    //==========================================
    
    void setIndexModAmpFreq (float INDEXMODFREQ_ID)
    {
        mod1freq = (int( INDEXMODFREQ_ID));
    }
    //==========================================
    double setOscType ()
    {

        switch (modulator1Type) {
            case 0:
                return 1;
                break;
            case 1:
                return modulator1.sinewave(mod1freq);
                break;
            case 2:
                return modulator1.square(mod1freq);
                break;
            case 3:
                return modulator1.phasor(mod1freq);
            default:
                break;
        }
    }
    
    
    
    
    //==========================================
    void startNote (int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition)
    {
        // Velocity will be a value between 0 and 1, instantiated when you press a key:
        
        //env1.trigger = 1;
        
        adsr.noteOn();
        
        level = velocity;
        
        carrierFreq = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
        
        modulator1.phaseReset(0);
        
        //std::cout << midiNoteNumber << std::endl;
        
        
    }
    
    //==========================================
    
    void stopNote (float velocity, bool allowTailOff)
    {
        //clearCurrentNote();
        //velocity = 0; //stop the note on key release
        
        // When we release a key, we want to be able to use that voice for the next key we press.
        // Allow tailOff boolean
        
        adsr.noteOff();
        
        allowTailOff = true;
        
        
        //env1.trigger = 0;
        
        if (velocity == 0)
        {clearCurrentNote();} // Unused voice can be allocated to next keypress
    }
    
    //==========================================
    
    void pitchWheelMoved (int newPitchWheelValue)
    {
        
    }
    
    //==========================================
    
    void controllerMoved (int controllerNumber, int newControllerValue)
    {
        
    }
    
    //==========================================
    
    void renderNextBlock (AudioBuffer<float> &outputBuffer, int startSample, int numSamples)
    {
            // This gets called in the process block of PluginProcessor
        // This is where we'll put our audio callback.
        
        // Set arguments for envelope:
      
        mod1amp = 19;
        //mod1freq = 2;
        adsr.setParameters (adsrParams);
        
        for (int sample = 0; sample < numSamples; ++sample)
        {
            
            mod0freq = harmRatio * carrierFreq;
            //modIndex = mod1freq * mod1amp;
            mod0amp = mod0freq * modIndex;
            
//           //frequency modulation happens below
            double theWave = carrier.sinewave(carrierFreq
                                              + (modulator0.sinewave(mod0freq)
                                                 * (mod0amp * setOscType() )));
                                              
           
            
            double theSound = adsr.getNextSample() * theWave;
            
            
            
            // Iterate the channels
            for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
            {
                outputBuffer.addSample(channel, startSample, (theSound * 0.2)); //args: (destChannel, destSample, valueToAdd)
            }
            // Advance startSample after channel iterator:
            ++startSample;
        }
        
        
    }
    
    //==========================================
    //ADSR Getter:
    ADSR::Parameters& getADSRParams() { return adsrParams; }
    
private:
    
    ADSR adsr;
    ADSR::Parameters adsrParams;
    
    double level;
    double carrierFreq;
    double mod0freq;
    double mod0amp;
    double modIndex;
    double mod1amp;
    double mod1freq;
    int harmRatio;
    
    bool isModulator;
    //double mod1wave;
    
    int modulator1Type;
    
    
    
    //Create an oscillator:
    maxiOsc carrier, modulator0, modulator1;
    
};
