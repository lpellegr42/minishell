/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:28:53 by livsauze          #+#    #+#             */
/*   Updated: 2024/09/11 19:28:54 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

/* @brief Strjoin with free the first string
 * @return A string (char *)
*/
char	*ft_join(char *s1, char *s2)
{
	char	*newstr;
	int		i;
	int		j;

	newstr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (newstr == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		newstr[i] = s1[j];
		i++;
		j++;
	}
	j = 0;
	while (s2[j])
	{
		newstr[i] = s2[j];
		i++;
		j++;
	}
	newstr[i] = '\0';
	return (free(s1), newstr);
}

/* @brief Creates a new node to the environment
 * @return A pointer to the first node
*/
t_env	*ft_append_env(t_env *env, char **str)
{
	t_env	*new;
	t_env	*last;

	new = malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->key = ft_strdup(str[0]);
	if (str[1])
	{
		new->val = ft_strdup(str[1]);
		new->set = 1;
	}
	else
	{
		new->val = NULL;
		new->set = 2;
	}
	new->pos = 0;
	last = ft_last_node(env);
	last->next = new;
	return (env);
}

/* @brief Modifies the value of an environment variable
 * @return Nothing
*/
void	ft_modify_env(char *s1, char *s2, t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (ft_strncmp(s1, tmp->key, ft_strlen(s1)) == 0)
		{
			free(tmp->val);
			tmp->val = ft_strdup(s2);
			return ;
		}
		tmp = tmp->next;
	}
}

/* @brief Gets the value of an environment variable
 * @return The value in a string (char *)
*/
char	*ft_getenv(char *str, t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (ft_strcmp(str, tmp->key) == 0)
			return (tmp->val);
		tmp = tmp->next;
	}
	return (NULL);
}

/* @brief Creates and resets an env copy in a char **
 * @return Nothing
*/
char	**ft_reset_env(t_env *env)
{
	int		i;
	char	**res;
	t_env	*tmp;

	res = malloc(sizeof(char *) * (ft_lstsize(env) + 1));
	i = 0;
	tmp = env;
	while (tmp)
	{
		if (tmp->set == 1)
		{
			res[i] = ft_strdup(tmp->key);
			if (tmp->val)
			{
				res[i] = ft_join(res[i], "=");
				res[i] = ft_join(res[i], tmp->val);
			}
			i++;
		}
		tmp = tmp->next;
	}
	res[i] = NULL;
	return (res);
}
