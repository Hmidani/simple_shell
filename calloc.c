#include <stdlib.h>
#include "shell.h"
/**
 * _calloc - a functiont that takes two arguments, the number
 * of elements to allocate memory
 * @nmemb: an unsigned int input1.
 * @size: an unsigned int input2.
 * Return: nothing.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	void *p = NULL;
	unsigned int i;

	if (nmemb == 0 || size == 0)
	{
		return (NULL);
	}
	p = malloc(nmemb * size);
	if (p == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < (nmemb * size); i++)
	{
		*((char *)(p) + i) = 0;
	}
	return (p);
}
