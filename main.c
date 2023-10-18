#include "monty.h"
stack_t *head;
/**
 * main - main function
 * arc - value num
 * arv - value arr
 */


int main(int arc, char *arv[])
{
	FILE *fil;

	if (arc != 2)
	{

		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fil = fopen(arv[1], "r");
	if (!arv[1] || !fil)
	{
		fprintf(stderr, "Error: Can't open file %s\n", arv[1]);
	}
	reado(fil);
	fclose(fil);
	return (0);

}


/**
 * reado - function to read a file
 * fd: the file path
 */

void reado(FILE *fil)
{
	char *buf = NULL;
	size_t len = 0;
	int ln = 1, how = 0;

	while (getline(&buf, &len, fil) != -1)
	{
		how = strtoke(buf, ln, how);
		ln++;
	}
	free(buf);
}

/**
 * strtoke - function to take every single line
 * @buf: the bufferd to storage
 * @len: the line
 * @how: the format if 0 means stack if 1 means queue
 * Return: always
 */

int strtoke(char *buf, int ln, int how)
{
	char *tok, *val;

	if (!buf)
	{
		fprintf(stderr, "Error: malloc failed\n");
	}

	tok = strtok(buf, "\n ");
	if (!tok)
	{
		return (how);
	}
	val = strtok(NULL, "\n ");

	if (same(tok, "queue") == 0)
	{
		return (1);
	}
	if (same(tok, "stack") == 0)
	{
		return (0);
	}

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
	int i, fl;

	instruction_t name[] = {
		{"push", pushe},
		{"pall", palle}
	};

	if (tok[0] == '#')
	{
		return;
	}
	fl = 1;
	i = 0;
	while (name[i].opcode != NULL)
	{
		if (strcmp(tok, name[i].opcode) == 0)
		{
			funcal(name[i].f, tok, val, ln, how);
			fl = 0;
		}
		i++;
	}
	if (fl == 1)
	{
		fprintf(stderr, "L%d: unknown instruction %s", ln, tok);
	}
}
