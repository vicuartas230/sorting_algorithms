#include "sort.h"

/**
 * insertion_sort_list - This function sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 * @list: The linked list to sort.
 * Return: Nothing.
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *tmp = *list, *hold = NULL;
	int flag = 0;

	while (tmp->next)
	{
		if (tmp->next->n < tmp->n && tmp == *list && !tmp->next->next)
		{
			*list = tmp->next;
			tmp->prev = *list;
			(*list)->next = tmp;
			(*list)->prev = NULL;
			tmp->next = NULL;
			print_list(*list);
			break;
		}
		if (tmp->next->n < tmp->n && tmp == *list)
			swap_start(list, tmp);
		if (tmp->next->n < tmp->n && tmp->next->next)
		{
			swap_middle(list, tmp);
			tmp = tmp->prev;
		}
		if (tmp->next->n < tmp->n && !tmp->next->next)
		{
			swap_end(list, tmp);
			tmp = tmp->prev;
			if (tmp && tmp->n < tmp->prev->n)
				hold = tmp->next;
			while (tmp && tmp->n < tmp->prev->n)
			{
				flag = 1;
				if (tmp->prev->prev)
				{
					tmp = tmp->prev;
					swap_middle(list, tmp);
				}
				else if (tmp->prev)
				{
					swap(list, tmp);
				}
				tmp = tmp->prev;
			}
			if (flag)
			{
				tmp = hold->prev;
				flag = 0;
			}
		}
		tmp = tmp->next;
	}
}

/**
 * swap_start - This function swaps two nodes at the start of a linked list.
 * @list: The start of the linked list.
 * @tmp: The pointer to node to swap.
 * Return: Nothing
 */

void swap_start(listint_t **list, listint_t *tmp)
{
	listint_t *tmp2 = NULL;

	tmp2 = tmp->next;
	*list = tmp2;
	tmp->next = tmp2->next;
	tmp->prev = tmp2;
	tmp2->next->prev = tmp;
	tmp2->next = tmp;
	tmp2->prev = NULL;
	print_list(*list);
}

/**
 * swap_middle - This function swaps two nodes at the middle of a linked list.
 * @list: The start of the linked list.
 * @tmp: The pointer to node to swap.
 * Return: Nothing
 */

void swap_middle(listint_t **list, listint_t *tmp)
{
	listint_t *tmp2 = tmp->next, *hold = NULL;
	int flag = 0;

	tmp->next = tmp2->next;
	tmp->next->prev = tmp;
	tmp2->next = tmp;
	tmp2->prev = tmp->prev;
	tmp->prev = tmp2;
	tmp2->prev->next = tmp2;
	print_list(*list);
	tmp = tmp->prev;
	if (tmp && tmp->n < tmp->prev->n)
		hold = tmp->next;
	while (tmp && tmp->n < tmp->prev->n)
	{
		flag = 1;
		if (tmp->prev->prev)
		{
			tmp = tmp->prev;
			tmp->next = tmp2->next;
			tmp->next->prev = tmp;
			tmp2->next = tmp;
			tmp2->prev = tmp->prev;
			tmp->prev = tmp2;
			tmp2->prev->next = tmp2;
			print_list(*list);
		}
		else if (tmp->prev)
		{
			swap(list, tmp);
		}
		tmp = tmp->prev;
	}
	if (flag)
	{
		tmp = hold->prev;
		flag = 0;
	}
}

/**
 * swap_end - This function swaps two nodes at the end of a linked list.
 * @list: The start of the linked list.
 * @tmp: The pointer to node to swap.
 * Return: Nothing
 */

void swap_end(listint_t **list, listint_t *tmp)
{
	listint_t *tmp2 = NULL;

	tmp2 = tmp->next;
	tmp2->next = tmp;
	tmp2->prev = tmp->prev;
	tmp2->prev->next = tmp2;
	tmp->prev = tmp2;
	tmp->next = NULL;
	tmp = tmp->prev;
	print_list(*list);
}

/**
 * swap - This function swaps two nodes with the head.
 * @list: The start of the linked list.
 * @tmp: The pointer to node to swap.
 * Return: Nothing
 */

void swap(listint_t **list, listint_t *tmp)
{
	tmp->next->prev = *list;
	(*list)->next = tmp->next;
	(*list)->prev = tmp;
	tmp->next = *list;
	tmp->prev = NULL;
	*list = tmp;
	print_list(*list);
}
