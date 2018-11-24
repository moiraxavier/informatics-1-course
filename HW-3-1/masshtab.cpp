#include "masshtab.h"

float MASSHTAB(float (*trig_func)(float x), int B){
    float max = 0, min = 0;
    
    float step = 0.01, x1 = -1 + step, x2 = 1;
    for (float x = x1; x < x2; x = x + step){
        if (trig_func(x) < min)
            min = trig_func(x);
        if (trig_func(x) > max)
            max = trig_func(x);
    }
    
    //printf("MAX = %f\n", max);
    //printf("MIN = %f\n", min);
    
    max = max + fabs(min);
    
    return B/max;
}

