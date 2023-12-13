#include "sort.h"

/**
 * swap - swap values of array at i, j indeces
 * @array: array of ints
 * @i: first element index
 * @j: second element index
 */
static void swap(int *array, int i, int j)
{
	int temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}
/**
 * bubble_sort -  sorts an array of integers
 * in ascending order using the Bubble sort algorithm
 * @array: an array of length size to sort
 * @size: length of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int swapped;

	for (i = 0; i < size; ++i)
	{
		swapped = FALSE;
		for (j = 0; j < size - i - 1; ++j)
		{
			if (array[j] > array[j + 1])
			{
				swap(array, j, j + 1);
				swapped = TRUE;
				print_array(array, size);
			}
		}
		if (!swapped)
			break;
	}
}
