#include "../../includes/minishell.h"

/**
 * redir_in  <
 * redir_out > O_CREATE
 * redir_out >> O_APPEND
 * here_doc  <<
*/

/**
 * 0 no redir
 * 1 redir in < / redir file before the redir
 * 2 redir_out > redir file after the redir
 * 3 redir_out >> 0_APPEND redir file after the redir
*/

/* will return a fd to the last */

/**
 * need un split qui se charge des redir selon leur type et donc direction.
 * le split doit garder la redir me semble. IS OK
*/



void	handle_redir_arg(t_data *data, int i)
{
		if (data->arg[i][0] == '>')
		{
			if (data->arg[i][1])
				printf("handle_double_redir_out\n");
			else
				printf("handle_simple_redir_out\n");
		}
		else if(data->arg[i][0] == '<')
		{
			if (data->arg[i][1])
				printf("handle_here_doc\n");
			else
				printf("handle_simple_redir_in\n");
		}
		data->arg = array_remove_at(data->arg, i + 1);
		data->arg = array_remove_at(data->arg, i);
}

void	parse_redir(t_data *data)
{
	int	i;

	i = 0;
	while (data->arg && data->arg[i])
	{
		if (is_redir(data->arg[i][0]))
			handle_redir_arg(data, i);
		else
			i++;
	}
}

// int	parse_redir(t_cmdgrp *node, int i, t_cmdgrp *firstnode)
// {
// 	if (node->arg[i][0] == '>')
// 	{
// 		if (node->arg[i][1])
// 			redir_open(node, i, 1);
// 		else
// 			redir_open(node, i, 0);
// 	}
// 	else if (node->arg[i][0] == '<')
// 	{
// 		if (node->arg[i][1])
// 		{
// 			node->type = HEREDOC;
// 			node->fd = heredoc(node->arg[i + 1]);
// 		}
// 		else
// 			redir_open(node, i, 2);
// 	}
// 	if (node->fd == -1)
// 		return (parsing_error(firstnode, 1, node->arg[i][0]), 0);
// 	node->arg = rm_from_array(node->arg, i + 1);
// 	node->arg = rm_from_array(node->arg, i);
// 	return (1);
// }


/*
Je veux itérer dans les noeuds de ma structure et regarder si le noeud suivant est une redir.
Si c'est le cas je veux regarder que ce ne soit '>>>' ou '<<<' et que le noeuds suivant ne 
soit pas un token redir également. 

*/