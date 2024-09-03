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

char*	replace_var(char *arg)
{	
	char **res;
	int	i;

	i = 0;
	while(arg[i])
	{
		if (arg[i] == '$' && is_in_quote(arg, i, 0) != 2)
	}
}