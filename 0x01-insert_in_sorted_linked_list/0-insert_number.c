#include "lists.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * insert_node - inserts a node into a sorted linked list
 * @head: it s a double pointer
 * @number: it s an integer
 * Return: address of current node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
listint_t *current = malloc(sizeof(listint_t)), *p;

if (!head || !current)
	return (NULL);
current->next = NULL;
current->n = number;
if (!*head)
{
*head = current;
	return (current);
}
p = *head;
if (p->n > number)
{
current->next = p;
*head = current;
	return (current);
}
while (p->next != NULL && p->next->n < number)
p = p->next;
current->next = p->next;
p->next = current;
	return (current);
}
