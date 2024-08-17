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
	//node = parse_pipe(node);
		// securité si pas de pipe a verif - faire fct de trim de pipe fin et pipe debut.
	//node = parse_redir(node);
	node = fill_args(line, node);
	

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
	new_node->str = my_strdup(str); //char *
	new_node->cmd = NULL; //char *
	new_node->arg = NULL; //char **
	
	new_node->fd_in = -1; //voir pour fd val par defaut
	new_node->fd_out = -1;
	new_node->flag_out = -1;
	new_node->here_doc = NULL;
	
	new_node->next = NULL;
	return (new_node);
}

void	data_delnode(t_data	*data)
{
	if (data)
	{
		if (data->str)
			free(data->str);
		if (data->cmd)
			free(data->cmd);
		if (data->arg)
			free_tab_tab(data->arg);
		// add some free if i malloc anything else.
		free(data);
	}

}
void data_clear(t_all *all)
{
	t_data *tmp;

	while (all->data)
	{
		tmp = all->data->next;
		data_delnode(all->data);
		all->data = tmp;
	}
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

t_data	*fill_args(char *line, t_data *data)
{
	char **res;
	int i;
	int	j;

	i = 0;
	j = 0;
	if (!line)
		return (NULL);
	res = shell_split(line, ' ');
	data->cmd = my_strdup(res[i++]);
	data->arg = malloc(sizeof(char *) * (arg_tab_len(res) + 1));
	if (!data->arg)
		return (data);
	while (res[i] != NULL)
	{
		data->arg[j] = my_strdup(res[i]);
		i++;
		j++;
	}
	data->arg[j] = NULL;
	return(free_tab_tab(res), data);
}
