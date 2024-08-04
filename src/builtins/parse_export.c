//#include "minishell.h"
#include "../../includes/minishell.h"

int	ft_count_words(char *s, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	else
		count++;
	while (s[i] && s[i] != sep)
		i++;
	if (s[i] == sep && s[i + 1])
		count++;
	return (count);
}

int	ft_len_key(char *s, char sep)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != sep)
		i++;
	return (i);
}

char	*ft_key(char *s, char sep)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	res = malloc(sizeof(char) * (ft_len_key(s, sep) + 1));
	while (s[i] && s[i] != sep)
	{
		while (s[i] == '\"')
			i++;
		res[j] = s[i];
		i++;
		j++;
	}
	res[j] = '\0';
	return (res);
}

char	*ft_val(char *s, char sep)
{
	char	*res;
	int		i;
	int		j;

	j = 0;
	i = ft_len_key(s, sep) + 1;
	res = malloc(sizeof(char) * (ft_len(s, i) + 1));
	if (!res)
		return (NULL);
	while (s[i])
	{
		while (s[i] == '\"')
			i++;
		res[j] = s[i];
		j++;
		i++;
	}
	res[j] = '\0';
	return (res);
}

char	**ft_split_export(char *s, char sep)
{
	char	**res;
	int		len;
	int		j;

	len = ft_count_words(s, sep);
	if (len)
	{
		j = 0;
		res = malloc(sizeof(char *) * (len + 1));
		if (!res)
			return (NULL);
		res[j] = ft_key(s, sep);
		if (len > 1)
			res[++j] = ft_val(s, sep);
		else if (len <= 1 && ft_strchr(s, sep))
			res[++j] = ft_strdup("");
	}
	res[j + 1] = NULL;
	return (free(s), res);
}
