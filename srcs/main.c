
#include "minishell.h"

// int	main(void)
// {
// 	char	*line;

// 	while (1)
// 	{
// 		line = readline("Enter a line : ");
// 		printf("line : %s\n", line);
// 	}
// }

void	ft_prompt_loop()
{
	char	*home;
	char	*line;
	char	*prompt;

	while (1)
	{
		home = getenv("PWD");
		prompt = ft_strjoin("Minishell : ", home);
		prompt = ft_strjoin(prompt, "\n");
		line = readline(prompt);
		printf("line : %s\n", line);
	}
}

int	main(int argc, char **argv, char **envp)
{
	(void)argv;
	(void)envp;
	// t_env	env;

	if (argc != 1)
	{
		printf("Error : Invalid arguments.\n");
		printf("Try : ./minishell\n");
		return (1);
	}
	// ft_copy_env(env, envp);
	ft_prompt_loop();
}

// int	main(int argc, char **argv, char **envp)
// {
// }