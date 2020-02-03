#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list using the Insertion sort.
 *
 * @list: The head of the doubly linked list
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
listint_t *curr, *node, *prev;

	if (list == NULL && *list == NULL)		/* if empty */
		return;

	curr = (*list)->next;					/* at least two nodes in list */
	while (curr != NULL)
	{
		prev = curr->prev;
		node = curr;						/* inner evaluation for swapping */
		while (prev != NULL && prev->n > node->n)
		{
			if (prev == *list)				/* when new head */
				*list = node;
			if (prev->prev != NULL)			/* controling head edge */
				prev->prev->next = node;
			prev->next = node->next;
			node->prev = prev->prev;
			prev->prev = node;
			if (node->next != NULL)			/* controling tail edge */
				node->next->prev = prev;
			node->next = prev;
			prev = node->prev;
			print_list(*list);
		}
		curr = curr->next;
	}
}
