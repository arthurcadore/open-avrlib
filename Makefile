# Author: Arthur Cadore
# Date: 2024/11/11

APP := app/main.cpp
COMPONENTS := app/gpio.o app/uart.o app/adc.o
SERIAL_PORT := /dev/ttyACM0
# SERIAL_PORT := /dev/ttyUSB0 (for ATMega2560p)	

BUILD_DIR := ./build
AVRLIB_NAME := libavr.a

CC_FLAGS := -mmcu=atmega328p
# CC_FLAGS := -mmcu=atmega328p -Wl,-u,vfprintf -lprintf_flt

all: $(BUILD_DIR) $(COMPONENTS)
	avr-g++ $(CC_FLAGS) $(APP) $(BUILD_DIR)/$(AVRLIB_NAME) -o $(BUILD_DIR)/main.elf
	avr-size $(BUILD_DIR)/main.elf
	avr-objcopy -O ihex $(BUILD_DIR)/main.elf $(BUILD_DIR)/main.ihex
	avrdude -p atmega328p -c arduino -P $(SERIAL_PORT) -U flash:w:$(BUILD_DIR)/main.ihex
#	avrdude -p atmega2560 -c arduino -P $(SERIAL_PORT) -U flash:w:$(BUILD_DIR)/main.ihex (for ATMega2560p)


app/%.o: app/%.cpp
	avr-g++ $(CC_FLAGS) -c $< -o $(BUILD_DIR)/$(notdir $@)
	avr-ar rvs $(BUILD_DIR)/$(AVRLIB_NAME) $(BUILD_DIR)/$(notdir $@)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

clean:
	rm -f $(BUILD_DIR)/*.o $(BUILD_DIR)/*.elf $(BUILD_DIR)/*.ihex
	rm -rf $(BUILD_DIR)

install: 
	sudo apt-get install gcc-avr
	sudo apt-get install build-essential gcc-avr avr-libc avrdude
