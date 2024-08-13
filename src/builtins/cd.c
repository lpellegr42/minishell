//#include "minishell.h"
#include "../../includes/minishell.h"

/* @brief Changes the working directory to home
 * @return Nothing
*/
void	ft_cd_home(t_all *all)
{
	char	**buf;

	buf = malloc(sizeof(char *) * 1);
	buf[0] = malloc(sizeof(char) * 4096);
	if (chdir(ft_getenv("HOME", all->env)) == -1)
	{
		ft_display_err("cd: no such file or directory\n", all, 1);
		return ;
	}
	ft_modify_env("OLDPWD", ft_getenv("PWD", all->env), all->env);
	ft_modify_env("PWD", getcwd(buf[0], 4096), all->env);
	free(buf[0]);
	free(buf);
}
/* @brief Changes the working directory
 * @return Nothing
*/
void	ft_cd(t_all *all)
{
	char	**buf;

	if (!all->data->arg || all->data->arg[0][0] == '~')
		ft_cd_home(all);
	else
	{
		buf = malloc(sizeof(char *) * 1);
		buf[0] = malloc(sizeof(char) * 4096);
		if (!getcwd(buf[0], 4096))
		{
			printf("cd: error retrieving current directory: ");
			printf("getcwd: cannot access parent directories: ");
			ft_display_err("no such file or directory\n", all, 0);
			return (free(buf[0]), free(buf));
		}
		if (chdir(all->data->arg[0]) == -1)
		{
			ft_display_err("cd: no such file or directory\n", all, 1);
			return ;
		}
		ft_modify_env("OLDPWD", ft_getenv("PWD", all->env), all->env);
		ft_modify_env("PWD", getcwd(buf[0], 4096), all->env);
		free(buf[0]);
		free(buf);
	}
}
