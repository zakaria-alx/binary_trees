#include "binary_trees.h"

size_t depth(const binary_tree_t *tree);

/**
 * binary_trees_ancestor - ...
 *
 * @first: ...
 * @second: ...
 *
 * Return: If no common ancestors return NULL, else return common ancestor.
 *
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	size_t firstDepth, seconDepth;

	if (first == NULL || second == NULL)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);
	if (first->parent == second->parent)
		return ((binary_tree_t *)first->parent);
	if (first == second->parent)
		return ((binary_tree_t *)first);
	if (first->parent == second)
		return ((binary_tree_t *)second);

	for (firstDepth = depth(first); firstDepth > 1; firstDepth--)
		first = first->parent;
	for (seconDepth = depth(second); seconDepth > 1; seconDepth--)
		second = second->parent;

	if (first == second)
		return ((binary_tree_t *)first);
	if (first->parent == second->parent)
		return ((binary_tree_t *)first->parent);
	if (first == second->parent)
		return ((binary_tree_t *)first);
	if (first->parent == second)
		return ((binary_tree_t *)second);
	else
		return (NULL);
}

/**
 * depth - ...
 *
 * @tree: ...
 *
 * Return: If tree is NULL, your function must return 0, else return the depth.
 *
 */
size_t depth(const binary_tree_t *tree)
{
	return ((tree->parent != NULL) ? 1 + depth(tree->parent) : 0);
}
