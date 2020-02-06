#include "sort.h"

/**
  * counting_sort - implementation.
  * @array: to sort
  * @size: of the array
  * Return: void
  */

void counting_sort(int *array, size_t size)
{
	int *counter, *tmp; /*aux arrays*/
	int i, max = INT_MIN; /*Index for cicles && Max value in the array*/

	if (size <= 1)
		return;

	for (i = 0; i < (int) size; i++) /*get max value in the array*/
	{
		if (max < array[i])
			max = array[i];
	}

	counter = malloc(sizeof(int) * (max + 1));
	tmp = malloc(sizeof(int) * size);

	if (!counter || !tmp)
		return;

	for (i = 0; i < max; i++) /*Set array to 0*/
		counter[i] = 0;

	for (i = 0; i < (int) size; i++) /*Count the value; add 1 in counter arr*/
		counter[array[i]] += 1;

	for (i = 1; i < (max + 1); i++) /*Add prev value to current*/
		counter[i] += counter[i - 1];

	print_array(counter, (max + 1));

	for (i = 0; i < (int) size; i++) /*for every item in unsorted*/
	{
		tmp[counter[array[i]] - 1] = array[i]; /*set pos of counter with sum*/
		counter[array[i]] -= 1; /*decrement value in counter*/
	}

	for (i = 0; i < (int) size; i++) /*copy sorted array -> original array*/
		array[i] = tmp[i];
	free(counter); /*Because... valgrind*/
	free(tmp);
}
