#include "binary_trees.h"

/**
 * binary_tree_node - ...
 *
 * @parent: ...
 * @value: ...
 *
 * Return: must return a pointer to the new node, or NULL on failure.
 *
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *tree;

	tree = malloc(sizeof(binary_tree_t));
	/* Break on malloc errors */
	if (tree == NULL)
		return (NULL);

	tree->n = value;
	tree->parent = parent;
	tree->left = NULL;
	tree->right = NULL;

	return (tree);
}
