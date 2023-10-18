#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


extern stack_t *head;
typedef void(*op_func)(stack_t **, unsigned int);

void func(char *tok, char *val, int ln, int how);
int strtoke(char *buf, int ln, int how);
void reado(FILE *fil);
void funcal(op_func fun, char *tok, char *val, int ln, int how);
int same(char *s1, char *s2);
void palle(stack_t **he, unsigned int ln);
void pushe(stack_t **he, unsigned int ln);
void addqu(stack_t **ok, unsigned int ln);
stack_t *node(int k);
void pinte(stack_t **he, unsigned int ln);
void pope(stack_t **he, unsigned int ln);



#endif
