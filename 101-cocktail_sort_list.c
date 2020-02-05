#include "sort.h"

/**
 * swap - Swaps on a doubly linked list
 *
 * @curr: current location of linked list
 * @list: double pointer to list
 *
 * Return: The new pointer
 */
listint_t *swap(listint_t *curr, listint_t **list)
{
	listint_t *node;

	if (curr->prev->prev != NULL)
		curr->prev->prev->next = curr;
	curr->prev->next = curr->next;
	node = curr->prev->prev;
	curr->prev->prev = curr;
	if (curr->next != NULL)
		curr->next->prev = curr->prev;
	curr->next = curr->prev;
	curr->prev = node;
	if (curr->prev == NULL)
		*list = curr;
	return (curr);
}

/**
 * cocktail_sort_list - sort linked list using cocktail sort algo.
 *
 * @list: input linked list
 *
 * Return: Nothing
 */
void cocktail_sort_list(listint_t **list)
{
listint_t *current;
int flag;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	flag = 1;
	current = (*list);
	do {
		flag = 0;
		while (current->next != NULL)
		{

			if (current->n > current->next->n)
			{
				current = swap(current->next, list);
				print_list(*list);
				flag = 1;
			}
			current = current->next;
		}
		current = current->prev;

		while (current->prev != NULL)
		{

			if (current->prev->n > current->n)
			{
				current = swap(current, list);
				print_list(*list);
				flag = 1;
			}
			else if (current->prev != NULL)
				current = current->prev;
		}
		current = current->next;
	} while (flag);
}
