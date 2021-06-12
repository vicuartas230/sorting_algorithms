#include "sort.h"

/**
 * insertion_sort_list - This function sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm.
 * @list: The linked list to sort.
 * Return: Nothing.
 */

void insertion_sort_list(listint_t **list)
{
    listint_t *tmp = *list, *tmp2 = NULL, *hold = NULL;
    int flag = 0;

    while (tmp->next)
    {
        if (tmp->next->n < tmp->n && tmp == *list)
        {
            tmp2 = tmp->next;
            *list = tmp2;
            tmp->next = tmp2->next;
            tmp->prev = tmp2;
            tmp2->next->prev = tmp;
            tmp2->next = tmp;
            tmp2->prev = NULL;
            print_list(*list);
        }
        if (tmp->next->n < tmp->n && tmp->next->next)
        {
            tmp2 = tmp->next;
            tmp->next = tmp2->next;
            tmp->next->prev = tmp;
            tmp2->next = tmp;
            tmp2->prev = tmp->prev;
            tmp->prev = tmp2;
            tmp2->prev->next = tmp2;
            tmp = tmp->prev;
            print_list(*list);
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
                    tmp->next->prev = *list;
                    (*list)->next = tmp->next;
                    (*list)->prev = tmp;
                    tmp->next = *list;
                    tmp->prev = NULL;
                    *list = tmp;
                    print_list(*list);
                }
                tmp = tmp->prev;
            }
            if (flag)
            {
                tmp = hold->prev;
                flag = 0;
            }
        }
        if (tmp->next->n < tmp->n && !tmp->next->next)
        {
            tmp2 = tmp->next;
            tmp2->next = tmp;
            tmp2->prev = tmp->prev;
            tmp2->prev->next = tmp2;
            tmp->prev = tmp2;
            tmp->next = NULL;
            tmp = tmp->prev;
            print_list(*list);
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
                    tmp->next->prev = *list;
                    (*list)->next = tmp->next;
                    (*list)->prev = tmp;
                    tmp->next = *list;
                    tmp->prev = NULL;
                    *list = tmp;
                    print_list(*list);
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
