//#include "minishell.h"
#include "../../includes/minishell.h"

t_parsing	*parse_pipe(t_parsing *parsing_tree, char *str)
{
	char	*part1;
	char	*part2;
	char	*first_pipe_pos;
	/* put in conditional structure recursively. */
	/* strchr to found the first occurence of a pipe if there is one in the string */
	/* create two subtring of that and put them in the two part of my binary tree. */

	first_pipe_pos = ft_strchr(str, '|'); //faire fct, first pipe
	part1 = ft_substr(str, 0, );
	part2 = ft_substr();
	//Allocates and fill part1 and 2.
	return (parsing_tree);
}

t_parsing	*parsing(char *str)
{
	t_parsing	*parsing_tree; //double pointer or not ? i want to keep the first node adress.

	parsing_tree = NULL;
	parsing_tree = parse_pipe(parsing_tree, str); //mon parse pipe va créer deux nodes, deux partie pour chaque cote du pipe, puis recursive sur les enfants.
	parsing_tree = parse_redir(parsing_tree);
	//split pimp qui garde plus de choses
	return (parsing_tree);
}

void	free_node(t_parsing *node)
{
	free(node->type);
	free(node->str);
	free_tab(node->arg); //TODO
	free(node->fd);
	// have i to free part 1 and 2 cause i do it recursively above ?
}

void	free_tree(t_parsing *node)
{
	if (!node)
		return ;
	free_tree(node->part1);
	free_node(node); //data to change - create another function.
	free_tree(node->part2);
	free_node(node); // same
}
t_parsing	*init_node(char *str, int len)
{
	t_parsing	*new_node;

	new_node =  malloc(sizeof(t_parsing));
	if (!new_node)
		return (NULL);
	new_node->type = DEFAULT;
	//new_node-> str = ft_strdup(str, len); //TODO
	new_node -> str = NULL; //provisoire - fill with the line, see above
	new_node->arg = NULL;
	new_node->part1 = NULL;
	new_node->part2 = NULL;
	return (new_node);
}
