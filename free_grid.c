#include "shell.h"
/**
 * free_grid - function to free a matrix
 * @grid: the string input
 * @height: the integre input
 * Return: nothing
 */
void free_grid(char **grid, int height)
{
	int i;

	for (i = 0; i < height; i++)
	{
		free(grid[i]);
	}
	free(grid);
}
