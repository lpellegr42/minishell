#include "../../includes/minishell.h"

// void	*split_free(char **res)
// {
// 	int	i;

// 	while (res[i])
// 	{
// 		free(res[i]);
// 		i++;
// 	}
// 	free(res);
// 	return (NULL);
// }

int	minishell_countchar(char *s, char sep)
{
	int	i;

	i = 0;
	while(*(s + i) && *(s + i) != sep || is_in_quote(s, i))
	{
		if (i == 0 && is_redir_token(*(s + i))) // si la chaine contient une redir en premier char.
		{
			if (is_redir_token(*(s + i + 1))) // '<<' ou '>>'
				/* return (2) */
			return (1); // simple redir
		}
		else if
	}
}

int	countwords(char *s, char sep)
{
	int		count;
	int		i;

	if (!*s || !s)
		return (0);
	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == sep && !is_in_quote(s, i))
			i++;
		if (s[i])
		{
			i += minishell_countchar(&s[i], sep); //right order ? will calculate the next word len taking account token and quotes.
			count++;
		}
	}
	return (count);
}

char	*strldup(char *s, int len)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	while (*(s + i) != '\0' && i < len)
	{
		*(dest + i) = *(s + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
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

char	**ft_split(char *s, char sep)
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



