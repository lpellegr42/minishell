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

/**
 * @brief Remove the element at the index i from an array of string.
 * @return The cleaned array.
 */
char	**array_remove_at(char **array, int i)
{
	int		j;
	int		k;
	char	**res;

	j = 0;
	k = 0;
	res = malloc(sizeof(char *) * tab_len(array));
	if (!res)
		return (NULL);
	while (array && array[j])
	{
		if (array[j] && j != i)
		{
			res[k] = my_strdup(array[j]);
			if (!res[k])
				return (free_tab_tab(res), NULL);
			k++;
		}
		j++;
	}
	res[k] = NULL;
	free_tab_tab(array);
	return (res);
}

/**
 * @brief Take a string as parameter and return it truncated at the pos len.
 * @return The cleaned string.
 */
char	*replace_data_line(char *line, int len)
{
	char	*temp;

	if (!line)
		return (NULL);
	temp = strldup(line, len);
	if (!temp)
		return (NULL);
	free(line);
	return (temp);
}
