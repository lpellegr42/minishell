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
 * le split doit garder la redir me semble.
*/

// void	redir_parsing(t_cmdtree *node, char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (node->str[i])
// 	{
// 		if (node->str[i] == '<' && node->str[i - 1] != '\\')
// 		{
// 			return (i); //return char * "redir_in" and treat later ?

// 		}
// 		else if (node->str[i] == '>' && node->str[i - 1] != '\\')
// 		{
// 			return (i); // or do it in the parent function and re-analyse the node type.
// 		}
// 		i++;
// 	}
// }

// int	search_redir(char *str)
// {

// }

