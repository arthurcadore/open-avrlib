#ifndef _ADC_H_  
#define _ADC_H_  

#include <string.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "fifo.h"

class ADC_channel{ 
private:
    FIFO<16, char> samples;
    int channel;
public:
    ADC_channel(int channel);

    int sample();
};


#endif 
