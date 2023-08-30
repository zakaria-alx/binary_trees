#include "binary_trees.h"

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
	binary_tree_t *firstAnc, *secondAnc;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	firstAnc = first->parent, secondAnc = second->parent;
	if (first == secondAnc || !firstAnc || (!firstAnc->parent && secondAnc))
		return (binary_trees_ancestor(first, secondAnc));
	else if (
		firstAnc == second || !secondAnc || (!secondAnc->parent && firstAnc))
		return (binary_trees_ancestor(firstAnc, second));
	return (binary_trees_ancestor(firstAnc, secondAnc));
}
