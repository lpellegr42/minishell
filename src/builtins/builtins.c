//#include "minishell.h"
#include "../../includes/minishell.h"

void	ft_builtins(char *line, t_data *data, t_env *env)
{
	if (ft_strncmp(line, "env", 3) == 0)
		ft_env(env);
	else if (ft_strncmp(line, "unset test", 11) == 0)
		ft_unset("test", data, env);
	else if(ft_strncmp(line, "export", 11) == 0)
		ft_export("export", data, &env);
}
