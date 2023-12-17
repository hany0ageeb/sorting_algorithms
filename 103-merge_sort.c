#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

void msort(int *array, long int lo, long int hi, int *temp_array);
void merge(int *array, long int lo, long int hi, long int mid,
		int *temp_array);
/**
 * merge_sort - sorts an array of integers in ascending
 * order using the Merge sort algorithm
 * @array: array of integers to sort
 * @size: size of array
 */
void merge_sort(int *array, size_t size)
{
	int *temp_array = malloc(sizeof(int) * size);

	if (temp_array == NULL)
		return;
	msort(array, 0, size - 1, temp_array);
	free(temp_array);
}
/**
 * msort - sorts an array using top down merge sort
 * @array: array to sort
 * @lo: low index
 * @hi: high index
 * @temp_array: temprary working array
 */
void msort(int *array, long int lo, long int hi, int *temp_array)
{
	long int mid;

	if (lo < hi)
	{
		mid = lo + (hi - lo) / 2;
		if (mid > 0 && mid - lo > hi - (mid + 1))
			mid--;
		msort(array, lo, mid, temp_array);
		msort(array, mid + 1, hi, temp_array);
		merge(array, lo, hi, mid, temp_array);
	}
}
/**
 * merge - merge sorted arrays into one large array
 * @array: array of integers to sort
 * @lo: low index
 * @mid: middle index
 * @hi: high index
 * @temp_array: temprary array
 */
void merge(int *array, long int lo, long int hi, long int mid, int *temp_array)
{
	long int i, j, k, temp;
	long int n1 = mid - lo + 1;
	long int n2 = n1 + (hi - mid);

	printf("Merging...\n");
	printf("[left]: ");
	for (i = 0; i < n1; ++i)
	{
		temp_array[i] = array[lo + i];
		if (i < (n1 - 1))
			printf("%d, ", temp_array[i]);
		else
			printf("%d\n", temp_array[i]);
	}
	printf("[right]: ");
	for (j = n1, temp = 1; j < n2; ++j, ++temp)
	{
		temp_array[j] = array[mid + temp];
		if (j < (n2 - 1))
			printf("%d, ", temp_array[j]);
		else
			printf("%d\n", temp_array[j]);
	}
	printf("[Done]: ");
	for (k = lo, i = 0, j = n1; i < n1 && j < n2; k++)
	{
		if (temp_array[i] <= temp_array[j])
		{
			array[k] = temp_array[i];
			i++;
		}
		else
		{
			array[k] = temp_array[j];
			j++;
		}
		if (k < hi)
			printf("%d, ", array[k]);
		else
			printf("%d\n", array[k]);
	}
	for (; i < n1; ++i, ++k)
	{
		array[k] = temp_array[i];
		if (k < hi)
			printf("%d, ", array[k]);
		else
			printf("%d\n", array[k]);
	}
	for (; j < n2; ++j, ++k)
	{
		array[k] = temp_array[j];
		if (k < hi)
			printf("%d, ", array[k]);
		else
			printf("%d\n", array[k]);
	}
}
