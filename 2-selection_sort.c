#include "sort.h"

/**
 * selection_sort -  sorts an array of integers in ascending order
 * using the Selection sort algorithm
 * @array: array of ints to sort
 * @size: array size
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_j;
	int temp;

	for (i = 0; i < size - 1; ++i)
	{
		min_j = i;
		for (j = i + 1; j < size; ++j)
		{
			if (array[min_j] > array[j])
				min_j = j;
		}
		if (min_j != i)
		{
			temp = array[i];
			array[i] = array[min_j];
			array[min_j] = temp;
			print_array(array, size);
		}
	}
}
