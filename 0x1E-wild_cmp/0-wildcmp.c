#include "holberton.h"
/**
 * strc - function to compare 2 str
 * @str0: this is a string
 * @str1: this is a string
 * Return: 1 or 0
 */
int strc(char *str0, char *str1)
{

	if (*str1 == '*')
	{
		return (strb(str0, str1 + 1));
	}
	if (*str0 == '\0' || *str1 == '\0')
	{
		if (*str1 == '\0' && *str0 == '\0')
			return (1);
		return (0);
	}
	if (*str0 == *str1)
	{
		return (strc(str0 + 1, str1 + 1));
	}
	return (0);
}
/**
 * strb - branch horizontally if a '*' has been encountered
 * @s1: ptr to string
 * @x: this is a string
 * Return: 1 or 0
 */
int strb(char *s1, char *x)
{
	if (*s1 == '\0')
		return (strc(s1, x));
	return (strc(s1, x) || strb(s1 + 1, x));
}
/**
 * wildcmp - compares two strings
 * @s: ptr to string 1
 * @s2: ptr to string 2 (may contain wildcard denoted by '*')
 * Return: 1 or 0.
 */
int wildcmp(char *s, char *s2)
{
	return (strc(s, s2));
}
