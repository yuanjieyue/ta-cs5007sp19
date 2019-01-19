#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initialize_arr(int len, int nums[]);
double quick_sort(int len, int nums[]);
void print_arr(int len, int nums[]);
void swap(int* a, int*b);
void sort(int len, int nums[], int p, int r);
int partition(int len, int nums[], int p, int r);
void print_arr(int len, int nums[]);

int main(void) {
	int SMALL_ELE_NUM = 30, MED_ELE_NUM = 500, LARGE_ELE_NUM = 3000;
	double small_time, med_time, large_time;
	
	int small_nums[SMALL_ELE_NUM], med_nums[MED_ELE_NUM], large_nums[LARGE_ELE_NUM];
	srand(time(NULL));	
	// initialize the arrays
	initialize_arr(SMALL_ELE_NUM, small_nums);
	initialize_arr(MED_ELE_NUM, med_nums);
	initialize_arr(LARGE_ELE_NUM, large_nums);

	// compute times
	small_time = quick_sort(SMALL_ELE_NUM, small_nums);
	med_time = quick_sort(MED_ELE_NUM, med_nums);
	large_time = quick_sort(LARGE_ELE_NUM, large_nums);
	
	// print the result	
	printf("----------------------\n");	
	printf("FAST SORT : QUICK SORT\n");	
	printf("----------------------\n");	
	printf("Large:\t%d elements\t%f msecs\n", LARGE_ELE_NUM, large_time);	
	printf("Med:\t%d elements\t%f msecs\n", MED_ELE_NUM, med_time);
	printf("Small:\t%d elements\t%f msecs\n", SMALL_ELE_NUM, small_time);
	printf("----------------------\n");	
	return 0;
} 
void print_arr(int len, int nums[]) {

	int i;
	for (i = 0; i < len; i++) {
		printf("%d\n", nums[i]);
	}
}


double quick_sort(int len, int nums[]) {
	clock_t begin = clock();
	sort(len, nums, 0, len - 1);
	clock_t end = clock();
	double res = (double) (end - begin);
	return res;
}
void sort(int len, int nums[], int p, int r) {
	if (p < r) {
		int q = partition(len, nums, p, r);
		sort(len, nums, p, q - 1);
		sort(len, nums, q + 1, r);
	}	
}
int partition(int len, int nums[], int p, int r) {
	int pivot = nums[r];
	int i = p - 1, j;
	for (j = p; j < r; j++) {
		if (nums[j] <= pivot) {
			i++;
			swap(&nums[j], &nums[i]);
		}
	}
	swap(&nums[i + 1], &nums[r]);
	return i + 1;
}

void initialize_arr(int len, int nums[]) {
	int i;	
	for (i = 0; i < len; i++) {
		nums[i] = rand() % len + 1;
	}
}

void swap (int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

