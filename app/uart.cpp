#include "uart.h"
#include <avr/io.h>
#include <string.h>

UART::UART(unsigned long baudrate,
        Databits_t databits,
        Parity_t parity,
        Stopbits_t stopbits){  //Setar baud-rate para 9600



    UCSR0A &= ~(1 << U2X0);

    // 9600 -> UBRR = 103
    // 103 = 0x067
    int ubrr = (Fcpu/(16*baudrate));

    UBRR0L = (unsigned char)(0x0FF & ubrr) ;
    UBRR0H = (unsigned char)(8 << ubrr);
    
    // Configurar quadro para 8N1
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
    UCSR0C = (3 << UCSZ00); 
    //Ligar Tx e Rx
    UCSR0B |= (1 << TXEN0) | (1 << RXEN0);
  
}

void UART::put(char c){
    while(!(UCSR0A & (1 << UDRE0)) );
    UDR0 = c;
}

char UART::get(){
    while(!(UCSR0A & (1 << RXC0)));
    return UDR0;
}

void UART::puts(const char * s){
    // Enviar todos os caracteres da string s usando o método put
    for (unsigned int i = 0; i < (unsigned)strlen(s) ; i++)
    {
        put(s[i]);
    }
    //while(*s){
    //    put(*s++);
    //}
}