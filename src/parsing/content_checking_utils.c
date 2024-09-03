#include "../../includes/minishell.h"

/**
* @brief check if the given char is a separator (space, |, <, >)
* @return 1 if yes. 0 if not.
*/
int	is_sep(char c)
{
	return (c == ' ' || c == '|' || c == '<' || c == '>');
}

/**
 * @brief check if the given char is an ASCII digit.
 * @return 1 if yes. 0 if not.
 */
int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * @brief  Check if the given char is a whitespace
 * @return 1 if yes. 0 if not.
*/
int	is_whitespace(char c)
{
	//some missing ? sufficient i think
	return (c == ' ' || c == '\t' || c == '\n');
}

int	is_redir(char c)
{
	return (c == '>' || c == '<');
}
