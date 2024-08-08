
#include "../../includes/minishell.h"

/*
* check if the given char is a separator (space, |, <, >)
* return 1 if yes.
* 0 if not.
*/
int	is_separator(char c)
{
	if (c == ' ' || c == '|' || c == '<' || c == '>')
		return (1);
	return (0);
}

int is_digit(char *c)
{
	return (c >= '0' && c <= '9');
}

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

/* Check if the given char is a whitespace
 * @return 1 if it is. 0 if not
*/
int is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

/*
 * @brief Check whether the current string is only whitespace in the given string
 * @return 1 if there's only whitespace 0 if there is not
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

/* @brief Check if the given string (prompt) is empty
 * @return 1 if the given string is empty or contains only whitespace
 * 0 if not.
*/
int	empty_line_check(char *line)
{
	if (*line == '\0' || /* !line ||*/ is_only_whitespace(line))
		return (1);
	return (0);
}