//#include "minishell.h"
#include "../../includes/minishell.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_isvalid(char *str)
{
	int	i;

	i = 1;
	if (!ft_isalpha(str[0]) && str[0] != '_')
		return (0);
	while (str[i] && str[i] != '=')
	{
		if (!ft_isalpha(str[i]) && !ft_isdigit(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_node(char *s1, char *s2)
{
	if (s1 && s2 && ft_strncmp(s1, s2, ft_strlen(s2)) == 0)
		return (0);
	if (s1 && ft_strncmp(s1, "_", 1) == 0)
		return (0);
	return (1);
}
