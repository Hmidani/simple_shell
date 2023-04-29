#include "shell.h"

/**
 * _signal - function that handle SIGINT signal
 * @s: an integer input.
 * Return: Nothing.
 */
void _signal(int s)
{
	(void)s;
	write(STDOUT_FILENO, "\n#cisfun$ ", 10);
}
