#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using
 * the Shell sort algorithm, using the Knuth sequence
 * @array: array of integers to sort
 * @size: array size
 */
void shell_sort(int *array, size_t size)
{
	long int i, j, h = 1;
	int temp;

	if (array == NULL || size <= 1)
		return;
	while (h < (long int)(size / 3))
		h = 3 * h + 1;
	while (h > 0)
	{
		for (i = h; i < (long int)size; ++i)
		{
			for (j = i; j >= h && array[j] < array[j - h]; j -= h)
			{
				temp = array[j];
				array[j] = array[j - h];
				array[j - h] = temp;
			}
		}
		h = (h - 1) / 3;
		print_array(array, size);
	}
}
