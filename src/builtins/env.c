//#include "minishell.h"
#include "../../includes/minishell.h"

/* @brief Prints environment variables
 * @return Nothing
*/

void	ft_env(t_env *env)
{
	while (env)
	{
		if (env->set == 1)
			printf("%s=%s\n", env->key, env->val);
		env = env->next;
	}
}
