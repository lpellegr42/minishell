//#include "minishell.h"
#include "../../includes/minishell.h"

void	reset(void)
{
	printf("\033[0m");
}
void	blue(void)
{
	printf("\033[1;34m");
}

void	green(void)
{
	printf("\033[0;32m");
}