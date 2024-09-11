/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellegr <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:30:06 by livsauze          #+#    #+#             */
/*   Updated: 2024/09/11 20:49:25 by lpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_getenv_tab(char *name, char **envp)
{
	int		i;
	int		j;
	char	*env_name;

	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j] && envp[i][j] != '=')
			j++;
		env_name = ft_substr(envp[i], 0, j);
		if (ft_strncmp(env_name, name, ft_strlen(name)) == 0)
		{
			free(env_name);
			return (&envp[i][j + 1]);
		}
		free(env_name);
		i++;
	}
	return (NULL);
}

char	*ft_getpath(char *cmd, char **envp)
{
	int		i;
	char	*cmd_path;
	char	**path_array;
	char	*path_slash;

	i = -1;
	if (!ft_getenv_tab("PATH", envp))
		return (NULL);
	if (ft_strncmp(cmd, "./", 2) == 0 || ft_strncmp(cmd, "/", 1) == 0)
	{
		cmd_path = ft_strdup(cmd);
		return (cmd_path);
	}
	path_array = ft_split(ft_getenv_tab("PATH", envp), ':');
	while (path_array[++i])
	{
		path_slash = ft_strjoin(path_array[i], "/");
		cmd_path = ft_strjoin(path_slash, cmd);
		free(path_slash);
		if (access(cmd_path, F_OK | X_OK) == 0)
			return (ft_free_tab(path_array), cmd_path);
		free(cmd_path);
	}
	return (ft_free_tab(path_array), NULL);
}

int	ft_tab_len(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
		i++;
	return (i);
}

char	**ft_get_args(char *path, char **arg)
{
	char	**tab;
	int		i;
	int		j;

	tab = malloc(sizeof(char *) * (ft_tab_len(arg) + 2));
	tab[0] = ft_strdup(path);
	i = 0;
	j = 1;
	while (arg && arg[i])
	{
		tab[j] = ft_strdup(arg[i]);
		i++;
		j++;
	}
	tab[j] = NULL;
	return (tab);
}
