#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - Deletes a node at a specific index
 * @head: Double pointer to head of list
 * @index: Index of node to delete
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current = *head;
	unsigned int i = 0;

	if (!head || !*head)
		return (-1);

	while (current && i < index)
	{
		current = current->next;
		i++;
	}

	if (!current)
		return (-1);

	if (current->prev)
		current->prev->next = current->next;
	else
		*head = current->next;

	if (current->next)
		current->next->prev = current->prev;

	free(current);
	return (1);
}
