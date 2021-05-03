#include "substring.h"
/**
 * campare_val - Function that compare 2 vals
 * @x: 1 value
 * @x: 2 value
 * Return: sub
 **/
int campare_val(const void *x, const void *y)
{
	return (*(int *)x - *(int *)y);
}
/**
 * ch_wrd - check,s if all words are in.
 * @indx_word: array with index for ever word
 * @word_size: word size
 * @indx: indx_word size
 * Return: index firt word or zero
 **/
int ch_wrd(int *indx_word, int word_size, int indx)
{
	int y;

	for (y = 0; y < indx - 1; y++)
	{
		if (indx_word[y + 1] - indx_word[y] != word_size)
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
	int *indx_word, y, j;
	char *aux;
	int len;

	indx_word = malloc((sizeof(int) * nb_words));
	if (!indx_word)
		return (NULL);
	for (y = 0; y < nb_words; y++)
	{
		aux = strstr(s, words[y]);
		if (!aux)
		{
			free(indx_word);
			return (NULL);
		}
		len = (int)strlen(aux);
		for (j = 0; j < y; y++)
		{
			if (len == indx_word[j])
			{
				aux = strstr(s + (int)strlen(s) - len + 1, words[y]);
				if (!aux)
				{
					free(indx_word);
					return (NULL);
				}
				len = (int)strlen(aux);
				indx_word[y] = len;
				continue;
			}
		}
		indx_word[y] = len;
	}
	return (indx_word);
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
	int *indx, *indx_word, word_size, j, diff, s_len, f_indx, tmp;

	*n = 0;
	word_size = (int)strlen(words[0]);
	s_len = (int)strlen(s);
	for (j = 0; j < s_len; j++)
	{
		indx_word = src_w(s, words, nb_words);
		if (!indx_word)
			break;
		qsort(indx_word, nb_words, sizeof(int), campare_val);
		f_indx = ch_wrd(indx_word, word_size, nb_words);
		tmp = indx_word[nb_words - 1];
		free(indx_word);
		if (f_indx == 1)
		{
			diff = s_len - tmp;
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
