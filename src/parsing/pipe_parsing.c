/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellegr <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:48:43 by lpellegr          #+#    #+#             */
/*   Updated: 2024/09/11 20:48:44 by lpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Search for the a pipe char '|' in the given string.
 * @return 	Return the position of the first pipe found 
 * in the given string. -1 if none is found.
*/
int	search_pipe(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '|' && str[i - 1] != '\\' && !is_in_quote(str, i, 1))
			return (i);
		i++;
	}
	return (-1);
}

int	check_start_pipe(char *line)
{
	int	i;

	i = 0;
	while (line[i] && is_whitespace(line[i]))
		i++;
	if (line[i] == '|')
		return (1);
	return (0);
}

int	check_middle_pipes(char *line)
{
	int	i;
	int	j;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '|')
		{
			j = i - 1;
			while (j >= 0 && is_whitespace(line[j]))
				j--;
			if (j < 0 || line[j] == '|')
				return (1);
			j = i + 1;
			while (is_whitespace(line[j]))
				j++;
			if (line[j] == '|' || line[j] == '\0')
				return (1);
		}
		i++;
	}
	return (0);
}

int	check_end_pipe(char *line)
{
	int	i;

	i = ft_strlen(line) - 1;
	while (i >= 0 && is_whitespace(line[i]))
		i--;
	if (line[i] == '|')
		return (1);
	return (0);
}

void	parse_pipe(t_data *data)
{
	int		pipe_pos;

	pipe_pos = search_pipe(data->line);
	if (pipe_pos == -1)
		return ;
	while (pipe_pos != -1)
	{
		data->next = init_node();
		data->next->line = strldup(&data->line[pipe_pos + 1],
				ft_strlen(&data->line[pipe_pos + 1]));
		data->line = replace_data_line(data->line, pipe_pos);
		data = data->next;
		pipe_pos = search_pipe(data->line);
	}
}
