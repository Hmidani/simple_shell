#include "shell.h"
/**
 * main - function that shell skeleton
 * @argc: the integer input.
 * @argv: the first string input.
 * @envp: the second string input.
 * Return: an integer value.
 */
int main(int argc, char *argv[], char *envp[])
{

	if (argc == 1)
	{
		_noargv(argv, envp);
	}
	else if (argc == 2)
	{
		_yesargv(argv, envp);
	}
	else
	{
		write(STDIN_FILENO, "NO ADMITTED AMOUNT OF ARGUMENTS", 31);
		write(STDIN_FILENO, "\n", 1);
	}
	return (0);
}
