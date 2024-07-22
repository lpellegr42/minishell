#include "../../includes/minishell.h"

void free_tab(char **tab)
{
	int i;

	i = 0;
	while(tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

// utils for liv_to_start

// t_data	*parse_args(char *line, t_data *data)
// {
// 	char **res;
// 	int i = 1;
// 	int j = 0;

// 	data = malloc(sizeof(t_data));
// 	res = ft_split(line, ' ');
// 	data->cmd = res[0];
// 	while(res[i])
// 	{
// 		data->arg[j] = res[i];
// 		i++;
// 		j++;
// 	}
// 	data->fd_out = NULL;
// 	data->fd_in = NULL;
// 	data->flag_out = NULL;
// 	data->here_doc = NULL;
// 	data->next = NULL; 
// 	free_tab(res);
// 	return(data);
// }
