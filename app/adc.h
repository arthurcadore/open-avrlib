#ifndef _ADC_H_  
#define _ADC_H_  

#include <string.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include "fifo.h"

// set reference voltage to AVCC
enum ADC_REF{
    ADC_REF_AVCC = 0,
    ADC_REF_AREF = 1,
    ADC_REF_INTERNAL = 3
};

enum ADC_CHANNEL{
    ADC_CHANNEL_0 = 0,
    ADC_CHANNEL_1 = 1,
    ADC_CHANNEL_2 = 2,
    ADC_CHANNEL_3 = 3,
    ADC_CHANNEL_4 = 4,
    ADC_CHANNEL_5 = 5,
    ADC_CHANNEL_6 = 6,
    ADC_CHANNEL_7 = 7, 
    ADC_CHANNEL_8 = 8
};

enum ADC_PRESCALER{
    ADC_PRESCALER_2 = 0,
    ADC_PRESCALER_4 = 2,
    ADC_PRESCALER_8 = 3,
    ADC_PRESCALER_16 = 4,
    ADC_PRESCALER_32 = 5,
    ADC_PRESCALER_64 = 6,
    ADC_PRESCALER_128 = 7
};

class ADC_channel{ 
public:
    ADC_channel(ADC_CHANNEL channel, 
                ADC_REF ref = ADC_REF_AREF,
                ADC_PRESCALER prescaler = ADC_PRESCALER_128);

    int sample();

    int avarageSample();

    // create adc isr handler
    static void adc_isr_handler(){
    }

private: 
    static ADC_channel* instance[16];
    ADC_CHANNEL channel;
    ADC_REF ref;
    
    // add a fifo buffer to store samples
    FIFO<8, int> samples;
};


#endif 
