#include "binary_trees.h"

/**
 * binary_tree_nodes - ...
 *
 * @tree: ...
 *
 * Return: If tree is NULL, the function must return 0, else return node count.
 *
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t found = 0;

	if (tree)
	{
		found += (tree->left || tree->right) ? 1 : 0;
		found += binary_tree_nodes(tree->left);
		found += binary_tree_nodes(tree->right);
	}
	return (found);
}
