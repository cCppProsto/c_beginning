#ifndef BITWISE_TOOLS_H
#define BITWISE_TOOLS_H

#define BIT_8 0x80
#define BIT_7 0x40
#define BIT_6 0x20
#define BIT_5 0x10
#define BIT_4 0x08
#define BIT_3 0x04
#define BIT_2 0x02
#define BIT_1 0x01

void print_bits_state(unsigned char aCh);
void print_bits_state_shift(unsigned char aCh);

unsigned char set_bit(unsigned char aCh, unsigned char aN);
unsigned char clear_bit(unsigned char aCh, unsigned char aN);
unsigned char invert_bit(unsigned char aCh, unsigned char aN);
unsigned char test_bit(unsigned char aCh, unsigned char aN);

#endif // BITWISE_TOOLS_H
