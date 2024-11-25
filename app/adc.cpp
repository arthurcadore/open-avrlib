#include "adc.h"

ADC_channel::ADC_channel(int channel){
    this->channel = channel;

    // enable ADC
    ADCSRA |= (1 << ADEN);

    // set prescaler to 128
    ADCSRA |= (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);




}

int ADC_channel::sample(){
    // set channel
    ADMUX = (ADMUX & 0xF8) | this->channel;

    // start conversion
    ADCSRA |= (1 << ADSC);

    // wait for conversion to complete
    while(ADCSRA & (1 << ADSC));

    // return result to user
    return ADC;
}

