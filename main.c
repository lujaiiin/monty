#include "monty.h"
stack_t *head;

/**
 * main - function
 * @arc: value num
 * @arv: value arr
 * Return: int
 */

int main(int arc, char *arv[])
{
	FILE *fil;
	stack_t *t;

	if (arc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fil = fopen(arv[1], "r");
	if (!arv[1] || !fil)
	{
		fprintf(stderr, "Error: Can't open file %s\n", arv[1]);
		exit(EXIT_FAILURE);
	}
	reado(fil);
	fclose(fil);
	if (!head)
	{
		return (0);
	}
	while (head)
	{
		t = head;
		head = head->next;
		free(t);
	}
	return (0);
}


/**
 * reado - function to read a file
 * @fil: the file path
 */

void reado(FILE *fil)
{
	char *buf = NULL;
	size_t l = 0;
	int ln = 1, how = 0;

	while (getline(&buf, &l, fil) != -1)
	{
		how = strtoke(buf, ln, how);
		ln++;
	}
	free(buf);
}

/**
 * strtoke - function to take every single line
 * @buf: the bufferd to storage
 * @ln: the line
 * @how: the format if 0 means stack if 1 means queue
 * Return: always
 */

int strtoke(char *buf, int ln, int how)
{
	char *tok, *val;

	if (!buf)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	tok = strtok(buf, "\n ");
	if (!tok)
	{
		return (how);
	}
	val = strtok(NULL, "\n ");
	func(tok, val, ln, how);
	return (how);
}

/**
 * func - function to call functions
 * @tok: the name of func
 * @val: the value i need insert
 * @ln: the num of char in every line
 * @how: if 1 means queue if 0 means stack
 */

void func(char *tok, char *val, int ln, int how)
{
	int i = 0, fl = 1;

	instruction_t name[] = {
		{"push", pushe},
		{"pall", palle},
		{"add", adde},
		{"pint", pinte},
		{"swap", swape},
		{"pop", pope},
		{"nop", nope},
		{NULL, NULL}
	};

	while (name[i].opcode)
	{
		if (same(tok, name[i].opcode) == 0)
		{
			funcal(name[i].f, tok, val, ln, how);
			fl = 0;
		}
		i++;
	}
	if (fl == 1)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", ln, tok);
		exit(EXIT_FAILURE);
	}
}
