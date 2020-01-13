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
: AudioProcessorEditor (&p), processor (p), oscGUI(p), envGUI(p), fmodGUI(p)
{
    setSize(800,300);
    
    // Add the oscillator gui
    addAndMakeVisible(&oscGUI);
    // Add the envelope GUI
    // Add Fmod GUI
    addAndMakeVisible(&fmodGUI);
    
    addAndMakeVisible(&envGUI);
    
    
    }
JuceSynthFrameworkAudioProcessorEditor::~JuceSynthFrameworkAudioProcessorEditor()
{
}

//==============================================================================
void JuceSynthFrameworkAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));
    
    //g.fillCheckerBoard

    g.setColour (Colours::white);
    g.setFont (15.0f);
    
}

void JuceSynthFrameworkAudioProcessorEditor::resized()
{
    Rectangle<int> area = getLocalBounds();
    
    
    
    const int componentWidth = 200;
    const int componentHeight = 200;
    
    auto bounds = getLocalBounds();
    const int componentSize { 100 };
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
   
    
    envGUI.setBounds(area.removeFromLeft(componentWidth*2).removeFromTop(componentHeight));
    
    fmodGUI.setBounds(area.removeFromLeft(componentWidth).removeFromTop(componentHeight));
    
    oscGUI.setBounds(area.removeFromLeft(componentWidth).removeFromTop(componentHeight));
    
    
    
    
    
    
}



