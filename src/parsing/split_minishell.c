#include "../../includes/minishell.h"

static void	*ft_free(char **res, int count)
{
	while (count >= 0)
	{
		free(res[count]);
		count--;
	}
	free(res);
	return (NULL);
}

static size_t	ft_countwords(char *s, char sep)
{
	size_t	count;
	int		i;

	if (!*s || !s)
		return (0);
	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == sep)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != sep)
			i++;
	}
	return (count);
}

static char	**word_malloc(char **res, char const *s, char sep)
{
	int		word_len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		word_len = 0;
		while (s[i] == sep && s[i])
			i++;
		while (s[i] != sep && s[i])
		{
			i++;
			word_len++;
		}
		if (word_len != 0)
		{
			res[j] = ft_calloc((word_len + 1), sizeof(char));
			if (!res[j])
				return (ft_free(res, j));
		}
		j++;
	}
	return (res);
}

static char	**word_copy(char **res, char const *s, char sep)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (s[i])
	{
		k = 0;
		while (s[i] == sep && s[i])
			i++;
		while (s[i] != sep && s[i])
		{
			res[j][k] = s[i];
			i++;
			k++;
		}
		if (k > 0)
			res[j][k] = '\0';
		j++;
	}
	return (res);
}

char	**ft_split(char const *s, char sep)
{
	char	**res;
	int		counter;

	if (!s)
		return (NULL);
	counter = ft_countwords(s, sep);
	res = (char **)ft_calloc((counter + 1), sizeof(char *));
	if (!res)
		return (NULL);
	res = word_malloc(res, s, sep);
	if (res == NULL)
		return (NULL);
	res = word_copy(res, s, sep);
	res[counter] = NULL;
	return (res);
}

// REWORKED VER



