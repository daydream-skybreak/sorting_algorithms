#include "sort.h"

/**
 * bubble_sort - sorts an array using bubble sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int flag;

	if (array == NULL)
		exit(1);

	for (i = size; i > 0; i--)
	{
		flag = 0;
		for (j = 0; j < i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				array[j] = array[j + 1] + array[j];
				array[j + 1] = array[j] - array[j + 1];
				array[j] = array[j] - array[j + 1];

				print_array(array, size);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}
