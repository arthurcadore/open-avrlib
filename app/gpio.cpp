#include "gpio.h"


const int GPIO_Pin::PORT_ADDR[3] = {0x23, 0x26, 0x29};
GPIO_Pin::FuncPtr_t GPIO_Pin::handlers[2];

ISR(INT0_vect){
    GPIO_Pin::FuncPtr_t handler = GPIO_Pin::get_handler(0);
    handler();
}

ISR(INT1_vect){

}


GPIO_Pin::GPIO_Pin(GPIO_Port_Name port_name, 
                   int pin,
                   GPIO_Direction dir,
                   FuncPtr_t handler){
    
    // verifica se o pino é de interrupção e aplica o handler
    if(dir >= INT_LOW){
        int int_pin = pin -2;
        int int_sens = dir - 2;
        handlers[int_pin] = handler;

        // configurar sensibilidade da interrupção
        unsigned char tmp = EICRA;
        tmp &= ~(3 << (int_pin*2));
        tmp |= int_sens << (int_pin*2);
        EICRA = tmp;

        // habilitar interrupção
        EIMSK |= 1 << int_pin;
    }

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


