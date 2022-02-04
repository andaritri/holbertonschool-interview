#include "lists.h"

/**
 * check_cycle - Check if there is a cycle
 * @list: head of linked list
 * Return: 0 if there is no cycle, 1 if there is a cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *fast = NULL;

	if (list == NULL)
		return (0);

	fast = list->next;
	while (fast != NULL && fast->next != NULL)
	{
		if (fast == list)
			return (1);

		fast = fast->next->next;
		list = list->next;
	}
	return (0);
}
