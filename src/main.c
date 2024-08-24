#include "../includes/minishell.h"

int	g_signum = 0;

/* @brief Handles signals (ctrl -C | ctrl-\)
 * @return Nothing
*/
void	ft_handler(int sig, siginfo_t *s_info, void *context)
{
	(void)context;
	(void)s_info;
	if (waitpid(-1, NULL, WNOHANG) == -1)
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
	susr.sa_flags = SA_RESTART;
	sigemptyset(&susr.sa_mask);
	if (sig == SIGINT)
		sigaction(SIGINT, &susr, 0);
	else if (sig == SIGQUIT)
		sigaction(SIGQUIT, &susr, 0);
}

void	ft_check_sig(t_all *all)
{
	if (g_signum)
	{
		all->err = 128 + g_signum;
		g_signum = 0;
	}
}

/* @brief Real main of the project. Prints the prompt and read STDIN.
 * @return Nothing
*/
void	ft_prompt_loop(t_all *all)
{
	char	*line;

	while (1)
	{
		line = readline("Minishell > ");
		ft_check_sig(all);
		if (line == NULL)
		{
			ft_free_env(all->env);
			clear_history();
			printf("exit\n");
			return ;
		}
		if (initial_check(line, all))
		{
			add_history(line);
			all = parsing(line, all);
			if (all->data)
				ft_exec(all);
		}
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
	all.env = ft_copy_env(all.env, envp);
	init_sig(SIGINT, &ft_handler);
	signal(SIGQUIT, SIG_IGN);
	ft_prompt_loop(&all);
}