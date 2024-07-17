#include "minishell.h"

void	ft_prompt_loop(t_env *env)
{
	char	*home;
	char	*line;
	char	*prompt;
	t_data	*data;

	while (1)
	{
		home = getenv("PWD");
		prompt = ft_strjoin("Minishell : ", home);
		prompt = ft_strjoin(prompt, "$ ");
		line = readline(prompt);
		data = parsing(line); //the parsing will return command table that you can une in the exec. TODO
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

// int	main(int argc, char **argv, char **envp)
// {
// }