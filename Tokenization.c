#include "monty.h"


/**
 * tokenize - function that take line & tokenize it
 *
 * @content: is pointer to line of file
 * @op: operation order
 *
 * Return: the result Token
 */

char *tokenize(char *content, __attribute__((unused)) char **op)
{
	return (strtok(content, " \n\t"));
}
