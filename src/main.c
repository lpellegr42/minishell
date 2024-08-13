#include "../includes/minishell.h"

int	g_signum = 0;

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

/* @brief Handles signals (ctrl -C | ctrl-\)
 * @return Nothing
*/
void	ft_handler(int sig, siginfo_t *s_info, void *context)
{
	(void)context;
	(void)s_info;
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_signum = sig;
	}
}
/* @brief Inits signals handler with struc sigaction
 * @return Nothing
*/
void	init_sig(int sig, void (*handler)(int, siginfo_t *, void *))
{
	struct sigaction	susr;

	susr.sa_sigaction = handler;
	susr.sa_flags = SA_SIGINFO;
	sigemptyset(&susr.sa_mask);
	if (sig == SIGINT)
		sigaction(SIGINT, &susr, 0);
	else if (sig == SIGQUIT)
		sigaction(SIGQUIT, &susr, 0);
}
/* @brief Real main of the project. Prints the prompt and read STDIN.
 * @return Nothing
*/
void	ft_prompt_loop(t_all *all)
{
	char	*line;

	while (1)
	{
		blue();
		line = readline("Minishell > ");
		reset();
		add_history(line);
		if (g_signum)
		{
			all->err = 128 + g_signum;
			g_signum = 0;
		}
		if (line == NULL)
			ft_exit(all);
		all->data = parse_args(line, all->data);
		//data = parsing(line); //the parsing will return command table that you can une in the exec. TODO
		ft_builtins(all);
		ft_reset_env(all);
		free(line);
		line = NULL;
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
	all.data = NULL;
	all.env = NULL;
	all.env_cpy = NULL;
	all.env = ft_copy_env(all.env, envp);
	ft_reset_env(&all);
	init_sig(SIGINT, &ft_handler);
	signal(SIGQUIT, SIG_IGN);
	ft_prompt_loop(&all);
}
