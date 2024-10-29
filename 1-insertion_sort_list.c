#include "sort.h"

/**
 * swapping_num - Swaps two nodes in a doubly linked list
 * @a: First node
 * @b: Second node
 */
void swapping_num(listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	b->prev = a->prev;
	a->next = b->next;
	a->prev = b;
	b->next = a;
}

/**
 * insertion_sort_list - Sorts a doubly linked list using insertion sort
 * @list: Double pointer to the head of the list
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
		while (apres && apres->prev && apres->n < apres->prev->n)
		{
			swapping_num(apres->prev, apres);
			if (!apres->prev)
				*list = apres;
			print_list(*list);
		}
	}
}
