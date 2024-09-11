//#include "minishell.h"
#include "../../includes/minishell.h"

void	free_and_close(char *line, int fd)
{
	close(fd);
	free(line);
}

void	ft_heredoc(char *delim)
{
	int		fd;
	char	*line;

	unlink(".tmp");
	fd = open(".tmp", O_RDWR | O_CREAT | O_TRUNC, 0777);
	while (1)
	{
		line = readline(">");
		if (!line)
		{
			printf("here-document delimited by EOF (wanted '%s')\n", delim);
			free_and_close(line, fd);
			return ;
		}
		if (ft_strncmp(line, delim, ft_strlen(delim)) == 0)
		{
			free_and_close(line, fd);
			return ;
		}
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
}

// Reunir ces deux fonctions pour manager les fd.

// all->data->fd

// int	ft_handle_out(t_all *all)
// {
// 	int	fd;

// 	fd = -1;

// 	//add fd management to the exec part
// 	if (fd != -1)
// 		dup2(fd, 1);
// 	return (fd);
// }

// int	ft_handle_in(t_all *all)
// {
// 	int	fd;

// 	fd = open(all->data->redir_in, O_RDONLY);
// 	dup2(fd, 0);
// 	return (fd);
// }