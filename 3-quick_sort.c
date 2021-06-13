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
    q_s(array, 0, size - 1, size);
}

/**
 */

void q_s(int *array, int lower, int higher, size_t size)
{
    int pivot = 0;

    print_array(array, size);
    if (lower < higher)
    {
        pivot = division(array, lower, higher);
        q_s(array, lower, pivot - 1, size);
        q_s(array, pivot + 1, higher, size);
    }
}

/**
 */

int division(int *array, int lower, int higher)
{
    int pivot = 0, aux = 0, i = 0, j = lower;

    pivot = array[higher];
    i = lower;
    while (j < higher)
    {
        if (array[j] < pivot)
        {
            aux = array[i];
            array[i] = array[j];
            array[j] = aux;
            i++;
        }
        j++;
    }
    aux = array[i];
    array[i] = array[higher];
    array[higher] = aux;
    return (i);
}
