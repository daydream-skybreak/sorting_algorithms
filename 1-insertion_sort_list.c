#include "sort.h"
/**
 *
 */
void swap(listint_t **h, listint_t **pre, listint_t *node)
{
	(*pre)->next = node->next;
	if (node->next != NULL)
		node->next->prev = *pre;

	node->prev = (*pre)->prev;
	node->next = *pre;

	if ((*pre)->prev != NULL)
		(*pre)->prev->next = node;
	else
		*h = node;

	(*pre)->prev = node;
	*pre = node->prev;

}
/**
 * insertion_sort_list - sorts a list using insertion sorting algortihm
 * @list: list ot be sorted
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node, *pre, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (node = (*list)->next; node != NULL; node = tmp)
	{
		tmp = node->next;
		pre = node->prev;

		while (pre != NULL && pre->n > node->n)
		{
			swap(list, &pre, node);
			print_list((const listint_t *)*list);
		}
	}
}
