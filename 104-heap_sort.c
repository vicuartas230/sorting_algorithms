#include "sort.h"

/**
 * heap_sort - This function sorts an array of integers in
 * ascending order using the Heap sort algorithm.
 * @array: The set of integers to sort.
 * @size: The length of the array.
 * Return: Nothing.
 */

void heap_sort(int *array, size_t size)
{
	int end = 0, aux = 0;

	if (size < 2)
		return;
	heapify(array, size);
	end = size - 1;
	while (end > 0)
	{
	aux = array[end];
	array[end] = array[0];
	array[0] = aux;
	print_array(array, size);
	end--;
	sift_down(array, 0, end, size);
	}
}

/**
 * heapify - This function find largest among root, left
 * child and right child.
 * @array: The set of integers to sort.
 * @size: The length of the array.
 * Return: Nothing.
 */

void heapify(int *array, size_t size)
{
	int start = (size - 2) / 2;

	while (start >= 0)
	{
	sift_down(array, start, size - 1, size);
	start--;
	}
}

/**
 * sift_down - This function does swap between
 * the parent and the last element of the array.
 * @array: The set of integers to sort.
 * @start: The first position of the array.
 * @end: The final position of the array.
 * @size: The length of the array.
 * Return: Nothing.
 */

void sift_down(int *array, int start, int end, size_t size)
{
	int root = start, child = 0, aux = 0;

	while (root * 2 + 1 <= end)
	{
	child = root * 2 + 1;
	if (child + 1 <= end && array[child] < array[child + 1])
		child++;
	if (array[root] < array[child])
	{
		aux = array[root];
		array[root] = array[child];
		array[child] = aux;
		root = child;
		print_array(array, size);
	}
	else
		return;
	}
}
