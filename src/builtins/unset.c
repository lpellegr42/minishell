/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:28:25 by livsauze          #+#    #+#             */
/*   Updated: 2024/09/11 19:28:27 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* @brief Unset environment variables given in parameter.
 * @return Nothing
*/
void	ft_unset(t_data *data, t_env *env)
{
	t_env	*tmp;
	int		i;

	tmp = env;
	i = 0;
	if (!data->arg)
		return ;
	while (data->arg[i])
	{
		tmp = env;
		while (tmp)
		{
			if (ft_strncmp(tmp->key, data->arg[i], ft_strlen(tmp->key)) == 0)
			{
				free(tmp->val);
				tmp->val = NULL;
				tmp->set = 0;
			}
			tmp = tmp->next;
		}
		i++;
	}
}
