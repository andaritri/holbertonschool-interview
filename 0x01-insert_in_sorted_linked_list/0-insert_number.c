#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * create_node - creates a new node of type listint_t
 * @number: value of the new node
 *
 * Return: the address of the new node
 */
listint_t *create_node(int number)
{
	listint_t *new_node;

	new_node = malloc(sizeof(listint_t));
	new_node->n = number;
	new_node->next = NULL;

	return (new_node);
}


/**
 * insert_node - inserts a number into a sorted singly linked list
 * @head: double pointer to the first node of the linked list
 * @number: integer to insert
 *
 * Return: the address of the new node, or NULL if failed
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *current;
	listint_t *p;
	listint_t *new_node;

	current = *head;
	p = *head;
	new_node = create_node(number);

	if (!head || !new_node)
		return (NULL);
	if (!*head)
	{
		*head = new_node;
		return (new_node);
	}
	if (new_node->n < (*head)->n)
	{
		new_node->next = (*head);
		*head = new_node;
		return (new_node);
	}
	while (current && *head)
	{
		if (current->next == NULL)
		{
			current->next = new_node;
			new_node->next = NULL;
		}
		if (current->n > new_node->n)
		{
			new_node->next = current;
			p->next = new_node;
			break;
		}
		p = current;
		current = current->next;
	}
	return (new_node);
}
