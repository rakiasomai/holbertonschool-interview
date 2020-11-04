#include "binary_trees.h"
/**
 * binary_tree_node - This function creates a binary tree node
 * @parent: node to add new node
 * @value: value to insert in new node
 * Return: poointer to the new node
 */
avl_t *binary_tree_node(avl_t *parent, int value)
{
	avl_t *new;

	new = malloc(sizeof(avl_t));
	if (new == NULL)
		return (NULL);

	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;
	return (new);
}
/**
 * insert - Function to insert a new node
 * @root: the head of the b tree
 * @array: This is an array
 * @end: this is the end array
 * @start: this is the start array
 * Return: pointer to new node or NULL if it fails
 */
avl_t *insert(avl_t **root, int end, int start, int *array)
{
	int half = (start + end) / 2;
	avl_t *new = NULL;

	if (start > end)
		return (NULL);
	new = binary_tree_node(*root, array[half]);
	if (half != start)
		new->left = insert(&new, half - 1, start, array);
	if (half != end)
		new->right = insert(&new, end, half + 1, array);
	return (new);
}
/**
 * sorted_array_to_avl - sorts array into avl binary tree
 * @array: The array to sorted
 * @size: Size of the array
 * Return: pointer to root node of the created tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;

	root = insert(&root, size - 1, 0, array);
	return (root);
}
