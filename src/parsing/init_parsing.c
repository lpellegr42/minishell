//#include "minishell.h"
#include "../../includes/minishell.h"

t_cmdtree	*parsing(char *line)
{
	t_cmdtree	*node;
	t_cmdtree	*root_node;

	node = init_node(line);
	root_node = node;
	node = parse_pipe(node); //mon parse pipe va créer deux nodes, deux partie pour chaque cote du pipe, puis recursive sur les enfants.
	// securité si pas de pipe.
	print_tree(node);
	//node = parse_redir(node);
	//split pimp qui garde plus de choses

	return (root_node);
}

// create a new node with default value.
t_cmdtree	*init_node(char *str)
{
	t_cmdtree	*new_node;

	new_node =  malloc(sizeof(t_cmdtree));
	if (!new_node)
		return (NULL);
	new_node->type = DEFAULT;
	new_node-> str = my_strdup(str); //malloc'd
	//new_node->str = strdup(str); //test purpose
	new_node->arg = NULL;
	new_node->part1 = NULL;
	new_node->part2 = NULL;
	return (new_node);
}

// FREE FUNCT - NOT IN USED ATM

// @brief Free a simple node
void	free_node(t_cmdtree *node)
{
	//free(node->type);
	free(node->str);
	
	//free_tab(node->arg); //TODO
	//free(node->fd);
	
	// have i to free part 1 and 2 cause i do it recursively above ?
}

// @brief Free a complete binary tree recursively.
void	free_tree(t_cmdtree *node)
{
	if (!node)
		return ;
	free_tree(node->part1);
	free_tree(node->part2);
	free_node(node);
}
