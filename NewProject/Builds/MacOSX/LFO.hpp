//
//  LFO.hpp
//  NewProject
//
//  Created by Nathaniel Gladstone on 3/16/23.
//

#ifndef LFO_hpp
#define LFO_hpp

#include "JuceHeader.h"

#endif /* LFO_hpp */

class LFO {
    
    LFO();
    ~LFO();
    void Initialize(float inSampleRate, float inBlocksize);
    
    void setParameters(float inLfoRate);
    
    void processBlock(float* inBuffer, int inNumSamples);
    
    void processSample(float& inSample);
    
    float getNextSample();

    
private:
    float mFreqHz = 1;
    float mSampleRate = 44100;
    float mPhase = 0;
    
};
