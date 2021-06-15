#include "sort.h"

/**
 * quick_sort - This function sorts an array of integers in ascending
 * order using the Quick sort algorithm.
 * @array: The set of the integers to sort.
 * @size: The length of the array.
 * Return: Nothing.
 */

void quick_sort(int *array, size_t size)
{
	recursion_quick_sort(array, 0, size - 1, size);
}

/**
 * recursion_quick_sort - This function sort a set the integers.
 * @array: The set of integers to sort.
 * @lower: The lower limit of the array.
 * @upper: The upper limit of the array.
 * @size: The length of the array.
 * Return: Nothing.
 */

void recursion_quick_sort(int *array, int lower, int upper, size_t size)
{
	int pivot = 0;

	if (lower < upper)
	{
		pivot = division(array, lower, upper, size);
		recursion_quick_sort(array, lower, pivot - 1, size);
		recursion_quick_sort(array, pivot + 1, upper, size);
	}
}

/**
 * division - This function returns the position of the pivot number.
 * @array: The set of integers to sort.
 * @lower: The lower limit of the array.
 * @upper: The upper limit of the array.
 * @size: The length of the array.
 * Return: The position of the pivot number.
 */

int division(int *array, int lower, int upper, size_t size)
{
	int pivot = 0, aux = 0, i = 0, j = lower;

	pivot = array[upper];
	i = lower - 1;
	while (j <= upper - 1)
	{
		if (array[j] <= pivot)
		{
			i++;
			aux = array[i];
			array[i] = array[j];
			array[j] = aux;
			if (i != j)
				print_array(array, size);
		}
		j++;
	}
	aux = array[i + 1];
	array[i + 1] = array[upper];
	array[upper] = aux;
	if (i + 1 != j)
		print_array(array, size);
	return (i + 1);
}
