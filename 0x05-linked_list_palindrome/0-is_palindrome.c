#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
/**
 * list - length function.
 * @head: this is a pointer.
 * Return: length.
 */
int list(listint_t *head)
{
	listint_t *current = head;
	int i = 0;

	while (current != NULL)
	{
		i++;
		current = current->next;
	}
	return (i);
}
/**
 * inarray - create array from linked list.
 * @head: this is a pointer.
 * @list: this is an array.
 * Return: full array
 */
int *inarray(listint_t *head, int *list)
{
	int n = 0;
	listint_t *current = head;
	int *a = list;

	while (current != NULL)
	{
		a[n] = current->n;
		n++;
		current = current->next;
	}
	return (a);
}
/**
 * is_palindrome - function to check the list. 
 * @head: this is a pointer.
 * Return: 0 if no, 1 if yes
 */
int is_palindrome(listint_t **head)
{
	listint_t *current = *head;
	int i = listlen(current);
	int *l, *a;
	int mid1 = 0, mid2 = 0, y = 0;

	l = (int *)malloc(sizeof(int) * i);
	if (l == NULL)
		return (0);
	if (current == NULL)
		return (1);

	a = inarray(current, l);
	mid1 = i / 2;
	if (i % 2 != 0)
	{
		y = 0;
		for (y = 1; y <= mid1; y++)
		{
			if (a[mid1 + y] != a[mid1 - y])
				return (0);
		}
		return (1);
	}
	if (i % 2 == 0)
	{
		mid2 = mid1 - 1;
		if (a[mid1] != a[mid2])
		{
			return (0);
		}
		y = 0;
		for (y = 1; y < mid1; y++)
		{
			if (a[mid1 + y] != a[mid2 - y])
				return (0);
		}
		return (1);
	}
	return (1);
}