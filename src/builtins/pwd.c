/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:28:21 by livsauze          #+#    #+#             */
/*   Updated: 2024/09/11 19:28:23 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* @brief Displays the current working directory
 * @return Nothing
*/
void	ft_pwd(t_all *all)
{
	char	**buf;

	buf = malloc(sizeof(char *) * 1);
	buf[0] = malloc(sizeof(char) * 4096);
	if (!getcwd(buf[0], 4096))
	{
		all->err = 1;
		return ;
	}
	printf("%s\n", getcwd(buf[0], 4096));
	free(buf[0]);
	free(buf);
	all->err = 0;
}
