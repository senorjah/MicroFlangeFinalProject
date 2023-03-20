//
//  LFO.cpp
//  NewProject
//
//  Created by Nathaniel Gladstone on 3/16/23.
//

#include "LFO.hpp"

LFO::LFO() {
    
}

LFO::~LFO() {
    
}

void LFO::Initialize(float inSampleRate, float inFrequencyHz) {
    
    mSampleRate = inSampleRate;
    
    mFreqHz = inFrequencyHz;
}

float LFO::getNextSample() {
    
    // calculate sine function output scaled to repeat between -1 on the input
    float output = std::sin(juce::MathConstants<float>::twoPi * mPhase);
    
    // move our phase forward by a single step determined by sample rate
    mPhase += mFreqHz / mSampleRate;
    
    // keep phase from overloading
    if (mPhase > 1.f) {
        mPhase -= 1.f;
    }
    
    return output;
}
