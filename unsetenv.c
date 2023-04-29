#include "shell.h"

/**
 * _isunsetenv - function that to finds if line input is unsetenv
 * @p: the string input1.
 * @myenv: the string input2.
 * @loop: the integer input1.
 * @v: the integer input2.
 * @e: the string input3.
 * Return: an integr value.
 */
int _isunsetenv(char **p, char **myenv, int *e, int loop, char *v[])
{
	char str[] = "unsetenv";
	int i = 0, cont = 0, salida = -1;

	i = 0;
	while (p[0][i] != '\0')
	{
		if (i < 8)
		{
			if (p[0][i] == str[i])
				cont++;
		}
		i++;
	}
	if (i == 8)
		cont++;
	if (cont == 9)
	{
		if (p[1] != NULL)
			_unsetenv(p, myenv, e, loop, v);
		else
			_put_err(p, loop, 5, v);
		salida = 0;
		currentstatus(&salida);
	}
	else if (cont == 8)
	{
		salida = 0;
		_put_err(p, loop, 3, v);
		currentstatus(&salida);
	}
	return (salida);
}
/**
 * _unsetenv - function to remove an environment variable
 * environ points to an array of pointers to strings called the "environment"
 * @p: the string input1.
 * @myenv: the string input2.
 * @loop: the integer input1.
 * @v: the integer input2.
 * @e: the string input3.
 * Return: nothing.
 */
void _unsetenv(char **p, char **myenv, int *e, int loop, char *v[])
{
	int i, lg, j, k = 0, k2 = 0, k3 = 0, cont = 0;

	lg = _strlen(p[1]);
	for (i = 0; myenv[i] != NULL; i++, cont = 0)
	{
		for (j = 0; p[1][j] != '\0' && j < lg; j++)
		{
			if (p[1][j] == myenv[i][j])
				cont++;
		}
		if (cont == lg)
			break;
	}
	if (cont == lg)
	{
		for (k = i; myenv[k] != NULL && myenv[k + 1] != NULL; k++)
		{
			for (k2 = 0; myenv[k][k2] != '\0'; k2++)
				myenv[k][k2] = 0;
			for (k3 = 0; myenv[k + 1][k3] != '\0'; k3++)
				;
			if (k2 < k3)
				myenv[k] = _realloc(myenv[k], k2, k3);
			for (k2 = 0; myenv[k + 1][k2] != '\0'; k2++)
				myenv[k][k2] = myenv[k + 1][k2];
		}
		free(myenv[k]);
		myenv[k] = NULL;
		*e = *e - 1;
		free(myenv[k + 1]);
	}
	else
		_put_err(p, loop, 5, v);
}
