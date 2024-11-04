#include "gpio.h"
#include <avr/io.h>


const int LED1_PIN = 5;
const int LED2_PIN = 2;
const int BUTTON_PIN = 0;
// const unsigned char led1_mask = 1 << LED1_PIN; // 0x20;
// const unsigned char led2_mask = 1 << LED2_PIN; // 0x04;  
// unsigned char * ddrb_ptr = (unsigned char *)0x24;
// unsigned char * portb_ptr = (unsigned char *)0x25;
// unsigned char * pinb_ptr = (unsigned char *)0x23;
// 
// #define DDRB *ddrb_ptr
// #define PORTB *portb_ptr
// #define PINB *pinb_ptr
// #define OUTPUT 0
// #define INPUT 1
// #define HIGH 1
//// #define LOW 0 
//
//void pinMode(int pin, int mode) {
//
//    unsigned char mask = 1 << pin;
//    if(mode == INPUT){
//        DDRB &= ~mask;
//    }else if(mode == OUTPUT){
//        DDRB |= mask;
//    }
//    
//}
//
//void digitalWrite(int pin, char value) {
//    unsigned char mask = 1 << pin;
//    if(value == LOW){
//        PORTB &= ~mask;
//    } else if (value == HIGH){
//        PORTB |= mask;
//    }
//}
//
//unsigned int digitalRead(int pin) {
//    if (pin < 0 || pin > 7) {
//        return LOW;  // Invalid pin, return LOW by default
//    }
//
//    unsigned char mask = 1 << pin;  // Create mask for the pin
//    return (PINB & mask) ? HIGH : LOW;  // Check if the bit is set
//}

void soft_delay(int times=1){
    for (int i = 0; i < times; i++)
    {
    unsigned long long x = 0xffff;
    while (x--)
    {
        
    }   
     }
    

    
}


void setup()
{
    pinMode(BUTTON_PIN,INPUT);
    pinMode(LED1_PIN, OUTPUT);
    pinMode(LED2_PIN,OUTPUT);
    //pinMode(LED_PIN,OUTPUT);
    DDRB = led1_mask | led2_mask;
}

void loop()
{
    if (digitalRead(BUTTON_PIN) == HIGH){
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, LOW);
    soft_delay(2);
    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, HIGH);
    soft_delay(3);
    }else {  
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, LOW);
    soft_delay(1);
    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, LOW);
    soft_delay(2);
    digitalWrite(LED1_PIN, HIGH);
    digitalWrite(LED2_PIN, HIGH);
    soft_delay(3);
    digitalWrite(LED1_PIN, LOW);
    digitalWrite(LED2_PIN, HIGH);
    soft_delay(2);}
}

int main()
{
    setup();
    while(true) loop();
}
