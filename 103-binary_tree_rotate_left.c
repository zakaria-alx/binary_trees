#include "binary_trees.h"

/**
 * binary_tree_rotate_left - ...
 *
 * @tree: ...
 *
 * Return: A pointer to the new root node after rotation.
 *
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot, *snapshot;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	pivot = tree->right;
	snapshot = pivot->left;
	pivot->left = tree;
	tree->right = snapshot;
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
