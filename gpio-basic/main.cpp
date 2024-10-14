#include <avr/io.h>
#include "gpio.h"

const int LED1_PIN = 5;    // Porta B 5
const int LED2_PIN = 2;    // Porta B 2
const int BUTTON_PIN = 8;  // Porta B 0

const unsigned char BIT_MASK = 0x01;  // 0000 0001

unsigned char *ddrb_ptr = (unsigned char *)0x24;
unsigned char *pinb_ptr = (unsigned char *)0x23;
unsigned char *portb_ptr = (unsigned char *)0x25;
#define DDRB *ddrb_ptr
#define PINB *pinb_ptr
#define PORTB *portb_ptr

#define INPUT 1
#define HIGH 1
#define OUTPUT 0
#define LOW 0

void pinMode(int pin, int mode) {
  if (mode == OUTPUT) {
    DDRB |= BIT_MASK << pin;
  } else {
    DDRB |= ~BIT_MASK << pin;
  }

  return;
}

void digitalWrite(int pin, char value) {
  if (value == HIGH) {
    PORTB |= BIT_MASK << pin;
  } else {
    PORTB &= ~BIT_MASK << pin;
  }

  return;
}

int digitalRead(int pin) {
  if (PINB & (BIT_MASK << pin)) {
    return HIGH;
  } else {
    return LOW;
  }
}

void soft_delay() {
  unsigned long long x = 0xffff;

  while (x--) {
  }
}

void setup() {
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED1_PIN, OUTPUT);
  pinMode(LED2_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED1_PIN, LOW);
  digitalWrite(LED2_PIN, LOW);
  soft_delay();

  digitalWrite(LED1_PIN, HIGH);
  soft_delay();

  digitalWrite(LED2_PIN, HIGH);
  soft_delay();
}

int main() {
  setup();
  while (true) loop();
}
