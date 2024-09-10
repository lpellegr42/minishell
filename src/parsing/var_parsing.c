#include "../../includes/minishell.h"

char	*join_var(char *arg, char *var, int i, int var_len)
{
	char	*res;
	int		j;
	int		k;
	int		len;

	len = ft_strlen(arg) - (var_len + 1) + ft_strlen(var);
	j = i + var_len;
	k = i + ft_strlen(var) - 1;
	res = malloc(sizeof(char) * (len + 1));
	ft_strlcpy(res, arg, i);
	if (var)
		ft_strlcat(res, var, ft_strlen(var) + ft_strlen(res));
	else
		ft_strlcat(res, 0, 0);
	while (arg[j])
		res[k++] = arg[j++];
	res[k] = '\0';
	return (res);
}

char	*return_replace_var(char *arg, char *before_var, char *res)
{
	char	*ret;

	ret = ft_strdup(res);
	free(arg);
	free(res);
	free(before_var);
	return (ret);
}

int	replace_var(char **arg, int i, t_all *all)
{
	char	*before_var;
	char	*after_var;
	char	*res;
	int		j;

	j = var_len(*arg, i + 1);
	before_var = my_substr(*arg, i + 1, j);
	after_var = ft_getenv(before_var, all->env);
	res = join_var(*arg, after_var, i + 1, j);
	*arg = return_replace_var(*arg, before_var, res);
	return (0);
}

int	replace_nothing(char **arg, int i)
{
	char	*tmp;

	(*arg)[i] = '\0';
	tmp = ft_strjoin(*arg, &(*arg)[i + 2]);
	free(*arg);
	*arg = tmp;
	return (0);
}

char	*replace_var_on_arg(char *arg, t_all *all)
{
	int	i;

	i = 0;
	(void)all;
	while (arg[i])
	{
		if (is_in_quote(arg, i, 0) != 1)
		{
			if (arg[i] == '$' && is_digit(arg[i + 1]))
				i += replace_nothing(&arg, i);
			else if (arg[i] == '$' && arg[i + 1] != '\0')
				replace_var(&arg, i, all);
			else
				i++;
		}
		else
			i++;
	}
	return (arg);
}
