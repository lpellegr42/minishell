//#include "minishell.h"
#include "../../includes/minishell.h"

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	lens;

	lens = ft_strlen(s);
	if (start >= lens)
		return ((char *)ft_strdup(""));
	if (len + start >= lens)
		str = (char *)malloc(sizeof(char) * (lens - start + 1));
	if (len + start < lens)
		str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = start;
	j = 0;
	while (i < lens && j < len)
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

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
	path_array = ft_split(ft_getenv_tab("PATH", envp), ':');
	while (path_array[++i])
	{
		path_slash = ft_strjoin(path_array[i], "/");
		cmd_path = ft_strjoin(path_slash, cmd);
		free(path_slash);
		if (access(cmd_path, F_OK | X_OK) == 0)
		{
			ft_free_tab(path_array);
			return (cmd_path);
		}
		free(cmd_path);
	}
	ft_free_tab(path_array);
	return (cmd);
}
