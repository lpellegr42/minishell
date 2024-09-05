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

void	handle_redir(void)
{
	printf("IT'S A REDIR\n");
}

void	parse_redir(t_data *node)
{
	while (node)
	{
		if (node->next->cmd[0] == '<' || node->next->cmd[0] == '>')
			handle_redir();
		node = node->next;
	}
}

// int	search_redir(char *str)
// {
// }


/*
Je veux itérer dans les noeuds de ma structure et regarder si le noeud suivant est une redir.
Si c'est le cas je veux regarder que ce ne soit '>>>' ou '<<<' et que le noeuds suivant ne 
soit pas un token redir également. 

*/