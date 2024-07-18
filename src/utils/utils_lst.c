//#include "minishell.h"
#include "../../includes/minishell.h"

t_env	*ft_last_node(t_env	*lst)
{
	while (lst->next)
		lst = lst->next;
	return (lst);
}
void	ft_swap(t_env **lst)
{
	t_env	*temp;

	temp = (*lst)->next;
	(*lst)->next = temp->next;
	temp->next = *lst;
	*lst = temp;
	printf("swap\n");
}
