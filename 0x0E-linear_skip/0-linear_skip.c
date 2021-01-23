#include "search.h"
/**
 * linear_skip - serching for a value.
 * @list: this is a pointer.
 * @value: this is an integer.
 * Return: NULL or the pointer.
**/

skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *tmp, *f;

	if (list == NULL)
		return (NULL);
	tmp = list->express;
	f = list;
	while (tmp)
	{
		printf("Value checked at index [%lu] = [%d]\n",
			   tmp->index, tmp->n);
		if (!tmp->express || tmp->n >= value)
		{
			if (!tmp->express && tmp->n < value)
			{
				f = tmp;
				while (tmp->next)
					tmp = tmp->next;
			}
			printf("Value found between indexes [%lu] and [%lu]\n",
				   f->index, tmp->index);
			while (f)
			{
				printf("Value checked at index [%lu] = [%d]\n",
					   f->index, f->n);
				if (f->n == value)
					return (f);
				if (f->n > value)
					return (NULL);
				f = f->next;
			}
			break;
		}
		f = tmp;
		tmp = tmp->express;
	}
	return (NULL);
}
