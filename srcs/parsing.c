#include "minishell.h"

// void	receive_line(char *str)
// {	
// }



void	parsing(char *str)
{
	parse_pipe(); //mon parse pipe va créer deux nodes, deux partie pour chaque cote du pipe, puis recursive sur les enfants.
	parse_redir();
	//split pimp qui garde plus de choses

}

t_parsing	*create_node(char *cmd)
{
	// malloc part
}

void	free_node(t_parsing *node)
{

}