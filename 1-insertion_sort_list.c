#include "sort.h"

/**
 * swapping_num - func
 * @a: inputs
 * @b: in
*/

void swapping_num(listint_t *a, listint_t *b)
{
    listint_t *temp_prev = a->prev;
    listint_t *temp_next = a->next;

    a->prev = b->prev;
    a->next = b->next;

    b->prev = temp_prev;
    b->next = temp_next;

    if (a->prev)
        a->prev->next = a;
    else
        a->prev = a;

    if (a->next)
        a->next->prev = a;

    if (b->prev)
        b->prev->next = b;
    else
        b->prev = b;

    if (b->next)
        b->next->prev = b;
}

/**
 * insertion_sort_list - func
 * @list: inputs
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *avant, *apres;

	if (!list || !*list || !(*list)->next)
		return;

	avant = (*list)->next;
	while (avant)
	{
		apres = avant;
		avant = avant->next;
		while (apres && apres->prev)
		{
			if (apres->prev->n > apres->n)
			{
				swapping_num(apres->prev, apres);
				if (apres->prev)
					*list = apres;
			}
			else
			{
				apres = apres->prev;
			}
		}

	}

}

