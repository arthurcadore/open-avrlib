## to check the interruptions in the assembly code

```bash
avr-objdump -d build/main.elf | less
```

Expected result: 

```assembly
build/main.elf:     file format elf32-avr


Disassembly of section .text:

00000000 <__vectors>:
   0:   0c 94 35 00     jmp     0x6a    ; 0x6a <__ctors_end>
   4:   0c 94 3a 01     jmp     0x274   ; 0x274 <__vector_1>
   8:   0c 94 4d 01     jmp     0x29a   ; 0x29a <__vector_2>
   c:   0c 94 5d 00     jmp     0xba    ; 0xba <__bad_interrupt>
  10:   0c 94 5d 00     jmp     0xba    ; 0xba <__bad_interrupt>
  14:   0c 94 5d 00     jmp     0xba    ; 0xba <__bad_interrupt>
  18:   0c 94 5d 00     jmp     0xba    ; 0xba <__bad_interrupt>
  1c:   0c 94 5d 00     jmp     0xba    ; 0xba <__bad_interrupt>
  20:   0c 94 5d 00     jmp     0xba    ; 0xba <__bad_interrupt>
  24:   0c 94 5d 00     jmp     0xba    ; 0xba <__bad_interrupt>
  28:   0c 94 5d 00     jmp     0xba    ; 0xba <__bad_interrupt>
  2c:   0c 94 5d 00     jmp     0xba    ; 0xba <__bad_interrupt>
  30:   0c 94 5d 00     jmp     0xba    ; 0xba <__bad_interrupt>
```
