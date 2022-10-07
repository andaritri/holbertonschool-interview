#ifndef LISTS_H
#define LISTS_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - single linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: single linked list node structure
 */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

listint_t *find_listint_loop(listint_t *head);

#endif
