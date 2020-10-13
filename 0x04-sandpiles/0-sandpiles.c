#include "sandpiles.h"
/**
 * sum - sums function.
 * @grid1: this is a matrix.
 * @grid2: second matrix.
 */
static void sum(int grid1[3][3], int grid2[3][3])
{
int y;
int z;

	for (y = 0; y < 3; y++)
		for (z = 0; z < 3; z++)
			grid1[y][z] += grid2[y][z], grid2[y][z] = 0;
}

/**
 * stable - checks if snadpile is stable.
 * @grid: a matrix matrix.
 * Return: 1 if stable, 0 otherwise.
*/
static int stable(int grid[3][3])
{
int y;
int z;

	for (y = 0; y < 3; y++)
		for (z = 0; z < 3; z++)
			if (grid[y][z] > 3)
				return (0);
	return (1);
}
/**
 * print - Prints the grid.
 * @grid: this is a matrix.
 * Return: 1 if stable, 0 otherwise.
*/
static void print(int grid[3][3])
{
int y;
int z;

	printf("=\n");
	for (y = 0; y < 3; y++)
	{
		for (z = 0; z < 3; z++)
		{
			if (z)
				printf(" ");
			printf("%d", grid[y][z]);
		}
		printf("\n");
	}
}

/**
 * tip - tips matrix.
 * @grid1: First sandpile.
 * @grid2: Second sandpile.
 */
static void tip(int grid1[3][3], int grid2[3][3])
{
int y;
int z;

	for (y = 0; y < 3; y++)
		for (z = 0; z < 3; z++)
			if (grid1[y][z] > 3)
			{
				grid1[y][z] -= 4;
				if (y - 1 >= 0)
					grid2[y - 1][z]++;
				if (y + 1 < 3)
					grid2[y + 1][z]++;

				if (z - 1 >= 0)
					grid2[y][z - 1]++;
				if (z + 1 < 3)
					grid2[y][z + 1]++;
			}
}

/**
 * sandpiles_sum - Sums function.
 * @grid1: First sandpile.
 * @grid2: Second sandpile.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	sum(grid1, grid2);
	while (!stable(grid1))
	{
		print(grid1);
		tip(grid1, grid2);
		sum(grid1, grid2);
	}
}
