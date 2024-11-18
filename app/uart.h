#ifndef __UART_H__
#define __UART_H__

#include <avr/io.h>
#include <string.h>
#include "fifo.h"
#include <avr/interrupt.h>



class UART {
private: 
    FIFO<16, char> tx_fifo;
    FIFO<16, char> rx_fifo;

    static UART* instances[1];

public:
    static const unsigned long Fcpu = 16e6;
    enum Databits_t{
        DATABITS_5 = 0,
        DATABITS_6 = 1,
        DATABITS_7 = 2,
        DATABITS_8 = 3,
        DATABITS_9 = 7
    };
    
    enum Parity_t{
        PARITY_NONE = 0,
        PARITY_EVEN = 2,
        PARITY_ODD = 3
    };

    enum Stopbits_t{
        STOPBITS_ONE = 0,
        STOPBITS_TWO = 1
    };

    UART(unsigned long baudrate = 9600,
        Databits_t databits = DATABITS_8,
        Parity_t parity = PARITY_NONE,
        Stopbits_t stopbits = STOPBITS_ONE);

        
    void sync_put(char c);
    void sync_puts(const char * s);
    char sync_get();

    void put(char c);
    void udre_isr_handler();
    void puts(const char * s);
    char get();
    char udr_isr_handler();
    
    static UART * get_instance(int uart){
        return instances[uart];
    }


private:
    void set_stopbits(Stopbits_t stopbits);
    void set_databits(Databits_t databits);
    void set_parity(Parity_t parity);
};

#endif