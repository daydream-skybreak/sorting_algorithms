#include "sort.h"

/**
 * selection_sort - sorts an array based on the selection sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int *low, tmp;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		low = array + i;
		for (j = i + 1; j < size; j++)
			low = (array[j] < *low) ? (array + j) : low;

		if ((array + i) != low)
		{
			tmp = *low;
			*low = *(array + i);
			*(array + i) = tmp;
			print_array(array, size);
		}
	}
}
