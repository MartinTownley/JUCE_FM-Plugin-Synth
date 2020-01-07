/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "Oscillator.h"

//==============================================================================
/**
*/
class JuceSynthFrameworkAudioProcessorEditor  : public AudioProcessorEditor

{
public:
    JuceSynthFrameworkAudioProcessorEditor (JuceSynthFrameworkAudioProcessor&);
    ~JuceSynthFrameworkAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
    
    
    

private:
    
    
    
    // Could make a vector of sliders..
    //Label allLabels[5];
    
    //std::vector<Slider> allSliders;
    
    
    //int numADSR{ static_cast<int>(std::size(ADSR))};
    //Label ADSRLabels[2];
    
    // oscillator class instance:
    Oscillator oscGUI;
    
    
    Slider attackSlider;
    Label allLabels[5];
    
    Slider releaseSlider;
    
    Slider harmDial;
    
    Slider modIndexDial;
    
    TextButton onOff;
    
    //ComboBox modChoice;
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    JuceSynthFrameworkAudioProcessor& processor;

public:
    //Scoped pointer is deprecated!
    //ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> sliderTree;
    
    //attackAttach
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> attackAttach;
    
    //releaseAttach
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> releaseAttach;
    
    
    // harmdialAttach
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> harmDialAttach;
    
    std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> modIndexDialAttach;
    
    // onoffAttach
    std::unique_ptr <AudioProcessorValueTreeState::ButtonAttachment> onOffAttach;
    
//    // choiceBoxAttach
//    std::unique_ptr <AudioProcessorValueTreeState::ComboBoxAttachment> modChoiceAttach;
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JuceSynthFrameworkAudioProcessorEditor)
};
