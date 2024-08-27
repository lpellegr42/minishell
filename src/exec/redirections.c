//#include "minishell.h"
#include "../../includes/minishell.h"

// int	ft_handle_in(t_all *all)
// {
// 	int	fd;

// 	fd = open(all->data->fd_in, O_RDONLY);
// 	dup2(fd, 0);
// 	return (fd);
// }

int	ft_handle_out(t_all *all)
[
	int	fd;

	fd = -1;
	if (all->data->flag_out == 1)
		fd = open(/*fd_out*/, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (all->data->flag_out == 2)
		fd = open(/*fd_out*/, O_WRONLY | O_CREAT| O_APPEND, 0777);
	return (fd);
]