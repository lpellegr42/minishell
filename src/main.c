#include "../includes/minishell.h"

void	ft_prompt_loop(t_env *env)
{
	char	*home;
	char	*line;
	char	*prompt;
	(void)env;
	t_cmdtree	*node;

	node = NULL;
	while (1)
	{
		home = getenv("PWD");
		prompt = ft_strjoin("Minishell : ", home);
		prompt = ft_strjoin(prompt, "$ ");
		line = readline(prompt);
		//data = parse_args(line);
		//node = parsing(line); //the parsing will return command table that you can use in the exec. TODO
		printf("quote return: %d\n", unclosed_quotes_check(line));
		//ft_builtins(line, data, env);
		if (strncmp("exit", line, 4) == 0)
		{
			free_tree(node);
			exit(EXIT_SUCCESS);
		}
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