#include "sort.h"
/**
 * cyclicSwap - Swap elements.
 * @a: this is an integer
 * @b: this is an integer
 */
void cyclicSwap(int *a, int *b)
{
int tmp;
tmp = *a;
*a = *b;
*b = tmp;
}
/**
 * heapify - Converting an array into heap.
 * @array: This is an array.
 * @z: The size of heap.
 * @r: This is the index.
 * @size: The size of the array.
 */
void heapify(int *array, int z, int r, int size)
{
int max = r;
int l = 2 * r + 1;
int right = 2 * r + 2;

if (l < z && array[l] > array[max])
	max = l;

	if (right < z && array[right] > array[max])
		max = right;

	if (max != r)
	{
		cyclicSwap(&array[r], &array[max]);
		print_array(array, size);
		heapify(array, z, max, size);
	}
}
/**
 * heap_sort - The heap sort algorithm.
 * @array: This is an array.
 * @size: the size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int y;

for (y = size / 2 - 1; y >= 0; y--)
	heapify(array, size, y, size);
	for (y = size - 1; y >= 0; y--)
	{
		cyclicSwap(&array[0], &array[y]);
		if (y != 0)
			print_array(array, size);
		heapify(array, y, 0, size);
	}
}
