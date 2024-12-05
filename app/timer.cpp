#include "timer.h"

Timer* Timer::instance;

Timer::Timer(Timestamp resulotion): time(0), resulotion(resulotion){
    start();
}

void Timer::start(){

    instance = this;

    // configurar timer (prescaler, valor de comparação)
    TCCR0A = 0; // modo normal
    OCR0A = 250; // valor de comparação

    // habilitar interrupção por comparação
    TIMSK0 |= 1 << OCIE0A;

    // iniciar timer
    TCNT0 = 0;  
    TCCR0B = 3 << CS00; // prescaler 64
}

ISR(TIMER0_COMPA_vect){
    Timer::get_instance()->isr_output_compare();
}

void Timer::isr_output_compare(){
    // incrementar tempo E zerar timer
    TCNT0 = 0;
    time += resulotion;
}

Timestamp Timer::micros(){
    cli();
    Timestamp tmp = this->time;
    sei();
    return tmp;
}

Timestamp Timer::milis(){
    return micros() / 1000;
}