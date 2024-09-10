#include "../../includes/minishell.h"

/**
 * @brief This function checks for quote marks (' or ") at a given index in 
 * 	a string and updates quote status accordingly.
 * @param str The string in which to check for quotes.
 * @param i The index at which to check for a quote in the string.c
 * @note The function toggles the quote status based on whether the current 
 * 	character is a quote and whether it is escaped or not.
 */
void	quote_checker(char *str, int i, int *s_quote, int *d_quote)
{
	if (str[i] == '\'' && !(*d_quote))
	{
		if (i == 0 || str[i - 1] != '\\')
			*s_quote = !(*s_quote);
	}
	else if (str[i] == '"' && !(*s_quote))
	{
		if (i == 0 || str[i - 1] != '\\')
			*d_quote = !(*d_quote);
	}
}

/**
 * @brief This function checks and updates the status of quote marks based 
 * 	on the current and next characters in a string.
 * @param c The current character to check for a quote.
 * @param next_c The next character after the current character, used 
 * 	to determine if a quote should be closed.
 * @param s_quote Pointer to an int that indicates whether a 
 * 	single quote is currently open (1) or closed (0).
 * @param d_quote Pointer to an int that indicates whether a 
 * 	double quote is currently open (1) or closed (0).
 * @note This function is typically used to handle arguments 
 * 	where the end of a quote might depend on the following character.
 */
void	quote_checker_arg(char c, char next_c, int *s_quote, int *d_quote)
{
	if (c == '\'' && !(*d_quote))
	{
		if (*s_quote == 1 && (is_sep(next_c) || !next_c))
			*s_quote = 0;
		else if (*s_quote == 0)
			*s_quote = 1;
	}
	else if (c == '"' && !(*s_quote))
	{
		if (*d_quote == 1 && (is_sep(next_c) || !next_c))
			*d_quote = 0;
		else if (*d_quote == 0)
			*d_quote = 1;
	}
}

/**
 * @brief This function verifies whether the character at the 
 * 	specified position in the given string is within quotes.
 * @param str The string to examine.
 * @param pos The position of the character to check.
 * @param flag Determines the mode of quote checking :
 * 	flag 0, the function uses standard quote checking. 
 *	If flag is 1, it uses a different method that checks
 * 	the current and next characters (when dealing with specific argument types).
 * @return Returns 1 if the character is within single quotes, 
 *	2 if within double quotes, 
 *	and 0 if it's not within any quotes.
 */
int	is_in_quote(char *str, int pos, int flag)
{
	int	i;
	int	s_quote;
	int	d_quote;

	i = 0;
	s_quote = 0;
	d_quote = 0;
	while (str && str[i])
	{
		if (flag == 0)
			quote_checker(str, i, &s_quote, &d_quote);
		if (flag == 1)
			quote_checker_arg(str[i], str[i + 1], &s_quote, &d_quote);
		if (i == pos && (d_quote || s_quote))
		{
			if (d_quote)
				return (2);
			else
				return (1);
		}
		i++;
	}
	return (0);
}

/**
 * @brief This function removes adjacent single or double quotes 
 *	from the given string. It scans through the input line and eliminates 
 *	consecutive quotes, creating a new string without these adjacent quotes.
 * @param line The input string containing adjacent single or double quotes.
 * @return Returns a new string with adjacent quotes removed.
 *	The original input string is freed. 
 *	If memory allocation for the new string fails, returns NULL.
 */
char	*clean_adjacent_quotes(char *line)
{
	int		i;
	int		j;
	int		len;
	char	*new_line;

	i = 0;
	j = 0;
	len = ft_strlen(line);
	new_line = (char *)malloc(sizeof(char) * len + 1);
	if (!new_line)
		return (NULL);
	while (line[i] != '\0')
	{
		if ((line[i] == '\'' && line[i + 1] == '\'')
			|| (line[i] == '"' && line[i + 1] == '"'))
			i += 2;
		else
			new_line[j++] = line[i++];
	}
	new_line[j] = '\0';
	return (free(line), new_line);
}
