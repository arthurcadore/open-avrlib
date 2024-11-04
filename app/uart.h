#ifndef __UART_H__
#define __UART_H__


class UART{
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

        
    void put(char c);
    void puts(const char * s);
    char get();
};

#endif