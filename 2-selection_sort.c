#include "sort.h"

/**
 * selection_sort - This function sorts an array of integers in
 * ascending order using the Selection sort algorithm.
 * @array: The set of integers to sort.
 * @size: The length of the array.
 * Return: Nothing.
 */

void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, hold = 0, aux = 0;

	while (i < size - 1)
	{
		hold = i;
		j = i + 1;
		while (j < size)
		{
			if (array[j] < array[hold])
			{
				hold = j;
			}
			j++;
		}
		if (hold != i)
		{
			aux = array[i];
			array[i] = array[hold];
			array[hold] = aux;
			print_array(array, size);
		}
		i++;
	}
}
