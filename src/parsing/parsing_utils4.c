/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellegr <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:48:39 by lpellegr          #+#    #+#             */
/*   Updated: 2024/09/11 20:48:40 by lpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	replace_err(char **arg, int i, t_all *all)
{
	char	*before_var;
	char	*after_var;
	char	*res;
	int		j;

	j = var_len(*arg, i + 1);
	before_var = my_substr(*arg, i + 1, j);
	after_var = ft_itoa(all->err);
	res = join_var(*arg, after_var, i + 1, j);
	free(after_var);
	*arg = return_replace_var(*arg, before_var, res);
}
