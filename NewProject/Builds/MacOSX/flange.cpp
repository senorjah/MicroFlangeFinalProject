//
//  flange.cpp
//  NewProject - VST3
//
//  Created by Nathaniel Gladstone on 3/16/23.
//

#include "flange.hpp"
#include "LFO.hpp"

flange::flange() {
    
}

flange::~flange() {
        
}

void flange::initialize(float inSampleRate, <#int blockSize#>)
{
    mSampleRate = inSampleRate;
}

void flange::setParameters(float inTimeMilliseconds, float inFeedbackAmount, float inMix, float inLfoAmount)
{
    mTimeInMilliseconds.setTargetValue(inTimeMilliseconds);
    mFeedbackAmount = inFeedbackAmount;
    mMix = inMix;
}

void flange::processSample(float& inSample)
{
    mCircularBuffer.setSample(0, mWriteHead, std::tanh(inSample + (mFeedbackSample * mFeedbackAmount)));
    auto lfo_mod = LFO.getNextSample();
    mWriteHead++;
    
    if (mWriteHead >= mCircularBuffer.getNumSamples()) {
        mWriteHead = 0;
    }
    
    float time_in_sample = mTimeInMilliseconds.getNextValue() * lfo_mod * mSampleRate;
    float read_head = mWriteHead - time_in_sample;
    
    read_head = AudioHelpers::wrap_buffer(read_head, mCircularBuffer.getNumSamples());
    
    int sample_x_pos = floor(read_head);
    int sample_x1_pos = sample_x_pos + 1;
    
    //sample_x_pos = AudioHelpers::wrap_buffer
    
    float inter_sample_amound = read_head - sample_x_pos;
    
    float sample_x = mCircularBuffer.getSample(0, sample_x_pos);
    float sample_x1 = mCircularBuffer.getSample(0, sample_x1_pos);
}
