
#include "minishell.h"

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
	// (void)envp;
	t_data	data;

	if (argc != 1)
	{
		printf("Error : Invalid arguments.\n");
		printf("Try : ./minishell\n");
		return (1);
	}
	data.env = NULL;
	ft_copy_env(data.env, envp);
	ft_prompt_loop();
}

// int	main(int argc, char **argv, char **envp)
// {
// }