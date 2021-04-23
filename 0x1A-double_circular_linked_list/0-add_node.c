#include "list.h"

/**
 * one - function to add one node.
 * @list: this is a linked list.
 * @str: this is a string.
 * Return: NULL or node
 */

List *one(List **list, char *str)
{
	List *n;

	n = malloc(sizeof(list));
	if (n == NULL)
		return (NULL);

	n->str = strdup(str);
	if (n->str == NULL)
	{
		free(str);
		return (NULL);
	}

	n->next = n;
	n->prev = n;
	*list = n;

	return (n);
}

/**
 * add_node_begin - function that add a node.
 * @list: this is a linked list.
 * @str: this is a string.
 * Return: NULL or node.
 */
List *add_node_begin(List **list, char *str)
{
	List *n, *tmp, *m;

	if (list == NULL)
		return (NULL);

	if (*list == NULL)
		return one(list, str);

	m = *list;
	n = malloc(sizeof(List));

	if (n == NULL)
		return (NULL);

	n->str = strdup(str);
	if (n->str == NULL)
	{
		free(n);
		return (NULL);
	}

	n->next = m;
	n->prev = m->prev;
	tmp = m->prev;
	m->prev = n;
	tmp->next = n;
	*list = n;

	return (n);
}

/**
 * add_node_end - function to add a node.
 * @list: this is a linked list.
 * @str: this is a string.
 * Return: NULL or node.
 */

List *add_node_end(List **list, char *str)
{
	List *n, *tmp, *m;

	if (list == NULL)
		return (NULL);

	if (*list == NULL)
		return one(list, str);

	m = *list;
	n = malloc(sizeof(List));

	if (n == NULL)
		return (NULL);
	n->str = strdup(str);
	if (n->str == NULL)
	{
		free(n);
		return (NULL);
	}
	n->next = m;
	n->prev = m->prev;
	tmp = m->prev;
	m->prev = n;
	tmp->next = n;

	return (n);
}
