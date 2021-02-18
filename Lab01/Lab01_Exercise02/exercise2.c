#include <stdio.h>


#include "random.h"

#define NUM_VALUES 250
long long int values[NUM_VALUES];

int main()
{

	unsigned long long int sum = 0;
	unsigned int average = 0;
	long long int min = 0;
	long long int max = 0;
	unsigned char i = 0;

	init_random();

	for (i = 0; i < NUM_VALUES; i++) {
		values[i] = random_uint();

		sum += values[i];
	}

	average = (unsigned int) (sum / NUM_VALUES);

	for (i = 0; i < NUM_VALUES; i++) {
		values[i] -= average;
		min = (values[i] < min) ? values[i] : min;
		max = (values[i] > max) ? values[i] : max;
	}

	printf("Sum is %llu\n", sum);
	printf("Average is %u\n", average);
	printf("Min is %lld\n", min);
	printf("Max is %lld\n", max);
	return 0;
}