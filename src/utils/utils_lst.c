//#include "minishell.h"
#include "../../includes/minishell.h"

t_env	*ft_last_node(t_env	*lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_print_list(char *str, t_env *lst)
{
	while (lst)
	{
		printf("%s, %s\n", str, lst->key);
		lst = lst->next;
	}
}
