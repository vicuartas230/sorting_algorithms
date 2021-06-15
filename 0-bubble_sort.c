#include "sort.h"

/**
 * bubble_sort - This function sorts an array of integers in ascending order
 * using the Bubble sort algorithm.
 * @array: The array to sort.
 * @size: The length of the array to sort.
 * Return: Nothing.
 */

void bubble_sort(int *array, size_t size)
{
	unsigned int i = 0, flag = 1;
	int aux = 0;

	if (!size)
		return;
	while (flag)
	{
		flag = 0;
		i = 0;
		while (i < size - 1)
		{
			if (array[i + 1] < array[i])
			{
				aux = array[i];
				array[i] = array[i + 1];
				array[i + 1] = aux;
				flag = 1;
				print_array(array, size);
			}
			i++;
		}
	}
}
