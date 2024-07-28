//#include "minishell.h"
#include "../../includes/minishell.h"

void	ft_cd_home(t_env *env)
{
	ft_modify_env("OLDPWD", ft_getenv("PWD", env), env);
	if (chdir(ft_getenv("HOME", env)) == -1)
	{
		red();
		printf("cd: no such file or directory\n");
		reset();
		return ;
	}
	ft_modify_env("PWD", getcwd(NULL, 0), env);
}

void	ft_cd(t_data *data, t_env *env)
{
	if (ft_getenv("PATH", env) == NULL)
		return ;
	else if (!data->arg || data->arg[0][0] == '~')
		ft_cd_home(env);
	else
	{
		ft_modify_env("OLDPWD", ft_getenv("PWD", env), env);
		if (chdir(data->arg[0]) == -1)
		{
			red();
			printf("cd: no such file or directory\n");
			reset();
			return ;
		}
		ft_modify_env("PWD", getcwd(NULL, 0), env);
	}

}