#ifndef __GPIO_PIN_H__
#define __GPIO_PIN_H__

class GPIO_Pin {
private:
    const int PORT_ADDR[3] = {0x23, 0x26, 0x29};

    struct GPIO_Port{
        unsigned char pin;
        unsigned char ddr;
        unsigned char port;
    }
    GPIO_Port *port;
    unsigned char mask;

public: 
    enum GPIO_Port_Name{
        GPIO_PortB = 0,
        GPIO_PortC = 1,
        GPIO_PortD = 2        
    };

    enum GPIO_Direction{
        INPUT = 0,
        OUTPUT = 1
    }
    GPIO_Pin(GPIO_Port_Name port, int pin, GPIO_Direction dir);
    void set();
    void clear();
    int read();
};

#endif;