#include "uart.h"
#include <avr/io.h>
#include "string.h"

UART::UART(unsigned long baudrate, databits_t databits, parity_t parity, stopbits_t stopbits);
    {

    // calculate the build rate of the register

    UCRSRA = (1 << 1);
    UCRS0A &= ~(1 << U2X0);

    int BDR = F_CPU / (16 * baudrate) - 1;

    // Set the baud rate

    UBRR0H = (unsigned char) (0x0FF & BDR);
    UBRR0L = (unsigned char) (BDR >> 8);
    
    // 9600 => 103 => 0x67 => 0x067 (pois o vetor é de 12bits)
    //UBRR0L = 0x067;
    //UBRR0H = 0; 

    // Frame 8N1 
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
    UCSR0C = (3 << UCSZ00);

    // Enable Tx
    UCSR0B |= (1 << TXEN0);
}

// function to put
void UART::put(char c){
    while( !(UCSR0A & (1 << UDRE0)));
    UDR0 = c;
}

void UART::puts(const char *s){
    // Enviar  todos os caracteres da string s usando o método put

    while(*s != '\0'){
        put(*s);
        s++;
    }
}

// function to get
char UART::get(){
    while( (UCSR0A & (1 << RXC0)));

    return UDR0;
}