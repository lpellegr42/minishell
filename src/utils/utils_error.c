//#include "minishell.h"
#include "../../includes/minishell.h"

void	ft_display_err(char *s, t_all *all, int err_status)
{
	all->err = err_status;
	red();
	printf("%s", s);
	reset();
}
