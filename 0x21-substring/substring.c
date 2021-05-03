#include "substring.h"
/**
 * campare_val - Function that compare two values
 * @y: first value
 * @x: second value
 * Return: substraction
 **/
int campare_val(const void *y, const void *x)
{
	return (*(int *)y - *(int *)x);
}
/**
 * ch_wrd - Function that chek if all words are continous
 * @aux_indx: array with index for ever word
 * @wrd_size: word size
 * @idx_len: aux_indx size
 * Return: index firt word or zero
 **/
int ch_wrd(int *aux_indx, int wrd_size, int idx_len)
{
	int i;

	for (i = 0; i < idx_len - 1; i++)
	{
		if (aux_indx[i + 1] - aux_indx[i] != wrd_size)
			return (0);
	}
	return (1);
}
/**
 * src_w - Function that search words in string
 * @s: string base
 * @words: array of words to search in the string
 * @nb_words: number of words
 * Return: array with size of substring for every word, otherwise NULL
 **/
int *src_w(char const *s, char const **words, int nb_words)
{
	int *aux_indx, i, j;
	char *aux;
	int len;

	aux_indx = malloc((sizeof(int) * nb_words));
	if (!aux_indx)
		return (NULL);
	for (i = 0; i < nb_words; i++)
	{
		aux = strstr(s, words[i]);
		if (!aux)
		{
			free(aux_indx);
			return (NULL);
		}
		len = (int)strlen(aux);
		for (j = 0; j < i; j++)
		{
			if (len == aux_indx[j])
			{
				aux = strstr(s + (int)strlen(s) - len + 1, words[i]);
				if (!aux)
				{
					free(aux_indx);
					return (NULL);
				}
				len = (int)strlen(aux);
				aux_indx[i] = len;
				continue;
			}
		}
		aux_indx[i] = len;
	}
	return (aux_indx);
}
/**
 * find_substring - Function that src_w words in string
 * @s: string base
 * @words: array of words to searh in the string
 * @nb_words: number of words
 * @n: return size
 * Return: array with index for every word or NULL
 *
 **/
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int *indx, *aux_indx, wrd_size, j, diff, s_len, f_indx, var;

	*n = 0;
	wrd_size = (int)strlen(words[0]);
	s_len = (int)strlen(s);
	for (j = 0; j < s_len; j++)
	{
		aux_indx = src_w(s, words, nb_words);
		if (!aux_indx)
			break;
		qsort(aux_indx, nb_words, sizeof(int), campare_val);
		f_indx = ch_wrd(aux_indx, wrd_size, nb_words);
		var = aux_indx[nb_words - 1];
		free(aux_indx);
		if (f_indx == 1)
		{
			diff = s_len - var;
			if (*n == 0 || diff != indx[*n - 1])
			{
				if (*n == 0)
				{
					indx = malloc((sizeof(int)));
					if (!indx)
						return (NULL);
				}
				else
					indx = realloc(indx, sizeof(int) * (*n + 1));
				indx[*n] = diff;
				*n += 1;
			}
		}
		s++;
	}
	if (*n == 0)
		return (NULL);
	return (indx);
}
