#include "monty.h"

/**
 * pope - function to pop first
 * @he: value
 * @ln: line number
 */

void pope(stack_t **he, unsigned int ln)
{
	stack_t *t;

	if (!*he || !he)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", ln);
		exit(EXIT_FAILURE);
	}

	t = *he;
	*he = t->next;
	if (*he)
	{
		(*he)->prev = NULL;
	}
	free(t);
}

/**
 * nope - function
 * @he: value
 * @ln: line number
 */

void nope(stack_t **he, unsigned int ln)
{
	(void) ln;
	(void) he;
}

/**
 * adde - function
 * @he: value
 * @ln: line number
 */

void adde(stack_t **he, unsigned int ln)
{
	int all;

	if (!he || !*he || (*he)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", ln);
		exit(EXIT_FAILURE);
	}
	(*he) = (*he)->next;
	all = (*he)->n + (*he)->prev->n;
	(*he)->n = all;
	free((*he)->prev);
	(*he)->prev = NULL;
}
