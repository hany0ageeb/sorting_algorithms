#include "sort.h"
#include <stdlib.h>

int get_max(int *array, size_t size);
void count_sort(int *array, int exp, size_t size, int *output);
/**
 * radix_sort - sorts an array of integers in ascending order
 * using the Radix sort algorithm
 * @array: array of integers
 * @size: array size
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;
	int *output = NULL;

	if (array == NULL || size <= 1)
		return;
	output = malloc(sizeof(int) * (size + 1));
	if (output == NULL)
		return;
	max = get_max(array, size);
	for (exp = 1; max / exp > 0; exp *= 10)
		count_sort(array, exp, size, output);
	free(output);
}
/**
 * get_max - get maximum item in array
 * @array: array of integers
 * @size: array size
 * Return: maximum integer in array
 */
int get_max(int *array, size_t size)
{
	size_t i;
	int max = 0;

	if (array == NULL || size == 0)
		return (0);
	max = array[0];
	for (i = 1; i < size; ++i)
		if (array[i] > max)
			max = array[i];
	return (max);
}
/**
 * count_sort - count sort array
 * @array: array of ints
 * @exp: exp
 * @output: output array
 * @size: size of array
 */
void count_sort(int *array, int exp, size_t size, int *output)
{
	int *count = NULL;
	size_t i;
	size_t max = (array[0] / exp) % 10;

	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return;
	for (i = 0; i < max; ++i)
		count[i] = 0;
	for (i = 0; i < size; ++i)
		count[(array[i] / exp) % 10]++;
	for (i = size - 1; i > 0; --i)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}
	output[count[(array[i] / exp) % 10] - 1] = array[i];
	count[(array[i] / exp) % 10]--;
	for (i = 0; i < size; ++i)
		array[i] = output[i];
	free(count);
}
