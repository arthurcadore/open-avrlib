APP := main.cpp
COMPONENTS := gpio.o
SERIAL_PORT := /dev/ttyACM0
BUILD_DIR := build
AVRLIB_NAME := libavr.a

CC_FLAGS := -mmcu=atmega328p
# CC_FLAGS := -mmcu=atmega328p -Wl,-u,vfprintf -lprintf_flt  # habilita uso de floats no printf

all: $(BUILD_DIR) $(COMPONENTS)
	avr-g++ $(CC_FLAGS) $(APP) $(BUILD_DIR)/$(AVRLIB_NAME) -o $(BUILD_DIR)/main.elf
	avr-size $(BUILD_DIR)/main.elf
	avr-objcopy -O ihex $(BUILD_DIR)/main.elf $(BUILD_DIR)/main.ihex
	avrdude -p atmega328p -c arduino -P $(SERIAL_PORT) -U flash:w:$(BUILD_DIR)/main.ihex

%.o: %.cpp
	avr-g++ $(CC_FLAGS) -c $< -o $(BUILD_DIR)/$@
	avr-ar rvs $(BUILD_DIR)/$(AVRLIB_NAME) $(BUILD_DIR)/$@

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

clean:
	rm -f *.o *.elf *.ihex 
	rm -rf $(BUILD_DIR)