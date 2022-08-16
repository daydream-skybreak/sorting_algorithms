#include "sort.h"
/**
 * swap - swaps two integers
 * @num1: number 1 to be switched
 * @num2: number 2 to be switched
 * Return: void
 */
void swap(int *num1, int *num2)
{
	int tmp;

	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}
/**
 * shell_sort - sorts an array using shell sort algo
 * @array: array to be sorted
 * @size: size of the array
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
		size_t gap, i, j;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
