#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * count - sorts array based on significant digit
 * @array: this is an array
 * @size: this is a size of the array
 * @w: this is an integer.
 */
void count(int *array, size_t size, int w)
{
	int c[10] = {0};
	int *otp = malloc(sizeof(int) * size);
	int y;

	for (y = 0; y < (int)size ; y++)
		c[(array[y] / w) % 10]++;

	for (y = 1; y < 10; y++)
		c[y] += c[y - 1];

	for (y = (int)size - 1; y >= 0; y--)
	{
		otp[c[(array[y] / w) % 10] - 1] = array[y];
		c[(array[y] / w) % 10]--;
	}

	for (y = 0; y < (int)size; y++)
		array[y] = otp[y];

	print_array(array, size);
	free(otp);
}
/**
 * radix_sort - function to sort an array
 * @array: this is a pointer
 * @size: this is a size of the array
 * Return: void
 */
void radix_sort(int *array, size_t size)
{
	int maxi, w, y;

	if (size < 2 || !array)
		return;

	maxi = array[0];
	for (y = 0; y < (int)size; y++)
		if (array[y] > maxi)
			maxi = array[y];

	for (w = 1; maxi / w > 0; w *= 10)
		count(array, size, w);
}
