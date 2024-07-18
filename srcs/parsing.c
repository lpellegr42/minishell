#include "minishell.h"

void	receive_line(char *str)
{
	
}



void	parsing(char *str)
{
	t_parsing	*parsing_tree;

	node = NULL;
	parsing_tree = parse_pipe(str); //mon parse pipe va créer deux nodes, deux partie pour chaque cote du pipe, puis recursive sur les enfants.
	parsing_tree = parse_redir(parsing_tree);
	//split pimp qui garde plus de choses
}

t_parsing	*create_node(char *data)
{
 testtest
}

void	free_tree(t_parsing *node)
{
	if (!node)
		return ;
	free_tree(node->part1);
	free(node->data); //data to change - create another function.
	free_tree(node->left);
	free(node->data); // same
}