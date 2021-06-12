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
	size_t i = 0, j = 0;
	int hold = array[0], aux = 0, flag = 0;

	while (i < size)
	{
		j = i;
		hold = array[i];
		while (j < size)
		{
			if (array[j] < hold)
			{
				flag = 1;
				aux = hold;
				hold = array[j];
				array[j] = aux;
			}
			j++;
		}
		array[i] = hold;
		if (flag)
		{
			print_array(array, size);
			flag = 0;
		}
		i++;
	}
}
