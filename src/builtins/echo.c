//#include "minishell.h"
#include "../../includes/minishell.h"

void	ft_echo(t_data *data)
{
	int	i;

	i = 0;
	if (!data->arg)
		printf("\n");
	else if (ft_strncmp(data->arg[0], "-n", 2) == 0)
	{
		i = 1;
		while (data->arg[i])
		{
			printf("%s", data->arg[i]);
			i++;
		}
	}
	else
	{
		while (data->arg[i])
		{
			printf("%s\n", data->arg[i]);
			i++;
		}
	}
}