#include "../includes/minishell.h"

void	ft_copy_env(t_env *env, char **envp)
{
	int	i;
	int	j;
	
	i = 0;
	while (envp[i])
		i++;
	env = malloc(sizeof(t_env) * i);
	i = 0;
	while (envp[i])
	{
		j = 0;
		env[i].key = malloc(sizeof(char) * ft_strlen(envp[i]));
		while (envp[i][j] && envp[i][j] != '=')
		{
			env[i].key[j] = envp[i][j];
			j++;
		}
		if (envp[i][j] == '=')
		{
			env[i].key[j] = envp[i][j];
			j++;
		}
		printf("env : %s\n", env[i].key);
		i++;
	}
}
