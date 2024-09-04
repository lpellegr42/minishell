#include "../../includes/minishell.h"

// char	*get_var(char *line, int i, t_all *all)
// {
// 	char	*str;
// 	char	*var;
// 	int		flag;
// 	int		j;
// 	int		k;

// 	k = 0;
// 	flag = is_digit(line[i]);
// 	// if (check_var(line))
// 	if (line[i] == '?')
// 	{
// 		str = ft_itoa(all->err);
// 		all->err = 0;
// 		return (str);
// 	}
// 	if (flag)
// 		i++;
// 	j = i;
// 	while (line[j] && line[j] != ' ')
// 		j++;
// 	str = malloc(sizeof(char) * (j - i + 1));
// 	while (i < j)
// 	{
// 		str[k] = line[i];
// 		i++;
// 		k++;
// 	}
// 	str[k] = '\0';
// 	if (!flag)
// 	{
// 		var = ft_getenv(str, all->env);
// 		return (free(str), var);
// 	}
// 	else
// 		return (str);
// }

/*
	if (res[i][0] == '$')
		data->arg[j] = my_strdup(get_var(res[i], 1, all));
*/


/*
"ahjgfdagf $VAR hfksjhfksehf $VAR ahgfjfge"

"ahjgfdagf "
$VAR
 "hfksjhfksehf $VAR ahgfjfge"
*/


/*

echo '$USER' = $USER

echo "$USER" = leo

*/

char	*join_var(char *arg, char *var, int i, int var_len)
{
	char	*res;
	int		j;
	int		k;

	int len = i + ft_strlen(var) + ft_len(arg, i + var_len);
	j = i + var_len;
	k = i + ft_strlen(var) - 1;
	res = malloc(sizeof(char) * (len + 1));
	ft_strlcpy(res, arg, i);
	if (var)
		res = ft_join(res, var);
	else
		ft_strlcat(res, 0, 0);
	while (arg[j])
	{
		res[k] = arg[j];
		k++;
		j++;
	}
	res[k] = '\0';
	return (res);
}

int	var_len(char *str, int i)
{
	int	count;

	count = 0;
	if (!str)
		return (0);
	while (str[i] && !is_whitespace(str[i]) && str[i] != '"' && str[i] != '$')
	{
		count++;
		i++;
	}
	return (count);
}

char	*return_replace_var(char *arg, char *before_var, char *res)
{
	char *ret;
	ret = ft_strdup(res);
	free(arg);
	free(res);
	free(before_var);
	return(ret);
}

int	replace_var(char **arg, int i, t_all *all)
{	
	char	*before_var;
	char	*after_var;
	char	*res;
	int	j;

	j = var_len(*arg, i + 1);
	before_var = my_substr(*arg, i + 1, j);
	after_var = ft_getenv(before_var, all->env);
	res = join_var(*arg, after_var, i + 1, j);
	*arg = return_replace_var(*arg, before_var, res);
	return (j - i);
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

char	*clean_var(char *arg, t_all *all)
{
	int i;

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