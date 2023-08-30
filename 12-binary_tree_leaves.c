#include "binary_trees.h"

/**
 * binary_tree_leaves - ...
 *
 * @tree: ...
 *
 * Return: The number of leaves in the tree.
 *
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t found = 0;

	if (tree)
	{
		found += (!tree->left && !tree->right) ? 1 : 0;
		found += binary_tree_leaves(tree->left);
		found += binary_tree_leaves(tree->right);
	}
	return (found);
}
