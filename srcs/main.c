#include "minishell.h"

void	ft_prompt_loop(t_env *env)
{
	char	*home;
	char	*line;
	char	*prompt;

	while (1)
	{
		home = getenv("PWD");
		prompt = ft_strjoin("Minishell : ", home);
		prompt = ft_strjoin(prompt, "$ ");
		line = readline(prompt);
		init_parsing(line);
		ft_builtins(line, env);
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