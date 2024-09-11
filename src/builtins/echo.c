/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:27:02 by livsauze          #+#    #+#             */
/*   Updated: 2024/09/11 19:27:05 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_check_echo(char	*str)
{
	int	i;

	i = 1;
	if (str[0] != '-')
		return (0);
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

/* @brief Prints the arguments
 * @return Nothing
*/
void	ft_print_echo(t_all *all)
{
	int	i;

	i = 0;
	while (all->data->arg && (all->data->arg[i]))
		i++;
	while (all->data->arg[i])
	{
		printf("%s", all->data->arg[i]);
		i++;
		if (all->data->arg[i])
			printf(" ");
		else if (!ft_check_echo(all->data->arg[0]))
			printf("\n");
	}
}

/* @brief Displays the string given in parameters
 * @return Nothing
*/
void	ft_echo(t_all *all)
{
	if (!all->data->arg)
		printf("\n");
	else
		ft_print_echo(all);
}
