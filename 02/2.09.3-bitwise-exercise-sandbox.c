#include <stdio.h>
#include <stdint.h>

uint32_t set_bits(uint32_t reg, uint8_t pos, uint8_t len);
uint16_t highest_set_bit(uint16_t reg);
uint16_t spread_bits(uint8_t val);

int main() {
    uint32_t reg = 0;
    uint8_t pos = 4, len = 3;
    printf("%u\n", set_bits(reg, pos, len));

    printf("%u\n", highest_set_bit(38));
    return 0;
}

/* set_bits: Set a few bits starting from a given position and covering a specific length */
uint32_t set_bits(uint32_t reg, uint8_t pos, uint8_t len) {
    uint32_t fill = ~(~(uint32_t)1 << len-1);
    return reg | (fill << (pos));
}


/* highest_set_bit: Return a value where only the highest (leftmost) set bit is retained */
uint16_t highest_set_bit(uint16_t reg) {
    uint16_t full = reg | reg >> 1;
    full |= full >> 2;
    full |= full >> 4;
    full |= full >> 8;
    full |= full >> 16;

    uint16_t mask = (full + 1) >> 1;
    return reg & mask;
}

/* spread_bits: spread 8 bit in between of 16-bits of 0 */
uint16_t spread_bits(uint8_t val) {
    uint16_t res = 0;
    res |= 1 & val;
    res |= 4 & (val << 1);
    res |= 16 & (val << 2);
    res |= 64 & (val << 3);
    res |= 256 & (val << 4);
    res |= 1024 & (val << 5);
    res |= 4096 & (val << 6);
    res |= 16384 & (val << 7);
    return res;
}
