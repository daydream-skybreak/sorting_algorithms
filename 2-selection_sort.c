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
	int flag;

	if (array == NULL)
		return;

	for (i = 0; i < size - 1; i++)
	{
		flag = 0;

		for (j = i + 1; j < size; j++)
		{
			if ( array[j] < array[i])
			{
				array[j] = array[j] + array[i];
				array[i] = array[j] - array[i];
				array[j] = array[j] - array[i];
				print_array(array, size);
				flag = 1;
			}
		}
		if (flag == 0)
			return;
	}
}
