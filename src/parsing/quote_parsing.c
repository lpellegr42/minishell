#include "../../includes/minishell.h"

void	quote_checker(char *str, int i, int *s_quote, int *d_quote)
{
	if (str[i] == '\'')
	{
		if ((i = 0 || str[i - 1]  == '\\') &&!(*s_quote) && !(*d_quote))
			*s_quote = 1;
		if (*s_quote == 1)
			*s_quote = 0;
	}
	else if (str[i] == '"')
	{
		if ((i = 0 || str[i - 1]  == '\\') && !(*s_quote) && !(*d_quote))
			*d_quote = 1;
		else if ((i = 0 || str[i - 1]  == '\\') && *d_quote == 1)
			*d_quote = 0;
	}
}

void	quote_checker_arg(char c, char next_c, int *s_quote, int *d_quote)
{
	if (c == '\'' && !(*d_quote))
	{
		if (*s_quote == 1 && (is_sep(next_c) || !next_c))
			*s_quote = 0;
		else
			*s_quote = 1;
	}
	else if (c == '"' && !(*d_quote))
	{
		if (*d_quote == 1 && (is_sep(next_c) || !next_c))
			*d_quote = 0;
		else
			*d_quote = 1;
	}
}

/**
 * @brief This function verifies whether the character at the specified position 
 *	in the given string is within quotes.
 * @param str The string to examine.	
 * @param pos The position of the character to check.
 * @return Returns 1 if the character is within single quotes, 2 if within double quotes, 
 * and 0 if it's not within any quotes.
 */
int	is_in_quote(char *str, int pos, int flag)
{
	int	i;
	int	s_quote;
	int	d_quote;

	i = 0;
	s_quote = 0;
	d_quote = 0;
	while(str && str[i] && i < pos) //i < pos good condition ? not sure
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

/* ANCIEN */

// Add quote counter for initial verification, need to code quote counter function. IZI

// int	is_unclosed_quotes(char *line)
// {
// 	if (count_double_quotes(line) % 2 == 0 && count_single_quotes(line) % 2 == 0)
// 		return (0);
// 	return (1);
// }