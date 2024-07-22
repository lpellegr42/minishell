#include "../includes/minishell.h"

void	ft_print_data(t_data *lst)
{
	int i =  0;
	while (lst)
	{
		printf("%s\n", lst->cmd);
		while (lst->arg && lst->arg[i])
		{
			printf("arg : %s\n", lst->arg[i]);
			i++;
		}
		lst = lst->next;
	}
}

void	ft_prompt_loop(t_env *env)
{
	char	*home;
	char	*line;
	char	*prompt;
	t_data	*data;
	(void)env;

	data = NULL;
	while (1)
	{
		home = getenv("PWD");
		prompt = ft_strjoin("Minishell : ", home);
		prompt = ft_strjoin(prompt, "$ ");
		blue();
		line = readline(prompt);
		reset();
		add_history(line);
		data = parse_args(line, data);
		//data = parsing(line); //the parsing will return command table that you can une in the exec. TODO
		ft_builtins(data, env);
	}
}


int	main(int argc, char **argv, char **envp)
{
	t_env	*env;

	(void)argv;
	if (argc != 1)
	{
		printf("Error : Invalid arguments.\n");
		printf("Try : ./minishell\n");
		return (1);
	}
	env = NULL;
	env = ft_copy_env(env, envp);
	ft_prompt_loop(env);
}
