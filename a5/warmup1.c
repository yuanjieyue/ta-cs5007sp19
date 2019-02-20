#include <stdlib.h>
#include <stdio.h>



#define SIZE (8) /* amount of bits */
#define ARRAY_SIZE(x) (x/8+(!!(x%8)))
 
char get_bit(char *array, int index);

void toggle_bit(char *array, int index);

void toggle_bit(char *array, int index) {
    array[index / 8] ^= 1 << (index % 8);
}
 
char get_bit(char *array, int index) {
    return 1 & (array[index / 8] >> (index % 8));
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


int main(void) {
    /* initialize empty array with the right size */
    char x[ARRAY_SIZE(SIZE)] = { 0 };

    int i;
 
    toggle_bit(x, 3); 
    toggle_bit(x, 4);
    toggle_bit(x, 6);
    toggle_bit(x, 7);

    char* out = "00011011"; 

    for (i=0; i<8; i++){
    	printf("%d\n",(out[i] >> i));
    }

    printf("\n\n"); 	

	displayBits('B');
	displayBits('i');	
	displayBits('k');

 
    return 0;
}
