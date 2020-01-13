/*
  ==============================================================================

    Envelope.cpp
    Created: 7 Jan 2020 5:28:28pm
    Author:  sierra

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Envelope.h"

//==============================================================================
Envelope::Envelope(JuceSynthFrameworkAudioProcessor& p) :
processor(p)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    //attack slider
    attackSlider.setSliderStyle (Slider::SliderStyle::LinearVertical);
    attackSlider.setTextBoxStyle (Slider::TextEntryBoxPosition::TextBoxBelow, true, 50, 15);
    addAndMakeVisible(&attackSlider);
    attackAttach = std::make_unique <AudioProcessorValueTreeState::SliderAttachment> (processor.treeState, ATTACK_ID, attackSlider);
    
    //decay slider
    decaySlider.setSliderStyle (Slider::SliderStyle::LinearVertical);
    decaySlider.setTextBoxStyle (Slider::TextEntryBoxPosition::TextBoxBelow, true, 50, 15);
    addAndMakeVisible(&decaySlider);
    decayAttach = std::make_unique <AudioProcessorValueTreeState::SliderAttachment> (processor.treeState, DECAY_ID, decaySlider);
    
    
    
    //sustain slider
    sustainSlider.setSliderStyle (Slider::SliderStyle::LinearVertical);
    sustainSlider.setTextBoxStyle (Slider::TextEntryBoxPosition::TextBoxBelow, true, 50, 15);
    addAndMakeVisible(&sustainSlider);
    decayAttach = std::make_unique <AudioProcessorValueTreeState::SliderAttachment> (processor.treeState, SUSTAIN_ID, sustainSlider);
    
    
    
    
    //release slider
    releaseSlider.setSliderStyle (Slider::SliderStyle::LinearVertical);
    releaseSlider.setTextBoxStyle (Slider::TextEntryBoxPosition::TextBoxBelow, true, 50, 15);
    addAndMakeVisible(&releaseSlider);
    releaseAttach = std::make_unique <AudioProcessorValueTreeState::SliderAttachment> (processor.treeState, RELEASE_ID, releaseSlider);
    

}

Envelope::~Envelope()
{
}

void Envelope::paint (Graphics& g)
{
    g.fillAll(Colours::purple);
    
       // clear the background
    
    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component
    
    g.setColour (Colours::white);
    g.setFont (14.0f);
    //g.drawText ("FMod", getLocalBounds(),
    //Justification::centred, true);
    g.drawText("Envelope", 10, 10, 200, 10, Justification::centred);
    // draw some placeholder text
    
}

void Envelope::resized()
{
    auto bounds = getLocalBounds();
    const int componentSize { 100 };
    
    //attackSlider set bounds
    attackSlider.setBounds (bounds.removeFromLeft(100).withSizeKeepingCentre(componentSize, componentSize));
    
    //decay slider set bounds
    decaySlider.setBounds (bounds.removeFromLeft(100).withSizeKeepingCentre(componentSize, componentSize));
    
    //sustain slider set bounds
    sustainSlider.setBounds (bounds.removeFromLeft(100).withSizeKeepingCentre(componentSize, componentSize));
    
    
    
    //releaseSlider set bounds
    releaseSlider.setBounds (bounds.removeFromLeft(100).withSizeKeepingCentre(componentSize, componentSize));

}
