#include "binary_trees.h"
/**
* heap_insert - Inserts a value into a Max Binary Heap.
* @root: Double pointer to the root node of the Heap.
* @value: Value to store in the node to be inserted.
* Return: Pointer to the inserted node, or NULL on failure.
*/
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *create = NULL;
	int ch;

	if (!root)
		return (NULL);
	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	else
	{
		create = insert_last(*root, value);
		if (!create)
			return (NULL);
	}
	while (create->parent && create->parent->n < create->n)
	{
		ch = create->n;
		create->n = create->parent->n;
		create->parent->n = ch;
		create = create->parent;
	}
	return (create);
}
/**
* push - Pushes a value into the queue.
* @last: Last element of queue.
* @node: Node to insert.
* Return: Node inserted or NULL if failed.
*/
queue *push(queue *last, heap_t *node)
{
	queue *create = malloc(sizeof(queue));

	if (!create)
		return (NULL);

	create->node = node;
	create->next = NULL;

	if (last)
		last->next = create;
	return (create);

}

/**
* insert_last - Inserts in the last free position of a heap.
* @root: Root of the heap.
* @value: Value of new node.
* Return: Pointer to new node inserted or NULL on failure.
*/

heap_t *insert_last(heap_t *root, int value)
{
	queue *q, *last, *temp;
	heap_t *create = NULL;

	q = push(NULL, root);
	if (!q)
		return (NULL);
	last = q;
	while (q)
	{
		if (create)
		{
			temp = q;
			q = q->next;
			free(temp);
		}
		else if (q->node->left && q->node->right)
		{
			last = push(last, q->node->left);
			if (!last)
				return (NULL);
			last = push(last, q->node->right);
			if (!last)
				return (NULL);
			temp = q;
			q = q->next;
			free(temp);
		}
		else if (!q->node->left)
		{
			create = binary_tree_node(q->node, value);
			q->node->left = create;
		}
		else
		{
			create = binary_tree_node(q->node, value);
			q->node->right = create;
		}
	}
	return (create);
}

