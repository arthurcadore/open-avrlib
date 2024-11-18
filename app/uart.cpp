#include "uart.h"
#include <avr/io.h>
#include <string.h>
#include <avr/interrupt.h>


UART* UART::instances[1]; 

UART::UART(unsigned long baudrate,
        Databits_t databits,
        Parity_t parity,
        Stopbits_t stopbits){  //Setar baud-rate para 9600

    instances[0] = this;

    UCSR0A &= ~(1 << U2X0);

    // 9600 -> UBRR = 103
    // 103 = 0x067
    int ubrr = (Fcpu/(16*baudrate));

    UBRR0L = (unsigned char)(0x0FF & ubrr) ;
    UBRR0H = (unsigned char)(8 << ubrr);
    
    // Configurar quadro para 8N1
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
    UCSR0C = (3 << UCSZ00); 

    UCSR0C = (parity << UPM00) | (stopbits << USBS0) | ((0x3 & databits) << UCSZ00);
    
    // Configurar stop bits
    // set_stopbits(stopbits);
    // set_parity(parity);
    // set_databits(databits);

    //Ligar Tx e Rx
    UCSR0B = (1 << TXEN0) | (1 << RXEN0) | (((0x4 & databits)? 1 : 0) << UCSZ02);
}

void UART::sync_put(char c){
    while(!(UCSR0A & (1 << UDRE0)) );
    UDR0 = c;
}

char UART::sync_get(){
    while(!(UCSR0A & (1 << RXC0)));
    return UDR0;
} 

// Enviar uma string pela serial
void UART::sync_puts(const char * s){

    // Enviar todos os caracteres da string s usando o método put
    while(*s){
        sync_put(*s++);
    }
}

// Enviar uma string pela serial
void UART::puts(const char * s){

    // Enviar todos os caracteres da string s usando o método put
    while(*s){
        put(*s++);
    }
}

ISR(USART_UDRE_vect){
    UART* uart = UART::get_instance(0);
    uart->udre_isr_handler();
}

void UART::udre_isr_handler(){
    if(tx_fifo.getCount() > 0){
        UDR0 = tx_fifo.get();
    } else {
        UCSR0B &= ~(1 << UDRIE0);
    }
}


void UART::put(char c){
    
    tx_fifo.put(c);
    // Habilitar interrupção por recepção completa
    UCSR0B |= (1 << UDRIE0);
}

ISR(USART_RX_vect){
    UART* uart = UART::get_instance(0);
    uart->udr_isr_handler();
}

char UART::udr_isr_handler(){
    rx_fifo.put(UDR0);
    return UDR0;
}

char UART::get(){
    return rx_fifo.get();
}