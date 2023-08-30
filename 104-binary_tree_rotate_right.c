#include "binary_trees.h"

/**
 * binary_tree_rotate_right - ...
 *
 * @tree: ...
 *
 * Return: A pointer to the new root node after rotation.
 *
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *pivot, *snapshot;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	pivot = tree->left;
	snapshot = pivot->right;
	pivot->right = tree;
	tree->left = snapshot;
	if (snapshot != NULL)
		snapshot->parent = tree;
	snapshot = tree->parent;
	tree->parent = pivot;
	pivot->parent = snapshot;
	if (snapshot != NULL)
	{
		if (snapshot->left == tree)
			snapshot->left = pivot;
		else
			snapshot->right = pivot;
	}

	return (pivot);
}
