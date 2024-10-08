/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_minishell.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellegr <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:48:55 by lpellegr          #+#    #+#             */
/*   Updated: 2024/09/11 20:48:56 by lpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Calculate the length of the next part of the given string 
 * up to a separator or redirection.
 * This function traverses the string `s` to count characters until 
 * it finds the specified separator `sep` unless the character 
 * is within quotes or is part of a redirection command.
 * @param s The string to process.
 * @param sep The separator character to stop at.
 * @return The count of characters up to the separator, end of the string,
 *  or redirection symbol. If the string starts with a redirection character,
 *  the function returns 1 for a single redirection symbol ('>' or '<') 
 * 	and 2 for double symbols ('<<' or '>>').
 *  If a redirection symbol is found not at the start and outside of quotes,
 *  the count up to (but not including) the redirection is returned.
 */
static int	countchar(char *s, char sep)
{
	int	i;

	i = 0;
	while ((*(s + i) && *(s + i) != sep) || is_in_quote(s, i, 1))
	{
		if (i == 0 && is_redir(*(s + i)))
		{
			if (is_redir(*(s + i + 1)))
				return (2);
			return (1);
		}
		else if (is_redir(s[i]) && !is_in_quote(s, i, 1))
			return (i);
		else
			i++;
	}
	return (i);
}

/**
 * @brief Counts the number of words in a string, 
 * delimited by a specified separator, ignoring the separators within quotes.
 * @param s The string to process.
 * @param sep The character used as a word separator.
 * @return The number of words found in the string. 
 * If the string is empty or NULL, returns 0.
 */
static int	countwords(char *s, char sep)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == sep && !is_in_quote(s, i, 1))
			i++;
		if (s[i])
		{
			count++;
			i += countchar(&s[i], sep);
		}
	}
	return (count);
}

/**
 *@brief Creates a duplicate of a substring of length `len` from string `s`.
 *
 * @param s The source string to duplicate from.
 * @param len The number of characters to duplicate.
 * @return A pointer to the newly allocated string which is a
 *  duplicate of the substring, or NULL if the allocation fails.
 */
char	*strldup(char *s, int len)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (dest);
	while (s && s[i] && i < len)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * @brief Copies a word from the string `s` starting at index `*i`, 
 * skipping initial separators, and advances the index past the copied word. 
 * This function modifies the index `i` to point to the character following the
 * last character of the word copied, handling separators 
 * and quotes appropriately.
 * @param s The string from which to copy the word.
 * @param i Pointer to the index in string `s` where the word starts. 
 * This index is modified by the function to reflect the new position 
 * after the word has been copied, thus affecting the caller's state.
 * @param sep The character used as a word separator.
 * @return A pointer to the new word, or NULL if no word is found or
 *  memory allocation fails.
 */
static char	*word_copy(char *s, int *i, char sep)
{
	char	*new_word;
	int		len;

	while (s[*i] == sep && !is_in_quote(s, *i, 1))
		(*i)++;
	if (s[*i])
	{
		len = countchar(&s[*i], sep);
		new_word = strldup(&s[*i], len);
		if (!new_word)
			return (NULL);
		*i += len;
	}
	return (new_word);
}

/**
 * @brief Splits a string `s` into an array of words based 
 * on the separator `sep`, considering quotes and managing 
 * memory allocation for the array of words.
 * @param s The string to split.
 * @param sep The character used as a word separator.
 * @return A pointer to the first element of an array of word strings,
 *         or NULL if the string is NULL or memory allocation fails.
 */
char	**shell_split(char *s, char sep)
{
	int		counter;
	char	**res;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	counter = countwords(s, sep);
	res = (char **)malloc(sizeof(char *) * (counter + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (j < counter)
	{
		res[j] = word_copy(s, &i, sep);
		if (!res[j])
			return (split_free(res, j), NULL);
		j++;
	}
	res[j] = NULL;
	return (res);
}
