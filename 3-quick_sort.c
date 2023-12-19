#include "sort.h"

/**
 * partition - the array partition function
 * @array: it the array to sort
 * @first: it the first position
 * @last: it the last position
 * @size: it the array size
 * Return: returns pivot index intenger
 */

int partition(int *array, int first, int last, size_t size)
{
	int i = first - 1, aux, j;

	for (j = first; j <= last - 1; j++)
	{
		if (array[j] < array[last])
		{
			i++;
			if (i < j)
			{
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
				print_array(array, size);
			}
		}
	}
	if (array[i + 1] > array[last])
	{
		aux = array[i + 1];
		array[i + 1] = array[last];
		array[last] = aux;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick - sorts the array of the integers recursively
 * @array: it the array to sort
 * @first: it the first position
 * @last: it the last position
 * @size: it the array size
 * Return: nothing/void
 */

void quick(int *array, int first, int last, size_t size)
{
	int pivot;

	if (first < last)
	{
		pivot = partition(array, first, last, size);
		quick(array, first, pivot - 1, size);
		quick(array, pivot + 1, last, size);
	}
}

/**
 * quick_sort - sorts the array of integers using a Quick
 * sort algorithm in the ascending order
 * @array: it the array to sort
 * @size: it the array size
 * Return: nothing/void
 */

void quick_sort(int *array, size_t size)
{
	quick(array, 0, size - 1, size);
}
