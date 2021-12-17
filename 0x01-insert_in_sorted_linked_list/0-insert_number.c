#include "lists.h"
/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: head
 * @number: number to be inserted
 *
 * Return: address of the new_node node, or NULL if it failed
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current, *new_node;
	int previous;

	current = *head;
	new_node = malloc(sizeof(listint_t));
	if (!new_node)
    {
		return (NULL);
    }

	if (!*head)
	{
		new_node->n = number;
		new_node->next = NULL;
		*head = new_node;
		return (new_node);
	}
	new_node->n = number;
	while (current)
	{
		previous = current->n;
		if (previous >= number)
		{
			new_node->next = current;
			*head = new_node;
			return (new_node);
		}
		else if(!current->next && previous <= number)
		{
			current->next = new_node;
			new_node->next = NULL;
			return (new_node);
		}
		else if (previous <= number && current->next->n >= number)
		{
			new_node->next = current->next;
			current->next = new_node;
			return (new_node);
		}
		current = current->next;
	}
	return (NULL);
}