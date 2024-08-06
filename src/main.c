#include "../includes/minishell.h"



char	*ft_get_prompt(char	*s1, char *s2, int flag)
{
	char	*new;
	int	i;
	int	j;
	int	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	new = malloc(sizeof(char) * (len + 1));
	while (s1 && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2 && s2[j])
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[i] = '\0';
	if (flag == 1)
		free(s1);
	return (new);
}

void	ft_prompt_loop(t_all *all)
{
	char	*line;

	while (1)
	{
		blue();
		line = readline("Minishell > ");
		reset();
		add_history(line);
		all->data = parse_args(line, all->data);
		//data = parsing(line); //the parsing will return command table that you can une in the exec. TODO
		ft_builtins(all);
		free(line);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_all	all;

	(void)argv;
	if (argc != 1)
	{
		printf("Error : Invalid arguments.\n");
		printf("Try : ./minishell\n");
		return (1);
	}
	all.err = 0;
	all.env = NULL;
	all.env = ft_copy_env(all.env, envp);
	ft_prompt_loop(&all);
}
