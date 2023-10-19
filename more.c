#include "monty.h"

/**
 * same - function like strcmp
 * @s1: first str
 * @s2: sec str
 * Return: 0 or 1
 */

int same(char *s1, char *s2)
{
	return (strcmp(s1, s2));
}

/**
 * funcal - function to call
 * @fun: the fun name
 * @tok: the name
 * @val: the value
 * @ln: the line number
 * @how: 0 or 1
 */

void funcal(op fun, char *tok, char *val, int ln, int how)
{
	int j = 0, fl = 1;
	stack_t *ok;

	if (same(tok, "push") == 0)
	{
		if (val && val[0] == '-')
		{
			val = val + 1;
			fl = -1;
		}
		if (!val)
		{
			fprintf(stderr, "L%d: usage: push integer\n", ln);
			exit(EXIT_FAILURE);
		}
		while (val[j] != '\0')
		{
			if (isdigit(val[j] == 0))
			{
				fprintf(stderr, "L%d: usage: push integer\n", ln);
				exit(EXIT_FAILURE);
			}
			j++;
		}
		ok = node(atoi(val) * fl);
		if (how == 0)
		{
			fun(&ok, ln);
		}
	}
	else
	{
		fun(&head, ln);
	}
}

/**
 * node - function
 * @k: value
 * Return: always
 */

stack_t *node(int k)
{
	stack_t *ok;

	ok = malloc(sizeof(stack_t));
	if (ok == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	ok->next = NULL;
	ok->prev = NULL;
	ok->n = k;

	return (ok);
}

/**
 * addqu - fun
 * @ok: value
 * @ln: value
 

void addqu(stack_t **ok, unsigned int ln)
{
	stack_t *t;

	(void) ln;

	if (!ok || !*ok)
	{
		exit(EXIT_FAILURE);
	}
	if (head == NULL)
	{
		head = *ok;
		return;
	}
	t = head;
	for (; t->next != NULL;)
	{
		t = t->next;
	}
	t->next = *ok;
	(*ok)->prev = t;
}*/
