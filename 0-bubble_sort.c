#include "sort.h"

/**
  * bubble_sort - implementation.
  * @array: to sort
  * @size: of the array
  * Return: void
  */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;

	if (size <= 1)
		return;

	for (j = size; j > 0; j--)
	{
		for (i = 1; i < j; i++)
		{
			if (array[i - 1] > array[i])
			{
				array[i - 1] = array[i - 1] ^ array[i];
				array[i] = array[i] ^ array[i - 1];
				array[i - 1] = array[i - 1] ^ array[i];
				print_array(array, size);
			}
		}
	}
}
