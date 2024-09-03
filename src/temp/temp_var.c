//#include "minishell.h"
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

	// printf("ft_len: %d\n",  var_len);
	int len = i + ft_strlen(var) + ft_len(arg, i + var_len);
	j = i + var_len;
	k = i + ft_strlen(var) - 1;
	res = malloc(sizeof(char) * (len + 1));
	// printf("%d\n", len);
	ft_strlcpy(res, arg, i);
	// printf("res1:%s\n", res);
	// if (var)
	// {	
		res = ft_join(res, var);
		// printf("res2:%s\n", res);
	// }
	// else
	// 	ft_strlcat(res, 0, 0);
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
	while (str[i] && !is_whitespace(str[i]) && str[i] != '"' && str[i] != '\'' && str[i] != '$' && str[i] != '\0')
	{
		count++;
		i++;
	}
	// printf("var_len = %d\n", count);
	return (count);
}

char	*return_replace_var(char *arg, char *before_var, char *res)
{
	char *ret;
	//printf("%s\n", res);
	ret = ft_strdup(res);
	free(arg);
	free(res);
	free(before_var);
	return(ret);
}

int	replace_var(char **arg, t_all *all)
{	
	char	*before_var;
	char	*after_var;
	char	*res;
	int	i;

	i = 0;
	// while(*arg[i])
	// {
	// 	if (*arg[i] == '$' && is_in_quote(*arg, i, 0) != 1 && !is_whitespace(*arg[i + 1]) && *arg[i + 1] != '\0')
	// 	{
	// 		//write(1, &arg[i], 1);

			before_var = my_substr(*arg, i + 1, var_len(*arg, i + 1));
			after_var = ft_getenv(before_var, all->env);
			// printf("before : %s, after : %s\n", before_var, after_var);
			// if (after_var != NULL)
			// {
				res = join_var(*arg, after_var, i + 1, var_len(*arg, i + 1));
				// printf("res : %s\n", res);
				i += var_len(*arg, i);
				*arg = return_replace_var(*arg, before_var, res);
				//return (free(arg), free(before_var), res);
			// }
		// }
		// else
		// 	i++;
	// }
	return (i);
}

int replace_nothing(char **arg, int i)
{
    char *temp;
    int len = strlen(*arg);
    (*arg)[i] = '\0';
    temp = (char *)malloc(len + strlen(*arg + i + 2) + 1);
	
    strcpy(temp, *arg);
    strcat(temp, *arg + i + 2);
    free(*arg);
    *arg = temp;
    return (0);
}

char	*clean_var(char *arg, t_all *all)
{
	int i;

	i = 0;
	while(arg[i])
	{
		if (arg[i] == '$' && is_digit(arg[i + 1]))
			i += replace_nothing(&arg, i);
		else if (arg[i] == '$' && is_in_quote(arg, i, 0) != 1 && !is_whitespace(arg[i + 1]) && arg[i + 1] != '\0')
			i += replace_var(&arg, all);
		else
			i++;	
	}
	return (arg);
}