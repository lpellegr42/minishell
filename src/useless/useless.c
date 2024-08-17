					// main.c


// char	*ft_get_prompt(char	*s1, char *s2, int flag)
// {
// 	char	*new;
// 	int	i;
// 	int	j;
// 	int	len;

// 	len = ft_strlen(s1) + ft_strlen(s2);
// 	i = 0;
// 	j = 0;
// 	new = malloc(sizeof(char) * (len + 1));
// 	while (s1 && s1[i])
// 	{
// 		new[i] = s1[i];
// 		i++;
// 	}
// 	while (s2 && s2[j])
// 	{
// 		new[i] = s2[j];
// 		i++;
// 		j++;
// 	}
// 	new[i] = '\0';
// 	if (flag == 1)
// 		free(s1);
// 	return (new);
// }

					// init_parsing.c

// void	data_delnode(t_data	*data)
// {
// 	if (data)
// 	{
// 		if (data->str)
// 			free(data->str);
// 		if (data->cmd)
// 			free(data->cmd);
// 		if (data->arg)
// 			free_tab_tab(data->arg);
// 		// add some free if i malloc anything else.
// 		free(data);
// 	}

// }

// void data_clear(t_all *all)
// {
// 	t_data *tmp;

// 	while (all->data)
// 	{
// 		tmp = all->data->next;
// 		data_delnode(all->data);
// 		all->data = tmp;
// 	}
// }

						// split_minishell.c

// #include <stdio.h>
// #include <stdlib.h>
// #include <stddef.h>

// int main(int argc, char **argv)
// {
// 	char **res;
// 	int i = 0;

// 	if (argc == 2)
// 	{
// 		res = shell_split(argv[1]);
// 		while(1)
// 		{
// 			printf("res[%d]:%s\n", i, res[i]);
// 			if (!res[i])
// 				break;
// 		}
// 	}
// 	return (0);
// }
