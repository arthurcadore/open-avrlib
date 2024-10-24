#include "gpio.h"
#include "uart.cpp"

const int LED1_PIN = 5;
const int LED2_PIN = 2;
const int BUTTON_PIN = 0;

GPIO_Pin led1(
    GPIO_Pin::GPIO_PortB,
    LED1_PIN,
    GPIO_Pin::OUTPUT);

GPIO_Pin led2(
    GPIO_Pin::GPIO_PortB,
    LED2_PIN,
    GPIO_Pin::OUTPUT);

GPIO_Pin btn1(
    GPIO_Pin::GPIO_PortB,
    BUTTON_PIN,
    GPIO_Pin::INPUT);

UART Serial();

void soft_delay(int times = 1)
{
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
    //Serial.puts("Ave Maria\n");
}

void loop()
{
    //Serial.put('L');

    // if (btn1.read() == GPIO_Pin::HIGH)
    // {
    //     led1.clear();
    //     led2.clear();
    //     soft_delay(2);
    //     led1.set();
    //     led2.set();
    //     soft_delay(3);
    // }

    // else
    // {
    //     led1.clear();
    //     led2.clear();
    //     soft_delay(1);
    //     led1.set();
    //     led2.clear();
    //     soft_delay(2);
    //     led1.set();
    //     led2.set();
    //     soft_delay(3);
    //     led1.clear();
    //     led2.set();
    //     soft_delay(2);
    // }
}

int main()
{
    setup();
    while (true)
        loop();
}