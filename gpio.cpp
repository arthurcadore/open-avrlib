#include "gpio.h"


GPIO_Pin::GPIO_Pin(GPIO_Port_Name port, int pin, GPIO_Direction dir){

    // cria o valor 1 (0000 0001) e  realiza um shift para o número pin;
    mask = 1 << pin;

    port = (GPIO_Port* ) PORT_ADDR[port_name];

    if(dir == OUTPUT){
        port->ddr |= mask;
    }else{
        port->ddr &= ~mask;
    }

}

void GPIO_Pin::set(){

}

void GPIO_Pin::clear(){

}

int GPIO_Pin::read(){

}

int GPIO_Pin::write(){


}