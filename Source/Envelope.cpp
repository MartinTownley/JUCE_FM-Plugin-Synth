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

}

Envelope::~Envelope()
{
}

void Envelope::paint (Graphics& g)
{
    
}

void Envelope::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
