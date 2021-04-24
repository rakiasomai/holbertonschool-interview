#include "binary_trees.h"
/**
 *  binary_tree_n - Function creates a binary tree node
 * @parent: ptr to parent node
 * @v: value for node
 * Return: ptr to new node, or NULL on failure
 */

binary_tree_t *binary_tree_n(binary_tree_t *parent, int v)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (node == NULL)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	return (node);
}
