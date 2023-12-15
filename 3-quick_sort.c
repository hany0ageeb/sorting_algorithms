#include "sort.h"

long int partition(int *array, long int lo, long int hi, size_t size);
void qsort(int *array, long int lo, long int hi, size_t size);
/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 * @array: array of integers to sort
 * @size: array size
 */
void quick_sort(int *array, size_t size)
{
	qsort(array, 0, (long int)size - 1, size);
}
/**
 * partition - quick sort partition routine
 * @array: array of ints
 * @lo: low index
 * @hi: hi index
 * @size: array size
 * Return: pivot index
 */
long int partition(int *array, long int lo, long int hi, size_t size)
{
	int pivot = array[hi], temp;
	long int i = lo - 1;
	long int j;

	for (j = lo; j <= hi; ++j)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, size);
			}
		}
	}
	i++;
	if (i != hi)
	{
		temp = array[i];
		array[i] = array[hi];
		array[hi] = temp;
		print_array(array, size);
	}
	return (i);
}
/**
 * qsort - sort array using quick sort
 * @array: array of ins to sort
 * @lo: low index
 * @hi: hi index
 * @size: qrray size
 */
void qsort(int *array, long int lo, long int hi, size_t size)
{
	long int p;

	if (lo < hi && hi < (long int)size && lo >= 0 && hi >= 0)
	{
		p = partition(array, lo, hi, size);
		qsort(array, lo, p - 1, size);
		qsort(array, p + 1, hi, size);
	}
}
