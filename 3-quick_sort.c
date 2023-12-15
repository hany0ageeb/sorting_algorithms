#include "sort.h"

size_t partition(int *array, size_t lo, size_t hi, size_t size);
void qsort(int *array, size_t lo, size_t hi, size_t size);
/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array of integers to sort
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
	qsort(array, 0, size - 1, size);
}
/**
 * partition - quick sort partition routine
 * @array: array of ints
 * @lo: low index
 * @hi: hi index
 * @size: array size
 * Return: pivot index
 */
size_t partition(int *array, size_t lo, size_t hi, size_t size)
{
	int pivot = array[hi], temp;
	long int i = (long int)lo - 1;
	size_t j;

	for (j = lo; j <= hi; ++j)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != (long int)j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	i++;
	if (i != (long int)hi)
	{
		temp = array[i];
		array[i] = array[hi];
		array[hi] = temp;
		print_array(array, size);
	}
	return ((size_t)i);
}
/**
 * qsort - sort array using quick sort
 * @array: array of ins to sort
 * @lo: low index
 * @hi: hi index
 * @size: qrray size
 */
void qsort(int *array, size_t lo, size_t hi, size_t size)
{
	size_t p;

	if (lo < hi)
	{
		p = partition(array, lo, hi, size);
		if (p > 0)
			qsort(array, lo, p - 1, size);
		if (p < hi)
			qsort(array, p + 1, hi, size);
	}
}
