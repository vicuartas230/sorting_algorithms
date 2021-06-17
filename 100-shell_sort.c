#include "sort.h"

/**
 * shell_sort - This function sorts an array of integers insert ascending order
 * using the Shell sort algorithm, using the Knuth sequence.
 * @array: The set of integers to sort.
 * @size: The length of the array.
 * Return: Nothing.
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, ext = 0, insert = 0;
	int aux = 0;

	if (size < 2)
		return;
	while (gap < size / 3)
		gap = gap * 3 + 1;
	while (gap > 0)
	{
		ext = gap;
		while (ext < size)
		{
			aux = array[ext];
			insert = ext;
			while (insert > gap - 1 && array[insert - gap] >= aux)
			{
				array[insert] = array[insert - gap];
				insert -= gap;
			}
			array[insert] = aux;
			ext++;
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
