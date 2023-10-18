#include "monty.h"

/**
 * pushe - add val to stack
 * @he: the new
 * @ln: line num
 */

void pushe(stack_t **he, unsigned int ln)
{
	stack_t *t;

	(void) ln;

	if (!*he || !he)
	{
		exit(EXIT_FAILURE);
	}
	if (head == NULL)
	{
		head = *he;
		return;
	}
	t = head;
	head = *he;
	head->next = t;
	t->prev = head;
}

/**
 * palle - function to pall
 * @ln: line num
 * @he: points to top
 */

void palle(stack_t **he, unsigned int ln)
{
	stack_t *t;

	(void) ln;

	if (!he)
	{
		exit(EXIT_FAILURE);
	}
	t = *he;
	for (; t;)
	{
		printf("%d\n", t->n);
		t = t->next;
	}
}
