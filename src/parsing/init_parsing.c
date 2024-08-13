//#include "minishell.h"
#include "../../includes/minishell.h"

//FURTHER COMMENT AND ADD NEXT PARSING STEP
// Add free b_tree functions in the loop.

/**
 * @brief Main parsing funct
 * TODO further comment and fct rework 
*/
t_cmdtree	*parsing(char *line)
{
	t_cmdtree	*node;
	t_cmdtree	*root_node;

	if (empty_line_check(line) == 1)
		exit (127); //check if not done in the exit built-in
	//if (unclosed_quote_check(line)) //TODO
	node = init_node(line);
	root_node = node;
	node = parse_pipe(node);
	// securité si pas de pipe -> verif que le tree soit pas vide dans next fct de parsing.
	print_tree(node);
	//node = parse_redir(node);
	return (root_node);
}

/**
 * @brief Create a new node with default value.
 */
t_cmdtree	*init_node(char *str)
{
	t_cmdtree	*new_node;

	new_node =  malloc(sizeof(t_cmdtree));
	if (!new_node)
		return (NULL);
	new_node->type = DEFAULT;
	new_node-> str = my_strdup(str); //malloc'd
	new_node->arg = NULL;
	new_node->part1 = NULL;
	new_node->part2 = NULL;
	return (new_node);
}


// /*
// FREE FUNCT - NOT IN USED ATM
// */

// /**
//  * @brief Free a simple node
// */
// void	free_node(t_cmdtree *node)
// {
// 	//free(node->type);
// 	free(node->str);
	
// 	//free_tab(node->arg); //TODO
// 	//free(node->fd);
	
// 	// have i to free part 1 and 2 cause i do it recursively above ?
// }

// /**
//  * @brief Free a complete binary tree recursively.
// */
// void	free_tree(t_cmdtree *node)
// {
// 	if (!node)
// 		return ;
// 	free_tree(node->part1);
// 	free_tree(node->part2);
// 	free_node(node);
// }
