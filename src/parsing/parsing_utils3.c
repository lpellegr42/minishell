#include "../../includes/minishell.h"

/**
 * @brief Frees a dynamically allocated array of strings and the array itself.
 * @param res A pointer to the first element of the array of strings to be freed.
 * @param count The number of strings in the array that need to be freed.
 */
void	split_free(char **res, int count)
{
	while (count > 0)
		free(res[--count]);
	free(res);
}

char	*clean_arg(char *str)
{
	int		i;
	int		j;
	char	*dupstr;

	dupstr = my_strdup(str);
	i = 0;
	j = 0;
	while (dupstr[j])
	{
		if (is_in_quote(dupstr, j, 0) == 1)
		{
			if (delchar(&str, i, '\'') != 1)
				i++;
		}
		else if (is_in_quote(dupstr, j, 0) == 2)
		{
			if (delchar(&str, i, '"') != 1)
				i++;
		}
		else
			apply_all_clean(&str, &i);
		j++;
	}
	free(dupstr);
	return (str);
}

int	var_len(char *str, int i)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (str[i] && !is_whitespace(str[i]) && str[i] != '"'
		&& str[i] != '\'' && str[i] != '$')
	{
		count++;
		i++;
	}
	return (count);
}
