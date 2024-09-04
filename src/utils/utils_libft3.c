//#include "minishell.h"
#include "../../includes/minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	ft_strlcat(char *dest, char *src, int size)
{
	int	i;
	int	j;
	int	lend;
	int	lens;

	lend = ft_strlen(dest);
	lens = ft_strlen(src);
	if (size == 0)
		return (lens);
	if (size < lend)
		return (lens + size);
	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j] && i < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (lens + lend);
}
