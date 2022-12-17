#include <stdio.h>
#include <math.h>

#define CONSTANT (long) powl(2,64)

void unsigned_binary_multiplication(unsigned long first, unsigned long second, unsigned long *youngerBits,
                                    unsigned long *olderBits);


int main() {
    unsigned long olderBits = 0;
    unsigned long youngerBits = 0;
    unsigned_binary_multiplication(4, 4, &youngerBits, &olderBits);
    printf("Older bits: %ld ",olderBits);
    printf("Younger bits: %ld",youngerBits);

    return 0;
}

void unsigned_binary_multiplication(unsigned long first, unsigned long second, unsigned long *youngerBits,
                                    unsigned long *olderBits) {
    *youngerBits = second;
    *olderBits = 0;
    int bits = 0;
    unsigned long temp = second;
    while (temp != 0) {
        temp>>=1;
        bits++;
    }
    for (int i = 0; i < bits; ++i) {
        if ((*youngerBits & 1) == 1) {
            *olderBits += first;
        }
        *youngerBits >>= 1;
        if ((*olderBits & 1) == 1) {
            unsigned long offset = (1L << 63L);
            *youngerBits |= offset;
        }
        *olderBits >>= 1;

    }



}


