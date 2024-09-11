/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:27:11 by livsauze          #+#    #+#             */
/*   Updated: 2024/09/11 19:27:16 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* @brief Prints environment variables
 * @return Nothing
*/

void	ft_env(t_env *env)
{
	while (env)
	{
		if (env->set == 1)
			printf("%s=%s\n", env->key, env->val);
		env = env->next;
	}
}
