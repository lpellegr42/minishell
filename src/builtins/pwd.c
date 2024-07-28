//#include "minishell.h"
#include "../../includes/minishell.h"

void	ft_pwd(t_env *env)
{
	printf("%s\n", ft_getenv("PWD", env));
}