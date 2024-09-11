/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:27:36 by livsauze          #+#    #+#             */
/*   Updated: 2024/09/11 19:27:39 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*ft_key(char *s, char sep)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	while (s[i] && s[i] != sep)
		i++;
	j = 0;
	res = malloc(sizeof(char) * (i + 1));
	i = 0;
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

int	ft_len_val(char *s, int i, char sep)
{
	int	count;

	count = 0;
	while (s[i] && s[i] != sep)
	{
		i++;
		count++;
	}
	return (count);
}

char	*ft_val(char *s, char sep)
{
	char	*res;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (s[i] && s[i] != sep)
		i++;
	i++;
	res = malloc(sizeof(char) * (ft_len_val(s, i, ' ') + 1));
	if (!res)
		return (NULL);
	while (s[i] && s[i] != ' ')
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
	res = ft_malloc_tab(len, s, sep);
	if (!res)
		return (NULL);
	j = 0;
	res[j] = ft_key(s, sep);
	if (len > 1)
		res[++j] = ft_val(s, sep);
	else if (len == 1 && ft_strchr(s, sep))
		res[++j] = ft_strdup("");
	if (res[j])
		res[j + 1] = NULL;
	return (res);
}
