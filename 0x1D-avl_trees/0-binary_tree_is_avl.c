#include<limits.h>
#include<stddef.h>
#include "binary_trees.h"


int bist(const binary_tree_t *t, int low, int height);
/**
 * binary_tree_b - Checks if a tree is a BST
 * @t: ptr to root node
 * Return: 1 if is a BST, 0 if not
 */

int binary_tree_b(const binary_tree_t *t)
{
	if (!t)
		return (0);

	return (bist(t, INT_MIN, INT_MAX));
}

/**
 * bist - Checks if a tree is a BST
 * @t: ptr to root node
 * @low: minimum constraint
 * @height: maximum constraint
 * Return: 1 if is a BST, 0 if not
 */

int bist(const binary_tree_t *t, int low, int height)
{
	if (!t)
		return (1);
	if (t->n < low || t->n > height)
		return (0);
	return (bist(t->left, low, t->n - 1) &&
		bist(t->right, t->n + 1, height));
}

/**
 * binary_tree_h - Measures height of binary tree
 * @t: pointer to root
 * Return: size_t height
 */

size_t binary_tree_h(const binary_tree_t *t)
{
	size_t r_count, l_count;

	if (t == NULL)
		return (0);

	if (!t->right && !t->left)
		return (0);

	r_count = binary_tree_h(t->right);
	l_count = binary_tree_h(t->left);

	if (l_count > r_count)
		return (l_count + 1);
	else
		return (r_count + 1);
}

/**
 * binary_tree_is_avl - checks if binary tree is valid AVL tree
 * @tree: ptr to root node
 * Return: 1 if tree valid AVL, else 0
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	size_t height_l;
	size_t height_r;
	size_t diff;

	if (!tree)
		return (0);
	if (!binary_tree_b(tree))
		return (0);

	height_l = tree->left ? binary_tree_h(tree->left) : 0;
	height_r = tree->right ? binary_tree_h(tree->right) : 0;

	if (height_l > height_r)
		diff = height_l - height_r;
	else
		diff = height_r - height_l;

	if (diff > 1)
		return (0);

	if (!(tree->left) && !(tree->right))
		return (1);
	else
		return (binary_tree_is_avl(tree->left) && binary_tree_is_avl(tree->right));
}
