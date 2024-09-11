/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_export.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:30:02 by livsauze          #+#    #+#             */
/*   Updated: 2024/09/11 19:30:03 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

/**
 * Checks if a character is a digit.
 * 
 * @param c The character to check.
 * @return 1 if the character is a digit, 0 otherwise.
 */
int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

/**
 * This function checks if a string is a valid environment variable name.
 * The string must start with a letter or an underscore and can only contain
 * letters, numbers or underscores.
 * 
 * @param str The string to check.
 * @return 1 if the string is valid, 0 otherwise.
 */
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

char	**ft_malloc_tab(int len, char *s, char sep)
{
	char	**res;

	// res = NULL;
	if (len > 1)
		res = malloc(sizeof(char *) * (len + 1));
	else if (len == 1)
	{
		if (ft_strchr(s, sep))
			res = malloc(sizeof(char *) * 3);
		else
			res = malloc(sizeof(char *) * (len + 1));
	}
	return (res);
}
