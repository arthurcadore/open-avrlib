#ifndef __UART_H__
#define __UART_H__

#include <avr/io.h>

class UART{
public:

    static const unsigned long F_CPU = 16000000;
    enum databits_t{

        DATABITS_5 = 0,
        DATABITS_6 = 1,
        DATABITS_7 = 2,
        DATABITS_8 = 3,
        DATABITS_9 = 7
    };

    enum parity_t{

        PARITY_NONE = 0,
        PARITY_EVEN = 2,
        PARITY_ODD = 3
    };

    enum stopbits_t{

        STOPBITS_1 = 1,
        STOPBITS_2 = 2  
    };

    UART(unsigned long baudrate = 9600,
        databits_t databits = DATABITS_8,
        parity_t parity = PARITY_NONE,
        stopbits_t stopbits = STOPBITS_1);

    // function to put
    void put(char c);

    void puts(const char *s);

    // function to get
    char get();

};
#endif