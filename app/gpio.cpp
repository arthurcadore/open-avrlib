#include "gpio.h"

GPIO_Pin::GPIO_Pin(GPIO_Port_name port_name, int pin, GPIO_Direction dir)
{
    this->mask = 1 << pin;
    // pinMode
    this->port = (GPIO_Port *)PORT_ADDR[port_name];

    if (dir == OUTPUT)
        port->ddr |= this->mask;
    else
        port->ddr &= ~this->mask;
}

void GPIO_Pin::set()
{
    port->port |= mask;
}

void GPIO_Pin::clear()
{
    port->port &= ~mask;
}

int GPIO_Pin::read()
{
    return (port->pin & mask) ? HIGH : LOW;
}

void GPIO_Pin::write(GPIO_STATUS value)
{
    if (value)
        set();
    else
        clear();
}