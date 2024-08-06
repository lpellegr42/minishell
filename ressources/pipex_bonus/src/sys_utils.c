/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sys_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellegr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:32:31 by lpellegr          #+#    #+#             */
/*   Updated: 2024/06/26 17:48:11 by lpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
*	Perform the open system call on the file given as parameter 
* 	with the specified access mode given by the in_out flag.
*	Return the file descriptor of the opened file.
*	In case of error, prints the error and exit.
*/
int	open_file(char *file, int in_out)
{
	int	return_value;

	if (in_out == 0)
		return_value = open(file, O_RDONLY);
	else if (in_out == 1)
		return_value = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (in_out == 2)
		return_value = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (return_value == -1)
		error_handler("open");
	return (return_value);
}

/* 
*	Call execve on the given environment with the 'splitted_cmd' arguments
*	using get_path to retrieves the binary we search for.
*/
void	exec(char *cmd, char **envp)
{
	char	**splitted_cmd;
	char	*path;

	splitted_cmd = ft_split(cmd, ' ');
	path = get_path(splitted_cmd[0], envp);
	if (execve(path, splitted_cmd, envp) == -1)
	{
		free_arrays(splitted_cmd);
		error_handler("execve");
	}
}

/*
 * Retrieves the absolute path of a command from the 'PATH' environment variable.
 * Returns the absolute path if found, otherwise returns the command alone.
 */
char	*get_path(char *cmd, char **envp)
{
	int		i;
	char	*cmd_path;
	char	**path_array;
	char	*path_slash;

	i = -1;
	path_array = ft_split(my_getenv("PATH", envp), ':');
	while (path_array[++i])
	{
		path_slash = ft_strjoin(path_array[i], "/");
		cmd_path = ft_strjoin(path_slash, cmd);
		free(path_slash);
		if (access(cmd_path, F_OK | X_OK) == 0)
		{
			free_arrays(path_array);
			return (cmd_path);
		}
		free(cmd_path);
	}
	free_arrays(path_array);
	return (cmd);
}

/*
 * 	Simple implementation of the getenv function (man 3 getenv).
 *	to get the value of the specified environment variable in the given envp.
 */
char	*my_getenv(char *name, char **envp)
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
