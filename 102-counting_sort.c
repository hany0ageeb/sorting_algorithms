#include "sort.h"
#include <stdlib.h>
/**
 * max - find max element if array
 * @array: array of integers
 * @size: array size
 * Return: maximum element in array
 */
int max(int *array, size_t size)
{
	int val = array[0];
	size_t i;

	for (i = 1; i < size; ++i)
		if (val < array[i])
			val = array[i];
	return (val);
}
/**
 * init_array - initialize array element to value
 * @array: array
 * @size: size
 * @value: init value
 */
void init_array(int *array, size_t size, int value)
{
	size_t i;

	for (i = 0; i < size; ++i)
		array[i] = value;
}
/**
 * counting_sort - sorts an array of integers in ascending order
 * using the Counting sort algorithm
 * @array: integer array
 * @size: array size
 */
void counting_sort(int *array, size_t size)
{
	int k, j;
	int *output_array = NULL;
	int *count_array = NULL;
	size_t i;

	if (array == NULL || size <= 1)
	{
		free(count_array);
		return;
	}
	k = max(array, size);
	count_array = malloc(sizeof(int) * (k + 1));
	if (count_array == NULL)
		return;
	output_array = malloc(sizeof(int) * size);
	if (output_array == NULL)
	{
		if (count_array != NULL)
			free(count_array);
		return;
	}
	init_array(count_array, k + 1, 0);
	for (i = 0; i < size; ++i)
		count_array[array[i]]++;
	for (j = 1; j <= k; ++j)
		count_array[j] += count_array[j - 1];
	print_array(count_array, k + 1);
	for (j = (long int)size - 1; j >= 0; --j)
	{
		output_array[count_array[array[j]] - 1] = array[j];
		count_array[array[j]]--;
	}
	for (i = 0; i < size; ++i)
		array[i] = output_array[i];
	free(output_array);
	free(count_array);
}
