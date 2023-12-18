#include "sort.h"

void heapify(int *array, long int root, long int end, size_t size);
void swap(int *a, int *b);
/**
 * heap_sort - sorts an array of integers in ascending order
 * using the Heap sort algorithm
 * @array: array of integeres
 * @size: array size
 */
void heap_sort(int *array, size_t size)
{
	long int root, i;

	if (array == NULL || size <= 1)
		return;
	for (root = (long int)size / 2 - 1; root >= 0; --root)
		heapify(array, root, (long int)size, size);
	for (i = (long int)size - 1; i >= 0; --i)
	{
		if (array[0] != array[i])
		{
			swap(&array[0], &array[i]);
			print_array(array, size);
			heapify(array, 0, i, size);
		}
	}
}
/**
 * swap - swap two integere a with b
 * @a: first element
 * @b: second element
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}
/**
 * heapify - Build the heap in array a so that largest value is at the root
 * @array: array of integers
 * @root: root index
 * @end: end index exclusive
 * @size: array size
 */
void heapify(int *array, long int root, long int end, size_t size)
{
	long int left = 2 * root + 1;
	long int right = 2 * root + 2;
	long int largest = root;

	if (left < end && array[left] > array[largest])
		largest = left;
	if (right < end && array[right] > array[largest])
		largest = right;
	if (largest != root && array[root] != array[largest])
	{
		swap(&array[root], &array[largest]);
		print_array(array, size);
		heapify(array, largest, end, size);
	}
}
