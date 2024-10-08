/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellegr <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:48:23 by lpellegr          #+#    #+#             */
/*   Updated: 2024/09/11 20:48:24 by lpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	initial_check(char *line, t_all *all)
{
	if (empty_line_check(line) == 1)
		return (0);
	if (is_unclosed_quotes(line) == 1)
	{
		ft_display_err ("minishell: unclosed quote error\n", all, 0);
		return (0);
	}
	if (empty_pipe_check(line) == 1)
	{
		printf("minishell: ");
		ft_display_err("syntax error near unexpected token `|'\n", all, 2);
		return (0);
	}
	if (redir_error_check(line) == 1 || pipe_follow_redir_check(line) == 1)
	{
		printf("minishell: ");
		ft_display_err("syntax error near redirection token\n", all, 2);
		return (0);
	}
	if (is_only_quote(line) == 1)
	{
		ft_display_err ("minishell: syntax error\n", all, 0);
		return (0);
	}
	return (1);
}

/**
 * @brief Main parsing funct
 * TODO further comment and fct rework 
*/
t_all	*parsing(char *line, t_all *all)
{
	t_data	*root_node;
	t_data	*node;

	node = init_node();
	root_node = node;
	node->line = my_strdup(line);
	node->line = clean_adjacent_quotes(node->line);
	parse_pipe(node);
	while (node)
	{
		node = fill_args(node);
		apply_clean_on_args(node, all);
		parse_redir(node);
		node = node->next;
	}
	all->data = root_node;
	return (all);
}

/**
 * @brief Create a new node with default value.
 */
t_data	*init_node(void)
{
	t_data	*new_node;

	new_node = malloc(sizeof(t_data));
	if (!new_node)
		return (NULL);
	new_node->line = NULL;
	new_node->cmd = NULL;
	new_node->arg = NULL;
	new_node->fd = -1;
	new_node->flag_redir = -1;
	new_node->next = NULL;
	return (new_node);
}

t_data	*fill_args(t_data *data)
{
	char	**res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!data->line)
		return (NULL);
	res = shell_split(data->line, ' ');
	data->cmd = my_strdup(res[i++]);
	if (arg_tab_len(res) > 0)
		data->arg = malloc(sizeof(char *) * (arg_tab_len(res) + 1));
	if (!data->arg)
		return (free_tab_tab(res), data);
	while (res[i] != NULL)
	{
		data->arg[j] = my_strdup(res[i]);
		i++;
		j++;
	}
	data->arg[j] = NULL;
	return (free_tab_tab(res), data);
}
