#include "gpio.h"



GPIO_Pin::GPIO_Pin(GPIO_Port_Name port_name, int pin ,GPIO_Direction dir){
    //pinMode
    this->mask = (1 << pin);
    this->port = (GPIO_Port *)PORT_ADDR[port_name];
    if(dir == OUTPUT){
        this->port->ddr |= this->mask;
    }else{
        this->port->ddr &= ~this->mask;
    }
}


void GPIO_Pin::set(){
    //DigitalWrite
    port->port |= mask;
}

void GPIO_Pin::clear(){
    //digitalWrite
    port->port &= mask; 
}

void GPIO_Pin::write(GPIO_STATUS value){
    if(value){
        set();
    }else{
        clear();
    }
}

int GPIO_Pin::read(){
    //DifitalRead
    return (this->port->pin & this->mask) > 0; 
}


