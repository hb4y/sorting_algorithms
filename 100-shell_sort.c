#include "sort.h"

/**
  * shell_sort - implementation.
  * @array: to sort
  * @size: of the array
  * Return: void
  */

void shell_sort(int *array, size_t size)
{
	size_t i, j;
	size_t gap = 1;
	int tmp;

	if (size <= 1)
		return;

	while (gap <= (size / 3))	/*Initial gap*/
		gap = 3 * gap + 1;

	while (gap >= 1)
	{
		for (i = gap; i < size; i++)
		{
			tmp = array[i];
			for (j = i; j > gap - 1 && array[j - gap] >= tmp; j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = tmp;
		}
		gap = (gap - 1) / 3;		/*Backwards gap*/
		print_array(array, size);
	}
}
