#include "sandpiles.h"


/**
 * suma_grid -  Compute the sum of two grids
 * @grid1: grid 1
 * @grid2: grid 2
 * Return: void
 */
void suma_grid(int grid1[3][3], int grid2[3][3])
{
	int m = 0, n = 0;

	for (m = 0; m < 3; m++)
	{
		for (n = 0; n < 3; n++)
		{
			grid1[m][n] += grid2[m][n];
		}
	}
}

/**
 * is_unstable - check if a grid is unstable
 * @grid: grid
 * Return: 1 if grid is unstable, otherwise 0
 */
int is_unstable(int grid[3][3])
{
	int m = 0, n = 0;

	for (m = 0; m < 3; m++)
	{
		for (n = 0; n < 3; n++)
		{
			if (grid[m][n] > 3)
			{
				return (1);
			}
		}
	}

	return (0);
}

/**
 * print_grid - prints a grid
 * @grid: grid
 * Return: void
 */
void print_grid(int grid[3][3])
{
	int m = 0, n = 0;

	for (m = 0; m < 3; m++)
	{
		for (n = 0; n < 3; n++)
		{
			printf("%i", grid[m][n]);
			if (n < 2)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}

/**
 * stabillize_grid - performs grid transformation to stabillize it
 * @grid: grid
 * Return: void
 */
void stabillize_grid(int grid[3][3])
{
	int m = 0, n = 0;

	for (m = 0; m < 3; m++)
	{
		for (n = 0; n < 3; n++)
		{
			if (grid[m][n] > 3)
			{
				grid[m][n] -= 4;
				/* Up */
				if (m > 0)
				{
					grid[m - 1][n] += 1;
				}
				/* Right */
				if (n < 2)
				{
					grid[m][n + 1] += 1;
				}
				/* Down */
				if (m < 2)
				{
					grid[m + 1][n] += 1;
				}
				/* Left */
				if (n > 0)
				{
					grid[m][n - 1] += 1;
				}
			}
		}
	}
}

/**
 * sandpiles_sum - performs a sum of fractal numbers
 * @grid1: first fractal number
 * @grid2: second fractal number
 * Return: void
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	suma_grid(grid1, grid2);

	while (is_unstable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		stabillize_grid(grid1);
	}
}
