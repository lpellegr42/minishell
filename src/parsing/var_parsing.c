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

	j = i + var_len;
	k = i + ft_strlen(var);
	res = malloc(sizeof(char) * (i + ft_strlen(var) + ft_len(arg, var_len) + 1));
	ft_strlcpy(res, arg, i);
	ft_strlcat(res, var, ft_strlen(var));
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
	while (str[i] && !is_whitespace(str[i]))
	{
		count++;
		i++;
	}
	printf("var_len = %d\n", count);
	return (count);
}

char*	replace_var(char *arg, t_all *all)
{	
	char	*before_var;
	char	*after_var;
	char	*res;
	int	i;

	i = 0;
	while(arg[i])
	{
		if (arg[i] == '$' && is_in_quote(arg, i, 0) != 2)
		{
			before_var = my_substr(arg, i + 1, var_len(arg, i + 1));
			after_var = ft_getenv(before_var, all->env);
			printf("before : %s, after : %s\n", before_var, after_var);
			if (after_var != NULL)		
				res = join_var(arg, after_var, i, var_len(arg, i));
		}
		i++;
	}
	return (res);
}
