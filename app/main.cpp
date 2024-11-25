#include "main.h"

const int LED1_PIN = 5;
const int BTN1_PIN = 2;
const int BTN2_PIN = 3;

UART Serial(9600,
            UART::DATABITS_8,
            UART::PARITY_NONE,
            UART::STOPBITS_ONE);    

GPIO_Pin led1(
    GPIO_Pin::GPIO_PortB,
    LED1_PIN,
    GPIO_Pin::OUTPUT
);


// void btn1_handler(){
//     static int led_state = 0;
//     led_state != led_state;
//     led1.write(led_state ? GPIO_Pin::HIGH : GPIO_Pin::LOW); ;
//     Serial.puts("Botão 1\n");
// };

// void btn2_handler(){
//     static int led_state = 0;
//     led_state != led_state;
//     led1.write(led_state ? GPIO_Pin::HIGH : GPIO_Pin::LOW); ;
//     Serial.puts("Botão 2\n");
// };


// GPIO_Pin btn1 (
//     GPIO_Pin::GPIO_PortB,
//     BTN1_PIN,
//     GPIO_Pin::INT_RISING,
//     // btn1_handler
// );

// GPIO_Pin btn2 (
//     GPIO_Pin::GPIO_PortB,
//     BTN2_PIN,
//     GPIO_Pin::INT_RISING,
//     // btn2_handler
// );


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
    ADC_channel adc(0);
    
    int adc_value = adc.sample();

    char str[64];
    sprintf(str, "ADC: %d\n", adc_value);

    Serial.puts(str);

    soft_delay(3);
} 

int main()
{
    setup();
    while(true) loop();
}
