#include <stdio.h>

#define BYTE 8

unsigned packCharacters(char, char);

void unpackCharacters(unsigned);

unsigned power2(unsigned, unsigned);

void displayBits(unsigned);

int main(void) {
		
	char ch1 = 'a';
	char ch2 = 'k';
	unsigned num = packCharacters(ch1, ch2);
	unpackCharacters(num);
	unsigned num2 = 5;
	unsigned pow = 3;
	int res = power2(num2, pow);
	printf("the result of %u * 2^%u = %d\n", num2, pow, res);
	return 0;
}

unsigned packCharacters(char ch1, char ch2) {
	unsigned res = ch1;
	for (int i = 0; i < BYTE; i++) {
		res <<= 1;
	}
	res |= ch2;	
	displayBits(res);
	return res;
}


void unpackCharacters(unsigned num) {
	// num     = 1010 0011 0001 1001
	// bitMask = 1111 1111 0000 0000
	printf("the given num is %u\n", num);
	displayBits(num);
	unsigned bitMask = 65280;
	displayBits(bitMask);
	printf("mask is %u\n", bitMask);
	unsigned ch1 = 0;
	unsigned ch2 = 0;
	ch1 = num & bitMask;
	printf("ch1 is %u\n", ch1);
	num <<= BYTE;
	ch2 = num & bitMask;
	ch2 >>= BYTE;
	printf("ch2 is %u\n", ch2);
	ch1 |= ch2;
	printf("the num retrieve is %u\n", ch1);
	displayBits(ch1);
}

// return num * 2^pow
unsigned power2(unsigned num, unsigned pow) {	
	return num * (1 << pow);
}

void displayBits(unsigned value){
        unsigned c, displayMask = 1 << 15;

        printf("%3c%7u = ", value, value);

        for(c=1; c<=16; c++){
                putchar(value & displayMask ? '1' : '0');
                value <<= 1;

                if (c % 8 == 0){
                        putchar(' ');
                }
        }
        putchar('\n');
}

