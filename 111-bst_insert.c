#include "binary_trees.h"

/**
 * bst_insert - ...
 *
 * @tree: ...
 * @value: ...
 *
 * Return: A pointer to the created node, or NULL on failure.
 *
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *current, *new;

	if (tree != NULL)
	{
		current = *tree;

		if (current == NULL)
		{
			new = binary_tree_node(current, value);
			if (new == NULL)
				return (NULL);
			return (*tree = new);
		}

		if (value < current->n) /* insert in left subtree */
		{
			if (current->left != NULL)
				return (bst_insert(&current->left, value));

			new = binary_tree_node(current, value);
			if (new == NULL)
				return (NULL);
			return (current->left = new);
		}
		if (value > current->n) /* insert in right subtree */
		{
			if (current->right != NULL)
				return (bst_insert(&current->right, value));

			new = binary_tree_node(current, value);
			if (new == NULL)
				return (NULL);
			return (current->right = new);
		}
	}
	return (NULL);
}
