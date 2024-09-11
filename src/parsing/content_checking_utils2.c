/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   content_checking_utils2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellegr <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:48:19 by lpellegr          #+#    #+#             */
/*   Updated: 2024/09/11 20:50:05 by lpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Check whether the given string contains only whitespace.
 * @return 1 if yes. 0 if not.
*/
int	is_only_whitespace(char *str, int i, int len)
{
	if (i >= len)
		return (0);
	while (str && str[i] && is_whitespace(str[i]) && i < len)
		i++;
	if (i == len)
		return (1);
	return (0);
}

/**
 * @brief check if the given string caontains only digit.
 * @return 1 if yes. 0 if not.
 */
int	is_only_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i] && is_digit(str[i]))
		i++;
	if (i == ft_strlen(str))
		return (1);
	return (0);
}

int	is_quote(char c)
{
	return (c == '"' || c == '\'');
}

int	is_only_quote(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (is_quote(str[i]) || is_whitespace(str[i])))
		i++;
	if (i == ft_strlen(str))
		return (1);
	return (0);
}
