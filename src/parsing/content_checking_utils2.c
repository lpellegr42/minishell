#include "../../includes/minishell.h"

/**
 * @brief Check whether the given string contains only whitespace.
 * @return 1 if yes. 0 if not.
*/
int	is_only_whitespace(char *str, int i, int len)
{
	if (i >= len)
		return (0);
	while (str && str[i] && is_whitespace(str[i]) && i < len)
		i++;
	if (i == len)
		return (1);
	return (0);
}

/**
 * @brief check if the given string caontains only digit.
 * @return 1 if yes. 0 if not.
 */
int	is_only_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i] && is_digit(str[i]))
	{
		i++;
	}
	if (i == ft_strlen(str))
		return (1);
	return (0);
}
