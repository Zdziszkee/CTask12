#include <stdio.h>
#include <math.h>

#define CONSTANT (long) powl(2,64)

void unsigned_binary_multiplication(unsigned long first, unsigned long second, unsigned long *youngerBits,
                                    unsigned long *olderBits);

void bin(unsigned long n);

int main() {
    unsigned long olderBits = 0;
    unsigned long youngerBits = 0;
    unsigned_binary_multiplication(3, 3, &youngerBits, &olderBits);
    bin(olderBits);
    bin(youngerBits);
    return 0;
}

void unsigned_binary_multiplication(unsigned long first, unsigned long second, unsigned long *youngerBits,
                                    unsigned long *olderBits) {
    *youngerBits = second;
    *olderBits = 0;
    int bits = sizeof(first) * 8;
    for (int i = 0; i < bits; ++i) {
        if ((*youngerBits & 1) == 1) {
            *olderBits += first;
        }
        *youngerBits >>= 1;
        if ((*olderBits & 1) == 1) {
            unsigned long offset = (1L<<63L);
            *youngerBits |= offset;
        }
        *olderBits >>= 1;

    }


}

void bin(unsigned long n) {
    if (n == 0) {
        printf("0");
        return;
    }
    while (n) {
        if (n & 1)
            printf("1");
        else
            printf("0");

        n >>= 1;
    }
    printf("");
}
