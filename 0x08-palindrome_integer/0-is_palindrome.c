#include <stdlib.h>
#include <stdio.h>
#include "palindrome.h"
/**
 * is_palindrome -  checks if an unsigned integer is a palindrome
 * @n: input integer
 * Return: 1 if n is palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long reverse_n, copy_n, organ_n;

	reverse_n = 0;
	organ_n = n;

	while (n != 0)
	{
		copy_n = n % 10;
		reverse_n = reverse_n * 10 + copy_n;
		n /= 10;
	}
	if (organ_n == reverse_n)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}
