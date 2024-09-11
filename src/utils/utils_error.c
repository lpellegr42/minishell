/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellegr <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:47:30 by lpellegr          #+#    #+#             */
/*   Updated: 2024/09/11 20:47:31 by lpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/**
 * @brief Prints the string given in parameter and sets the correct error status
 * @return Nothing
*/
void	ft_display_err(char *s, t_all *all, int err_status)
{
	all->err = err_status;
	printf("%s", s);
}
