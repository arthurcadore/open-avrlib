#include "main.h"

const int LED1_PIN = 5;
const int BTN1_PIN = 2;
const int BTN2_PIN = 3;

UART Serial(9600,
            UART::DATABITS_8,
            UART::PARITY_NONE,
            UART::STOPBITS_ONE);    

ADC_channel adc(ADC_CHANNEL_0, 
                ADC_REF_AVCC, 
                ADC_PRESCALER_128);


GPIO_Pin led1(
    GPIO_Pin::GPIO_PortB,
    LED1_PIN,
    GPIO_Pin::OUTPUT
);

Timer timer(Timestamp(1000));




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

void adc_test_sync(){

for(int i = 0; i < 3; i++){
       int adc_value = adc.sample();
       char str[64];
       sprintf(str, "ADC: %d\n", adc_value);
       Serial.puts(str);
       soft_delay(1);
    }

    // // print adc avarage
    int adc_avarage = adc.avarageSample();
    char str[64];
    sprintf(str, "ADC Avarage: %d\n", adc_avarage);
    Serial.puts(str);
    soft_delay(1);

}

void adc_test_async(){
    // PARTE DO ADC
    // int n = ADMUX & 0x0F;
    // ADC_channel* adc = ADC_channel::get_instance(n);
    // adc->adc_isr_handler();

    if(adc.available()){
        int adc_value = adc.sample();
        char str[64];
        sprintf(str, "ADC: %d\n", adc_value);
        Serial.puts(str);
        soft_delay(1);
    }
}

int seconds = 0;
char str[16];

void loop(){

    Timestamp now = timer.micros();
    if(((now % 1000000) == 0) && (now /1000000 > seconds)){
        seconds++;
        sprintf(str, "Segundo: %d\n", seconds);
        Serial.puts(str);
    }
} 

int main()
{
    setup();
    while(true) loop();
}
