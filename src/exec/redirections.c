//#include "minishell.h"
#include "../../includes/minishell.h"

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
			close(fd);
			free(line);
			return ;
		}
		if (ft_strncmp(line, delim, ft_strlen(delim)) == 0)
		{
			free(line);
			close(fd);
			return ;
		}
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		free(line);
	}
}

// int	ft_handle_out(t_all *all)
// {
// 	int	fd;

// 	fd = -1;
// 	if (all->data->flag_out == 1)
// 		fd = open(/*fd_out*/, O_WRONLY | O_CREAT | O_TRUNC, 0777);
// 	else if (all->data->flag_out == 2)
// 		fd = open(/*fd_out*/, O_WRONLY | O_CREAT| O_APPEND, 0777);
// 	return (fd);
// }

// int	ft_handle_in(t_all *all)
// {
// 	int	fd;

// 	fd = open(all->data->fd_in, O_RDONLY);
// 	dup2(fd, 0);
// 	return (fd);
// }
