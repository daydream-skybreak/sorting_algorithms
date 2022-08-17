#include "sort.h"
void swap(int *a, int *b);
int partition(int *array, int low, int high, size_t size);
void sort(int *array, int low, int high, size_t size);
void quick_sort(int *array, size_t size);

/**
 * swap - swaps two integers
 * @a: pointer to number one
 * @b: pointer to number two
 * Return: void
 */

void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - partitions an array into two using a pivot element
 * @array: array to be partitioned
 * @low: starting index of the subset to be partitioned
 * @high: final index of the subset to be partitioned
 * @size: size of the array
 * Return: index to pivot
 */

int partition(int *array, int low, int high, size_t size)
{
	int *pivot, above, below;

	pivot = array + high;
	for (above = below = low; below < high; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swap(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swap(array + above, pivot);
		print_array(array, size);
	}
	return (above);
}

/**
 * sort - sorts array in an ascending order
 * @array: array to be sorted
 * @low: lower index of the subset
 * @high: higher index of the subset
 * @size: size of the array
 * Return: void
 */

void sort(int *array, int low, int high, size_t size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		sort(array, 0, pivot - 1, size);
		sort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array in a quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	sort(array, 0, size - 1, size);
}
