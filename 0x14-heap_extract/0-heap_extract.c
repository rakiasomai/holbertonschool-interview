#include "binary_trees.h"
/**
 * long_b - Measure unity.
 * @t: this is a pointer.
 * Return: the node.
 */
static size_t long_b(const binary_tree_t *t)
{
	size_t long_l, long_r;

	long_l = t->left ? 1 + long_b(t->left) : 0;
	long_r = t->right ? 1 + long_b(t->right) : 0;
	return (long_l > long_r ? long_l : long_r);
}
/**
 * cheak - this is a function
 * @root: this is a pointer
 * @node: this is a pointer
 * @h: the size
 * @l: the size
 **/
void cheak(heap_t *root, heap_t **node, size_t h, size_t l)
{
	if (!root)
		return;
	if (h == l)
		*node = root;
	l++;
	if (root->left)
		cheak(root->left, node, h, l);
	if (root->right)
		cheak(root->right, node, h, l);
}
/**
 * get_s - sorting binary tree
 * @tmp: this is a pointer
 * Return: the pointer
 **/
heap_t *get_s(heap_t *tmp)
{
	int value;

	while (tmp->left || tmp->right)
	{
		if (!tmp->right || tmp->left->n > tmp->right->n)
		{
			value = tmp->n;
			tmp->n = tmp->left->n;
			tmp->left->n = value;
			tmp = tmp->left;
		}
		else if (!tmp->left || tmp->left->n < tmp->right->n)
		{
			value = tmp->n;
			tmp->n = tmp->right->n;
			tmp->right->n = value;
			tmp = tmp->right;
		}

	}
	return (tmp);
}
/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: pointer to the heap root
 * Return: value of extracted node
 **/

int heap_extract(heap_t **root)
{
	int v;
	heap_t *tmp, *node;

	if (!root || !*root)
		return (0);
	tmp = *root;
	v = tmp->n;
	if (!tmp->left && !tmp->right)
	{
		*root = NULL;
		free(tmp);
		return (v);
	}
	cheak(tmp, &node, long_b(tmp), 0);
	tmp = get_s(tmp);
	tmp->n = node->n;
	if (node->parent->right)
		node->parent->right = NULL;
	else
		node->parent->left = NULL;
	free(node);
	return (v);
}
