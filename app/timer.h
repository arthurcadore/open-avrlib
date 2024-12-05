#ifndef _TIMER_H_  
#define _TIMER_H_  
#include <avr/interrupt.h>
#include <avr/io.h>


typedef unsigned long long Timestamp;

class Timer {
private:
    Timestamp time;
    Timestamp resulotion;
    void start();
    static Timer * instance;

public:
    Timer(Timestamp resulotion);

    void isr_output_compare();

    Timestamp micros();

    Timestamp milis();

    static Timer* get_instance(){
        return instance;
    }

};

#endif
