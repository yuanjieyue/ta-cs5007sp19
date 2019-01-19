#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initialize_arr(int length, int nums[]);
double insertion_sort(int length, int nums[]);
void print_arr(int length, int nums[]);
void swap(int* a, int* b);

int main(void) {
	const int TRIALS = 30, SMALL_ELE_NUM = 30, MED_ELE_NUM = 500, LARGE_ELE_NUM = 3000;
	double small_time, med_time, large_time;
	int small_nums[SMALL_ELE_NUM], med_nums[MED_ELE_NUM], large_nums[LARGE_ELE_NUM]; 
	srand(time(NULL));

	// initialize array
	initialize_arr(SMALL_ELE_NUM, small_nums);
	initialize_arr(MED_ELE_NUM, med_nums);
	initialize_arr(LARGE_ELE_NUM, large_nums);
	
	// compute time
	// print_arr(SMALL_ELE_NUM, small_nums);
	// print result
	small_time = insertion_sort(SMALL_ELE_NUM, small_nums);
	med_time = insertion_sort(MED_ELE_NUM, med_nums);
	large_time = insertion_sort(LARGE_ELE_NUM, large_nums);
	// print_arr(SMALL_ELE_NUM, small_nums);
	printf("-----------------------\n");
	printf("SLOW SORT : INSERTION SORT\n");
	printf("-----------------------\n");	
	printf("Large:\t%d elements\t%f msecs\n", LARGE_ELE_NUM, large_time);
	printf("Med:\t%d elements\t%f msecs\n", MED_ELE_NUM, med_time);
	printf("Small:\t%d elements\t%f msecs\n", SMALL_ELE_NUM, small_time);
	printf("-----------------------\n");	
	return 0;
}

void print_arr(int len, int nums[]) {
	int i;
	for (i = 0; i < len; i++) {
		printf("%d\n", nums[i]);
	}	
}

void initialize_arr(int len, int nums[]) {
	int i;
	for (i = 0; i < len; i++) {
		nums[i] = rand() % len + 1;
	}
}

double insertion_sort(int len, int nums[]) {
	clock_t begin = clock();
	int i, j;
	for (i = 1; i < len; i++) {
		int key = nums[i];
		j = i - 1;
		while (j >= 0 && nums[j] > key) {
			swap(&nums[j], &nums[j + 1]);
			j--;
		}
		nums[j + 1] = key;
	}
	clock_t end = clock();
	double res = (double) (end - begin);
	return res;	
}

void swap (int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
