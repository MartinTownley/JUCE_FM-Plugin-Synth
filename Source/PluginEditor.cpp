/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
JuceSynthFrameworkAudioProcessorEditor::JuceSynthFrameworkAudioProcessorEditor (JuceSynthFrameworkAudioProcessor& p)
: AudioProcessorEditor (&p), processor (p)
{
    setSize(1000,300);
    
     //textbutton Bool
    onOff.setColour (TextButton::buttonColourId, Colours::purple);
    onOff.setColour (TextButton::buttonOnColourId, Colours::yellow);
    onOff.setClickingTogglesState (true);
    onOff.onClick = [this] () {};
    addAndMakeVisible(onOff);

    //attack slider
    attackSlider.setSliderStyle (Slider::SliderStyle::LinearVertical);
    attackSlider.setTextBoxStyle (Slider::TextEntryBoxPosition::TextBoxBelow, true, 50, 15);

    addAndMakeVisible(&attackSlider);
    

    attackAttach = std::make_unique <AudioProcessorValueTreeState::SliderAttachment> (processor.treeState, ATTACK_ID, attackSlider);

    //release slider
    releaseSlider.setSliderStyle (Slider::SliderStyle::LinearVertical);
    releaseSlider.setTextBoxStyle (Slider::TextEntryBoxPosition::TextBoxBelow, true, 50, 15);
    addAndMakeVisible(&releaseSlider);
    releaseAttach = std::make_unique <AudioProcessorValueTreeState::SliderAttachment> (processor.treeState, RELEASE_ID, releaseSlider);

    
    //harmdial slider
    harmDial.setSliderStyle (Slider::SliderStyle::RotaryVerticalDrag);
    harmDial.setTextBoxStyle (Slider::TextEntryBoxPosition::TextBoxBelow, true, 50, 15);
    addAndMakeVisible(&harmDial);
    harmDialAttach = std::make_unique <AudioProcessorValueTreeState::SliderAttachment> (processor.treeState, HARMDIAL_ID, harmDial);
    
    //modIndexDial slider
    modIndexDial.setSliderStyle (Slider::SliderStyle::RotaryVerticalDrag);
    modIndexDial.setTextBoxStyle (Slider::TextEntryBoxPosition::TextBoxBelow, true, 50, 15);
    addAndMakeVisible(&modIndexDial);
    modIndexDialAttach = std::make_unique <AudioProcessorValueTreeState::SliderAttachment> (processor.treeState, MODINDEXDIAL_ID, modIndexDial);
    
    //labels:
    //attack:
    addAndMakeVisible (&allLabels[0]);
    allLabels[0].setText("Attack", dontSendNotification);
    
    allLabels[0].attachToComponent(&attackSlider, false);
    
    //release:
    addAndMakeVisible (&allLabels[1]);
    allLabels[1].setText("Release", dontSendNotification);
    allLabels[1].attachToComponent (&releaseSlider, false);
    
    //harmRatio:
    addAndMakeVisible (&allLabels[2]);
    allLabels[2].setText("Harm", dontSendNotification);
    allLabels[2].attachToComponent (&harmDial, false);
    
    //harmRatio:
    addAndMakeVisible (&allLabels[3]);
    allLabels[3].setText("ModIndex", dontSendNotification);
    allLabels[3].attachToComponent (&modIndexDial, false);
    //otherLookAndFeel.setColour(Slider::thumbColourId, Colours::purple);
    //attackSlider.setLookAndFeel(&otherLookAndFeel);
   
    
   
    //otherLookAndFeel.createSliderTextBox(dial);
    
    //Choice
    //    choiceBox.addItem ("Choice1", 1);
    //    choiceBox.addItem ("Choice2", 2);
    //    choiceBox.addItem ("Choice3", 3);
    //    choiceBox.addItem ("Choice4", 4);
    //    addAndMakeVisible(choiceBox);
   
    
    
    
    
}
JuceSynthFrameworkAudioProcessorEditor::~JuceSynthFrameworkAudioProcessorEditor()
{
}

//==============================================================================
void JuceSynthFrameworkAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    
}

void JuceSynthFrameworkAudioProcessorEditor::resized()
{
    auto bounds = getLocalBounds();
    const int componentSize { 100 };
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
   
    onOff.setBounds (bounds.removeFromLeft(100).withSizeKeepingCentre(componentSize, componentSize));
    
    //attackSlider
    attackSlider.setBounds (bounds.removeFromLeft(100).withSizeKeepingCentre(componentSize, componentSize));
    
    //releaseSlider
    releaseSlider.setBounds (bounds.removeFromLeft(100).withSizeKeepingCentre(componentSize, componentSize));
    
    //choiceBox
//    choiceBox.setBounds (bounds.removeFromLeft(100).withSizeKeepingCentre(componentSize, componentSize));
    
    // dial
    harmDial.setBounds (bounds.removeFromLeft(100).withSizeKeepingCentre(componentSize, componentSize));
    
    // dial
    modIndexDial.setBounds (bounds.removeFromLeft(100).withSizeKeepingCentre(componentSize, componentSize));
    
    
    
}

//void JuceSynthFrameworkAudioProcessorEditor::sliderValueChanged(Slider* slider)
//{
//    if (slider == &attackSlider)
//    {
//        //use access to the processor, which is in the pluginEditor H file:
//        //processor.attackTime = attackSlider.getValue();
//        
//    }
//    
//}

