#include "sort.h"

/**
 * swapping_num - func
 * @a: inputs
 * @b: in
*/

void swapping_num(listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
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

