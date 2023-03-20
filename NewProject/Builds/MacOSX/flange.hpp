//
//  flange.hpp
//  NewProject - VST3
//
//  Created by Nathaniel Gladstone on 3/16/23.
//

#ifndef flange_hpp
#define flange_hpp

#include "JuceHeader.h"

#endif /* flange_hpp */

class flange {
    flange();
    
    ~flange();
    
    void initialize(float inSampleRate, int blockSize);
    
    void setParameters(float inTimeMilliseconds, float inFeedbackAmount, float inMix, float inLfoAmount);
    
    void processBlock(float* inBuffer, int inNumSamples);
    
    void processSample(float& inSample);
    
private:
    
    float mSampleRate;
    
    float mMix = 0;
    float mFeedbackAmount = 0;
    juce::LinearSmoothedValue<float> mTimeInMilliseconds;
    
    float mWriteHead = 0;
    float mFeedbackSample = 0;
    
    juce::AudioBuffer<float> mCircularBuffer;
}
