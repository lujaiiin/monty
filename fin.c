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
