#include "sort.h"

/**
 * swap_nodes - swap two nodes a, b in list
 * @list: doubly linked list of ints
 * @a: first node
 * @b: second node
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	listint_t *tmp;

	if (b == a || a == NULL || b == NULL || list == NULL || *list == NULL)
		return;
	if ((*list) == a)
		*list = b;
	else if ((*list) == b)
		*list = a;
	tmp = a->next;
	a->next = b->next;
	b->next = tmp;
	if (a->next != NULL)
		a->next->prev = a;
	if (b->next != NULL)
		b->next->prev = b;
	tmp = a->prev;
	a->prev = b->prev;
	b->prev = tmp;
	if (a->prev != NULL)
		a->prev->next = a;
	if (b->prev != NULL)
		b->prev->next = b;
}
/**
 * cocktail_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Cocktail shaker sort algorithm
 * @list: doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = TRUE;
	listint_t *start = *list, *end = *list;
	listint_t *node_i;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (end->next != NULL)
		end = end->next;
	while (swapped && start != NULL)
	{
		node_i = start;
		while (node_i != NULL && node_i != end)
		{
			if (node_i->n > node_i->next->n)
			{
				swap_nodes(list, node_i, node_i->next);
				swapped = TRUE;
			}
			node_i = node_i->next;
		}
		if (!swapped)
			break;
		swapped = FALSE;
		if (end != NULL)
			end = end->prev;
		if (end != NULL)
			node_i = end->prev;
		else
			node_i = NULL;
		while (node_i != NULL && node_i != start)
		{
			if (node_i->next != NULL && node_i->n > node_i->next->n)
			{
				swap_nodes(list, node_i, node_i->next);
				swapped = TRUE;
			}
			node_i = node_i->prev;
		}
		start = start->next;
	}
}
