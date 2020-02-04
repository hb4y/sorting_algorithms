#include "sort.h"

/**
 * swap - Function that swap two values using bitwise
 * @x: First value
 * @y: Second value
 *
 * Return: Nothing
 */
void swap(int *x, int *y)
{
int t = *x;

	*x = *y;
	*y = t;
}

/**
 * partition - Creates array with values less than the pivot before and greater
 *             than after.
 * @array: The array
 * @size: The size of the array
 * @low: The low limit for iteration
 * @high: The high limit for interation
 *
 * Return: The partition index
 */
size_t partition(int *array, size_t size, int low, int high)
{
int pivot = array[high];
int i = (low - 1);
int j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			if (array[i] != array[j])
				print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	if (array[i + 1] != array[high])
		print_array(array, size);
	return (i + 1);
}

/**
 * _quick_sort - The inner quicksort function.
 * @array: The array
 * @size: The size of the array
 * @low: The low limit for iteration
 * @high: The high limit for interation
 *
 * Return: Nothing
 */
void _quick_sort(int *array, size_t size, int low, int high)
{
size_t pi;

	if (low < high)
	{
		pi = partition(array, size, low, high);

		_quick_sort(array, size, low, pi - 1);
		_quick_sort(array, size, pi + 1, high);
	}
}

/**
 * quick_sort - Sorts an array in ascending order using the Quick sort algo.
 * @array: The array
 * @size: The size of the array
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	_quick_sort(array, size, 0, size - 1);
}
