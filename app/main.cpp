#include <avr/io.h>
#include "gpio.h"
#include "uart.h"

const int LED1_PIN = 5;
const int LED2_PIN = 2;
const int BTN1_PIN = 0;


GPIO_Pin led1(
    GPIO_Pin::GPIO_PortB,
    LED1_PIN,
    GPIO_Pin::OUTPUT
);


UART Serial(9600);

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
    Serial.puts("Setup\n");
    //pinMode(BUTTON_PIN,INPUT);
    //pinMode(LED1_PIN, OUTPUT);
    //pinMode(LED2_PIN,OUTPUT);
    //pinMode(LED_PIN,OUTPUT);
    //DDRB = led1_mask | led2_mask;
}

void loop()
{
    Serial.put(Serial.get() + 1);
    /*Serial.put('l');
    if (btn1.read()){

    led1.clear();
    led2.clear();
    soft_delay(2);
    led1.set();
    led2.set();
    soft_delay(3);
    }else {  

    led1.clear();
    led2.clear();
    soft_delay(1);
    led1.set();
    led2.clear();
    soft_delay(2);
    led1.set();
    led2.set();
    soft_delay(3);
    led1.clear();
    led2.set();
    soft_delay(2);
    }*/
}

int main()
{
    setup();
    while(true) loop();
}
