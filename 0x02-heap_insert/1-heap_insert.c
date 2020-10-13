#include "binary_trees.h"

/**
 * insert - location to insert new node.
 * @root: this is a pointer.
 * Return: a pointer.
 */
heap_t *insert(heap_t *root)
{
	heap_t *tail[50];
	heap_t *insert = root;
	int s = 0, e = 0;

	while (insert && insert->left && insert->right)
	{
		tail[s] = insert->left;
		s += 1;
		if (s >= 49)
			s = 0;
		tail[s] = insert->right;
		s += 1;
		if (s >= 49)
			s = 0;
		insert = tail[e];
		e += 1;
		if (e >= 49)
			e = 0;
	}

	return (insert);
}

/**
 * heap_insert - insert a value.
 * @root: a double pointer.
 * @value: value to insert.
 * Return: pointer or NULL.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *create, *p;
	int y;

	if (!root)
		return (NULL);

	if (!*root)
	{
		create = binary_tree_node(*root, value);
		*root = create;
		return (create);
	}

	p = insert(*root);
	create = binary_tree_node(p, value);
	if (p->left == NULL)
		p->left = create;
	else
		p->right = create;

	while (create->parent && create->n > create->parent->n)
	{
		y = create->parent->n;
		create->parent->n = create->n;
		create->n = y;
		create = create->parent;
	}
	return (create);
}
