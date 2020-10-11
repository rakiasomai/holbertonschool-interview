#include "binary_trees.h"
/**
 * binary_tree_node - creates a binary tree node.
 * @parent: this is a pointer.
 * @value: value added to the new node.
 * Return: the address.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
binary_tree_t *create;
create = malloc(sizeof(binary_tree_t));
if (!create)
return (NULL);
create->parent = parent;
create->n = value;
create->left = NULL;
create->right = NULL;
return (create);
}
