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

void	ft_echo(t_data *data)
{
	int	i;

	i = 0;
	if (!data->arg)
		printf("\n");
	else
	{
		while (ft_check_echo(data->arg[i]))
				i++;
		while (data->arg[i])
		{
			printf("%s", data->arg[i]);
			i++;
			if (data->arg[i])
				printf(" ");
			else if (!ft_check_echo(data->arg[0]))
				printf("\n");
		}
	}
}
