//#include "minishell.h"
#include "../../includes/minishell.h"

//FURTHER COMMENT AND ADD NEXT PARSING STEP
// Add free b_tree functions in the loop.

/**
 * @brief Main parsing funct
 * TODO further comment and fct rework 
*/

int	initial_check(char *line, t_all *all)
{
		
	if (empty_line_check(line) == 1)
		exit (127);
	if (is_unclosed_quotes(line) == 1)
	{
		ft_display_err("minishell: unclosed quote error\n", all, 0);		
		exit(all->err);
	}
	// if (/* VERIF PIPE FIN PIPE DEBUT*/)
	// if (/* VERIF REDIR VIDE */)
	return (1);
}

t_all	*parsing(char *line, t_all *all)
{
	t_data	*node;
	t_data	*root_node;

	if (!initial_check(line, all))
		return (NULL);
	node = init_node(line);
	root_node = node;
	node = fill_args(line, node);
	
	//node = parse_pipe(node);
		// securité si pas de pipe
	//node = parse_redir(node);

	all->data = root_node;
	return(all);
}

/**
 * @brief Create a new node with default value.
 */
t_data	*init_node(char *str)
{
	t_data	*new_node;

	new_node =  malloc(sizeof(t_data));
	if (!new_node)
		return (NULL);
	new_node->type = DEFAULT;
	new_node->str = my_strdup(str); //malloc'd
	new_node->cmd = NULL;
	new_node->arg = NULL;
	
	new_node->fd_in = NULL; //voir pour fd val par defaut
	new_node->fd_out = NULL;
	new_node->flag_out = NULL;
	
	new_node->next = NULL;
	return (new_node);
}

int	is_builtin(char **res)
{
	if (ft_strncmp(res[0], "env", 3) == 0)
		return (1);
	else if (ft_strncmp(res[0], "unset", 5) == 0)
		return (1);
	else if (ft_strncmp(res[0], "export", 6) == 0)
		return (1);
	else if (ft_strncmp(res[0], "echo", 4) == 0)
		return (1);
	else if (ft_strncmp(res[0], "pwd", 3) == 0)
		return (1);
	else if (ft_strncmp(res[0], "cd", 2) == 0)
		return (1);
	else if (ft_strncmp(res[0], "exit", 4) == 0)
		return (1);
	else
		return (0);
}

/**
 * 0 = builtin
 * 1 = exec
 */
void	builtin_or_exec(t_data *data, char **res, int *i, int flag)
{
	if (flag == 0)
	{
		data->cmd = res[*i];
	}
	else if (flag == 1)
	{
		data->cmd = NULL;
		data->arg[*i] = res[*i];
	}
	*i++;
}

t_data	*fill_args(char *line, t_data *data)
{
	char **res;
	int i;

	i = 0;
	if (!line)
		return (NULL);
	data = malloc(sizeof(t_data));
	res = split_shell(line, ' ');
	if (is_builtin(res))
		builtin_or_exec(data, res, &i, 0);
	else
		builtin_or_exec(data, res, &i, 1);
	while (res[i])
	{
		data->arg[i] = my_strdup(res[i]);
		i++;
	}
	data->arg[i] = NULL;
	free_tab_tab(res);
	return(data);
}


// // FOR REFERENCE

// /* @brief Real main of the project. Prints the prompt and read STDIN.
//  * @return Nothing
// */
// void	ft_prompt_loop(t_all *all)
// {
// 	char	*line;

// 	while (1)
// 	{
// 		blue();
// 		line = readline("Minishell > ");
// 		reset();
// 		add_history(line);
// 		if (g_signum)
// 		{
// 			all->err = 128 + g_signum;
// 			g_signum = 0;
// 		}
// 		if (line == NULL)
// 			ft_exit(all);
// 		//all->data = parse_args(line, all->data);
// 		all->data = parsing(line, all->data);
// 		ft_builtins(all);
// 		ft_reset_env(all);
// 		free(line);
// 		line = NULL;
// 	}
// }