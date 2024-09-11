#include "../../includes/minishell.h"

void	replace_err(char **arg, int i, t_all *all)
{
	char	*before_var;
	char	*after_var;
	char	*res;
	int		j;

	j = var_len(*arg, i + 1);
	before_var = my_substr(*arg, i + 1, j);
	after_var = ft_itoa(all->err);
	res = join_var(*arg, after_var, i + 1, j);
	free(after_var);
	*arg = return_replace_var(*arg, before_var, res);
}
