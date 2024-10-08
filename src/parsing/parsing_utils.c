/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellegr <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:48:29 by lpellegr          #+#    #+#             */
/*   Updated: 2024/09/11 20:48:30 by lpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "minishell.h"
#include "../../includes/minishell.h"

/**
 * @brief The strchr() function returns a pointer to the first occurrence 
 * 		  of the character 'c' in the string 's'.
*/
char	*my_strchr(const char *s, int c)
{
	unsigned int	i;
	char			cc;

	i = 0;
	cc = (char) c;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *) &s[i]);
	return (NULL);
}

/**
 * @brief Return a substring from the string ’s’.
 * The substring begins at index ’start’ and is of maximum size ’len’.
*/
char	*my_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= my_strlen(s))
		return (my_strdup(""));
	if (len > my_strlen(s + start))
		len = my_strlen(s + start);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (len--)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/**   
 *	@brief The strdup() function returns a pointer to a new string 
 *		which is a duplicate of the string s.
 *		Memory for the new string is obtained with malloc(3), and 
 *		can be freed with free(3).
*/
char	*my_strdup(const char *s)
{
	int		i;
	char	*dest;

	dest = malloc(sizeof(char) * (my_strlen(s) + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * @brief Return the len of the string given as parameter.
 */
size_t	my_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
}
