//#include "minishell.h"
#include "../../includes/minishell.h"

t_env	*ft_last_node(t_env	*lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_print_env(t_all *all)
{
	t_env	*lst;

	lst = all->env;
	while (lst)
	{
		printf("%s\n", lst->key);
		lst = lst->next;
	}
}

void	ft_print_data(t_data *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		printf("%s\n", lst->cmd);
		while (lst->arg && lst->arg[i])
		{
			printf("arg : %s\n", lst->arg[i]);
			i++;
		}
		lst = lst->next;
	}
}
