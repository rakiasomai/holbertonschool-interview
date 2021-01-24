#include "search_algos.h"
/**
* repeat_ser - Repeat searching for value.
* @a: This is an array.
* @one: This is an index.
* @two: This is an index.
* @v: The value to search for.
* Return: The value or -1.
*/
int repeat_ser(int *a, int one, int two, int v)
{
int tmp;
int x;

	if (one > two)
		return (-1);
	tmp = (one + two) / 2;
	if (a[tmp] == v && one == two)
		return (tmp);
	printf("Searching in array: ");
	for (x = one; x <= two; x++)
	{
		if (x != one)
		{
			printf(", ");
		}
		printf("%d", a[x]);
		if (x == two)
			printf("\n");
	}
	if (a[tmp] >= v)
		return (repeat_ser(a, one, tmp, v));
	return (repeat_ser(a, tmp + 1, two, v));
}

/**
* advanced_binary - searches for a v in a sorted a of integers.
* @a: is a pointer to the first element of the a to search in.
* @size: is the number of elements in a.
* @v: the v to search for.
* Return: the index or -1.
*/
int advanced_binary(int *a, size_t size, int v)
{
	if (!a || size < 1)
		return (-1);
	return (repeat_ser(a, 0, (int)(size - 1), v));
}
