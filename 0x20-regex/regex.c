#include "regex.h"
/**
 * strc - compare two strings
 * @str0: this is a string
 * @str1: this is a string
 * Return: 1or 0
 */
int strc(char const *str0, char const *str1)
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
 * @x: string with '*'
 * Return: 1 if the string matches, else 0
 */
int strb(char const *s1, char const *x)
{
	if (*s1 == '\0')
		return (strc(s1, x));
	return (strc(s1, x) || strb(s1 + 1, x));
}
/**
 * regex_match - checks whether a given pattern matches a given string
 * @str: this is a string
 * @pattern: elemenet to compare with
 * Return: 1 or 0.
 */
int regex_match(char const *str, char const *pattern)
{
	return (strc(str, pattern));
}
