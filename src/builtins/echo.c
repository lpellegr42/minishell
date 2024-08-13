//#include "minishell.h"
#include "../../includes/minishell.h"

int	ft_check_echo(char	*str)
{
	int	i;

	i = 1;
	if (str[0] != '-')
		return (0);
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}
/* @brief Prints the arguments
 * @return Nothing
*/
void	ft_print_echo(t_all *all)
{
	int	i;

	i = 0;
	while (ft_check_echo(all->data->arg[i]))
		i++;
	while (all->data->arg[i])
	{
		if (ft_strncmp(all->data->arg[i], "$?", 2) == 0)
		{
			printf("%d\n", all->err);
			all->err = 0;
			return ;
		}
		printf("%s", all->data->arg[i]);
		i++;
		if (all->data->arg[i])
			printf(" ");
		else if (!ft_check_echo(all->data->arg[0]))
			printf("\n");
	}
}
/* @brief Displays the string given in parameters
 * @return Nothing
*/
void	ft_echo(t_all *all)
{
	if (!all->data->arg)
		printf("\n");
	else
		ft_print_echo(all);
}
