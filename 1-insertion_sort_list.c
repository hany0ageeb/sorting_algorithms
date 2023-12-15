#include "sort.h"

/**
 * swap_nodes - swap two nodes a, b in list
 * @list: doubly linked list of ints
 * @a: first node
 * @b: second node
 */
static void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	listint_t *tmp;

	if (a == b || a == NULL || b == NULL)
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
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 * @list: doubly linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node_i, *node_j;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	node_i = (*list)->next;
	while (node_i != NULL)
	{
		node_j = node_i;
		while (node_j->prev != NULL && node_j->n < node_j->prev->n)
		{
			swap_nodes(list, node_j->prev, node_j);
			print_list(*list);
			if (node_i == node_j)
				node_i = node_i->next;
		}
		node_i = node_i->next;
	}
}
