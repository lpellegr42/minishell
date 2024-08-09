
#include "../../includes/minishell.h"

/**
* @brief check if the given char is a separator (space, |, <, >)
* @return 1 if yes. 0 if not.
*/
int	is_separator(char c)
{
	return (c == ' ' || c == '|' || c == '<' || c == '>');
}

/**
 * @brief check if the given char is an ASCII digit.
 * @return 1 if yes. 0 if not.
 */
int is_digit(char *c)
{
	return (c >= '0' && c <= '9');
}

/**
 * @brief check if the given string caontains only digit.
 * @return 1 if yes. 0 if not.
 */
int is_only_digit(char *str)
{
	int i;

	i = 0;
	while(str[i] && is_digit(str[i]))
	{
		i++;
	}
	if (i == ft_strlen(str))
		return (1);
	return (0);
}

/**
 * @brief  Check if the given char is a whitespace
 * @return 1 if yes. 0 if not.
*/
int is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'); //some missing ? sufficient i think
}

/**
 * @brief Check whether the given string contains only whitespace.
 * @return 1 if yes. 0 if not.
*/
int	is_only_whitespace(char *str)
{
	int i;

	i = 0;
	while(str[i] && is_whitespace(str[i]))
		i++;
	if (i == ft_strlen(str))
		return (1);
	return (0);

}

/** 
 * @brief Check if the given string (prompt) is empty.
 * @return 1 if the given string is empty or contains only whitespace 0 if not.
*/
int	empty_line_check(char *line)
{
	if (*line == '\0' || /* !line ||*/ is_only_whitespace(line))
		return (1);
	return (0);
}

int	is_redir(char c)
{
	return (c == '>' || c == '<');
}
