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
: AudioProcessorEditor (&p), processor (p), oscGUI(p)
{
    setSize(1000,300);
    
    
    addAndMakeVisible(&oscGUI);
    
    
    
     //textbutton Bool
    onOff.setColour (TextButton::buttonColourId, Colours::purple);
    onOff.setColour (TextButton::buttonOnColourId, Colours::yellow);
    onOff.setClickingTogglesState (true);
    onOff.onClick = [this] () {};
    addAndMakeVisible(&onOff);
    onOffAttach = std::make_unique <AudioProcessorValueTreeState::ButtonAttachment> (processor.treeState, ONOFF_ID, onOff);
    
    
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
    allLabels[2].setText("Harmonicity", dontSendNotification);
    allLabels[2].attachToComponent (&harmDial, false);
    
    //mod index:
    addAndMakeVisible (&allLabels[3]);
    allLabels[3].setText("Mod Index", dontSendNotification);
    allLabels[3].attachToComponent (&modIndexDial, false);
    
    
    //mod index amp mod
    addAndMakeVisible(&allLabels[4]);
    allLabels[4].setText("Mod Index Amp Mod Wave Select", dontSendNotification);
    allLabels[4].attachToComponent (&oscGUI, false);
    //otherLookAndFeel.setColour(Slider::thumbColourId, Colours::purple);
    //attackSlider.setLookAndFeel(&otherLookAndFeel);
   
    
    
    
    // Mod index
   
    //otherLookAndFeel.createSliderTextBox(dial);
    
    
   
    
    
    
    
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
    
    
    //modChoice.setBounds (bounds.removeFromLeft(100).withSizeKeepingCentre(componentSize, componentSize / 3));
    
    Rectangle<int> area = getLocalBounds(); //this is the dimensions of the whole UI
    
    const int componentWidth = 200;
    const int componentHeight = 200;
    
    //oscGUI.setBounds(area.removeFromLeft(componentWidth).removeFromTop(componentHeight));
    
    
    oscGUI.setBounds(bounds.removeFromLeft(100).withSizeKeepingCentre(componentHeight, componentWidth));
    
    
    
    
    //onOff.setBounds (bounds.removeFromLeft(100).withSizeKeepingCentre(componentSize, componentSize));
    
    
    
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

