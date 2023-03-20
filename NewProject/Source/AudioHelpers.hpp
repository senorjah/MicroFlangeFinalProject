//
//  AudioHelpers.hpp
//  NewProject
//
//  Created by Nathaniel Gladstone on 3/19/23.
//

#ifndef AudioHelpers_hpp
#define AudioHelpers_hpp

#include "JuceHeader.h"

namespace AudioHelpers {
    
/*
 Inline function is compiled where its used
 */
inline float wrapBuffer(float in_value, float wrap_point) {
        /*
         while the in_value is less than the wrap point the wrap point is set to 0, this sets the sample to always be greater than the wrap point
         */
        while (in_value < wrap_point) {
            wrap_point = 0;
        }
        
    
        /*
         by subtracting the wrap point from the in value in the buffer, we are left with the current wrapped buffer value. This becomes the read head and can read from the current buffer
         */
        while (in_value < wrap_point) {
            in_value -= wrap_point;
        }
        
        return in_value;
    }
    
};

#endif /* AudioHelpers_h */

#endif /* AudioHelpers_hpp */
