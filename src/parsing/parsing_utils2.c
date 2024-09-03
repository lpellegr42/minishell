#include "../../includes/minishell.h"

/**
 *  @brief Calculates the length of a string array (array of char pointers).
 *  @return The number of strings in the array (not including the NULL terminator).
 */
int	tab_len(char **tab)
{
	int i;

	i = 0;
	while(tab[i])
	{
		i++;
	}
	return(i);
}

/**
 * @brief Count the number of element in char ** array, skiping the first element.
 * @return The number of element in the array minus 1, 0 if there's is only one or less.
 */
int arg_tab_len(char **tab)
{
    int count = 0;

	tab++;
	while (*tab != NULL)
	{
		count++;
		tab++;
    }
	return (count);
}

int	delchar(char **str, int pos, char c)
{
	char	*new_str;
	int		i;
	int		j;

	if (str[0][pos] == c)
	{
		new_str = malloc(sizeof(char) * (ft_strlen(str[0])));
		i = 0;
		j = 0;
		while (str[0][i])
		{
			if (i != pos)
				new_str[j++] = str[0][i];
			i++;
		}
		new_str[j] = '\0';
		free(str[0]);
		str[0] = new_str;
		return (1);
	}
	return (0);
}

void	apply_all_clean(char **str, int *i)
{
	if ((delchar(str, *i, '\'') != 1)
		&& (delchar(str, *i, '"') != 1)
		&& (delchar(str, *i, ' ') != 1))
		(*i)++;
}

void apply_clean_on_args(t_data *node, t_all *all)
{
	int i;

	i = 0;
	if (node->cmd)
	{
		node->cmd = replace_var(node->cmd, all);
		node->cmd = clean_arg(node->cmd);
	}
	while (node->arg && node->arg[i])
	{
		node->arg[i] = replace_var(node->arg[i], all);
		node->arg[i] = clean_arg(node->arg[i]);
		i++;
	}
}

