#include "sort.h"

/**
 * merge_sort - This functionsorts an array of integers
 * in ascending order using the Merge sort algorithm.
 * @array: The set of integers to sort.
 * @size: The length of the array.
 * Return: Nothing.
 */

void merge_sort(int *array, size_t size)
{
	int *array_aux = malloc(size * sizeof(int));

	top_down(array, size - size, size - 1, array_aux);
	free(array_aux);
}

/**
 * top_down - This function divides the list in two sub list
 * until that only an element.
 * @array: The set of integers to divide.
 * @start: The first element of the list.
 * @end: The last element of the list.
 * @array_aux: The array to keep the temporary values.
 * Return: Nothing.
 */

void top_down(int *array, int start, int end, int *array_aux)
{
	int mid = 0;

	if (start < end)
	{
		mid = (start + end - 1) / 2;
		top_down(array, start, mid, array_aux);
		top_down(array, mid + 1, end, array_aux);
		merge(array, start, mid, end, array_aux);
	}
}

/**
 * merge - This function merges two sublists in one sorted list.
 * @array: The set of integers to sort.
 * @start: The start of the sublist.
 * @mid: The middle of the sublist.
 * @end: The end of the sublist.
 * @array_aux: The array to keep the temporary values.
 * return: Nothing.
 */

void merge(int *array, int start, int mid, int end, int *array_aux)
{
	int i = start, j = mid + 1, k = 0;

	print_before(array, start, mid, end);
	while (i <= mid && j <= end)
	{
		if (array[i] <= array[j])
		{
			array_aux[k] = array[i];
			k += 1, i += 1;
		}
		else
		{
			array_aux[k] = array[j];
			k += 1, j += 1;
		}
	}
	while (i <= mid)
	{
		array_aux[k] = array[i];
		k += 1, i += 1;
	}
	while (j <= end)
	{
		array_aux[k] = array[j];
		k += 1, j += 1;
	}
	i = start;
	while (i <= end)
	{
		array[i] = array_aux[i - start];
		i++;
	}
	printf("\n");
	print_after(array, start, end);
}

/**
 * print_before - This function prints the right
 * and left elements of the array to sort.
 * @array: The set of integers to sort.
 * @start: The fisrt element of the array.
 * @middle: The middle of the array.
 * @end: The last element of the array.
 * Return: Nothing.
 */
void print_before(int *array, int start, int middle, int end)
{
	char *sep = "", *empty = ", ";
	int i = start;

	printf("Merging...\n");
	printf("[left]: ");
	while (i <= middle)
	{
		printf("%s", sep);
		printf("%d", array[i++]);
		sep = empty;
	}
	printf("\n[right]: ");
	sep = "";
	while (i <= end)
	{
		printf("%s", sep);
		printf("%d", array[i++]);
		sep = empty;
	}
}

/**
 * print_after - This function prints the array after to sort.
 * @array: The set of integers to sort.
 * @start: The fisrt element of the array.
 * @end: The last element of the array.
 * Return: Nothing.
 */

void print_after(int *array, int start, int end)
{
	int i = start;
	char *sep = "", *empty = ", ";

	printf("[Done]: ");
	while (i <= end)
	{
		printf("%s", sep);
		printf("%d", array[i++]);
		sep = empty;
	}
	printf("\n");
}
