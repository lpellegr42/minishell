#include "../../includes/minishell.h"

/* Frees the double array 'res' if there's error */
static void	*ft_free_split(char **res, int count)
{
	while (count >= 0)
	{
		free(res[count]);
		count--;
	}
	free(res);
	return (NULL);
}

/* Count the number of 'words' separated by seperator given as argument. */
static int	ft_count_words(char const *s, char sep)
{
	int	count;
	int	i;

	if (!*s)
		return (0);
	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == sep)
			i++;
		if (s[i])
			count++;
		while (s[i] != sep && s[i])
			i++;
	}
	return (count);
}

/* Malloc the size of the words itself */
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
			res[j] = malloc(sizeof(char) * (word_len + 1));
			if (!res[j])
				return (ft_free_split(res, j));
		}
		j++;
	}
	return (res);
}

/* Copy the words in the malloc'ed string in the double array */
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
	counter = ft_count_words(s, sep);
	res = (char **)malloc(sizeof(char *) * (counter + 1));
	if (!res)
		return (NULL);
	res = word_malloc(res, s, sep);
	if (res == NULL)
		return (NULL);
	res = word_copy(res, s, sep);
	res[counter] = NULL;
	return (res);
}
