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
	if (ft_strncmp(cmd, "./", 2) == 0)
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
