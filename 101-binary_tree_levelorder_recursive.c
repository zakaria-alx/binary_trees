#include "binary_trees.h"

/**
 * struct node_s - ...
 *
 * @node: ...
 * @next: ...
 *
 */
typedef struct node_s
{
	const binary_tree_t *node;
	struct node_s *next;
} linkedList;

linkedList *append(linkedList *head, const binary_tree_t *btnode);
linkedList *get_children(linkedList *head, const binary_tree_t *parent);
void free_list(linkedList *head);
void levels_rec(linkedList *head, void (*func)(int));

/**
 * binary_tree_levelorder - ...
 *
 * @tree: ...
 * @func: ...
 *
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	linkedList *children = NULL;

	func(tree->n);
	children = get_children(children, tree);
	levels_rec(children, func);

	free_list(children);
}

/**
 * levels_rec - ...
 *
 * @head: ...
 * @func: ...
 *
 */
void levels_rec(linkedList *head, void (*func)(int))
{
	linkedList *children = NULL, *curr = NULL;

	if (!head)
		return;
	for (curr = head; curr != NULL; curr = curr->next)
	{
		func(curr->node->n);
		children = get_children(children, curr->node);
	}
	levels_rec(children, func);
	free_list(children);
}

/**
 * get_children - ...
 *
 * @head: ...
 * @parent: ...
 *
 * Return: Pointer to head of linked list of children.
 *
 */
linkedList *get_children(linkedList *head, const binary_tree_t *parent)
{
	if (parent->left)
		head = append(head, parent->left);
	if (parent->right)
		head = append(head, parent->right);
	return (head);
}

/**
 * append - ...
 *
 * @head: ...
 * @btnode: ...
 *
 * Return: pointer to head, or NULL on failure
 *
 */
linkedList *append(linkedList *head, const binary_tree_t *btnode)
{
	linkedList *new = NULL, *last = NULL;

	new = malloc(sizeof(*new));
	if (new)
	{
		new->node = btnode;
		new->next = NULL;
		if (!head)
			head = new;
		else
		{
			last = head;
			while (last->next)
				last = last->next;
			last->next = new;
		}
	}
	return (head);
}

/**
 * free_list - ...
 *
 * @head: ...
 *
 */
void free_list(linkedList *head)
{
	linkedList *ptr = NULL;

	while (head)
	{
		ptr = head->next;
		free(head);
		head = ptr;
	}
}
