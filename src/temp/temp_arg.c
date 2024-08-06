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

t_data	*parse_args(char *line, t_data *data)
{
	char **res;
	int i = 1;
	int j = 0;
	int k = 0;

	if (!line)
		return (NULL);
	data = malloc(sizeof(t_data));
	res = ft_split(line, ' ');

	data->cmd = ft_strdup(res[0]);
	if (res[i])
	{
		data->arg = malloc(sizeof(char *) * (tab_len(res)));
		while (res[i])
		{
			data->arg[j] = malloc(sizeof(char) * (ft_strlen(res[i]) + 1));
			k = 0;
			while(res[i][k])
			{
				data->arg[j][k] = res[i][k];
				k++;

			}
			data->arg[j][k] = '\0';
			i++;
			j++;
		}
		data->arg[j] = NULL;
	}
	else
	{
		data->arg = NULL;
	}
	data->fd_out = 0;
	data->fd_in = 0;
	data->flag_out = 0;
	data->here_doc = NULL;
	data->next = NULL; 
	free_tab(res);
	return(data);
}
