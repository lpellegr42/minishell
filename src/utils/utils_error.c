#include "../../includes/minishell.h"

/**
 * @brief Prints the string given in parameter and sets the correct error status
 * @return Nothing
*/
void	ft_display_err(char *s, t_all *all, int err_status)
{
	all->err = err_status;
	printf("%s", s);
}
