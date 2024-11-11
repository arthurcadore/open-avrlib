#include "main.h"

const int LED1_PIN = 5;
const int BTN1_PIN = 2;

GPIO_Pin led1(
    GPIO_Pin::GPIO_PortB,
    LED1_PIN,
    GPIO_Pin::OUTPUT
);

void btn_handler(){
    static int led_state = 0;
    led_state != led_state;
    led1.write(led_state ? GPIO_Pin::HIGH : GPIO_Pin::LOW); ;
};

GPIO_Pin btn (
    GPIO_Pin::GPIO_PortB,
    BTN1_PIN,
    GPIO_Pin::INT_RISING,
    btn_handler
);

UART Serial(9600,
            UART::DATABITS_8,
            UART::PARITY_NONE,
            UART::STOPBITS_ONE);    

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
    sei();
    Serial.puts("Setup\n");
}

void loop()
{
    Serial.put(Serial.get() + 1);
}

int main()
{
    setup();
    while(true) loop();
}
