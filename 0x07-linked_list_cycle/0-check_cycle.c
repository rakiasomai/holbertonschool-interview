#include "lists.h"
#include <stdio.h>

/**
 * check_cycle - to check if the singly linked list has a cycle.
 * @list: head of the list.
 * Return: 1 OR 0.
 **/

int check_cycle(listint_t *list)
{
	listint_t *first, *second;

	if (list == NULL || list->next == NULL)
		return (0);

	first = list->next;
	second = list->next->next;

	while (first && second && second->next)
	{
		if (first == second->next)
		{
			return (1);
		}
		first = first->next;
		second = second->next->next;
	}
	return (0);
}
