/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:29:43 by livsauze          #+#    #+#             */
/*   Updated: 2024/09/11 19:30:35 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	lens;

	lens = ft_strlen(s);
	if (start >= lens)
		return ((char *)ft_strdup(""));
	if (len + start >= lens)
		str = (char *)malloc(sizeof(char) * (lens - start + 1));
	if (len + start < lens)
		str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = start;
	j = 0;
	while (i < lens && j < len)
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
