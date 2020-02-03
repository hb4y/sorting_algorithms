#include "sort.h"

/**
  * selection_sort - implementation.
  * @array: to sort
  * @size: of the array
  * Return: void
  */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int aux;

	if (size <= 1)
		return;

	for (i = 0; i < size; i++)
	{
		aux = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[aux])
				aux = j;
		}

		if (aux != (int) i)
		{
			array[aux] = array[aux] ^ array[i];
			array[i] = array[i] ^ array[aux];
			array[aux] = array[aux] ^ array[i];
			print_array(array, size);
		}
	}
}
