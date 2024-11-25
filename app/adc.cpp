#include "adc.h"

ADC_channel* ADC_channel::instance[16]; 


ADC_channel::ADC_channel(
                ADC_CHANNEL channel, 
                ADC_REF ref,
                ADC_PRESCALER prescaler){

    this->channel = channel;

    // add instance to static array
    instance[channel] = this;

    // enable ADC
    ADCSRA |= (1 << ADEN);

    // set prescaler to 128
    ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

    // set reference voltage
    ADMUX = (ADMUX & 0x3F) | (ref << 6);
}

int ADC_channel::sample(){
    // set channel
    ADMUX = (ADMUX & 0xF8) | this->channel;

    // start conversion
    ADCSRA |= (1 << ADSC);

    // wait for conversion to complete
    while(ADCSRA & (1 << ADSC));

    // add sample to buffer
    int sample = ADC;

    // add sample to buffer, if buffer is full, discard oldest sample and add new one
    if(samples.getCount() == samples.getSize()){
        samples.pop();
    }

    samples.put(sample);

    return sample;
}

int ADC_channel::avarageSample(){
    int sum = 0;
    int numSamples = samples.getCount();
    for (int i = 0; i < numSamples; i++)
    {
        sum += samples.get();
    }
    return sum / numSamples;
}   

