#include "../../includes/minishell.h"

// void test_parsing(char *line)
// {
// 	split_on_pipe(line);
// }

	// PRINT PART

//print a complete binary tree recursively

char* enum_to_str(int spec_enum)
{
	if (spec_enum ==  EXEC)
		return ("EXEC");
	else if (spec_enum == PIPE)
		return ("PIPE");
	else if (spec_enum == IN_REDIR)
		return ("IN_REDIR");
	else if (spec_enum == OUT_REDIR)
		return ("OUT_REDIR");
	else if (spec_enum == HERE_DOC)
		return ("HERE_DOC");
	else if (spec_enum == DEFAULT)
		return ("DEFAULT");
	else
		return("Error");
}

void	print_node(t_cmdtree *node)
{
	if (node->type)
		printf("%s\n", enum_to_str(node->type));
	if (node->str)
		printf("%s\n", node->str);
	//print arg to add.

}
// void	print_tree(t_cmdtree *node)
// {
// 	if (!node)
// 		return ;
// 	printf("PART1 of the tree: \n");
// 	print_tree(node->part1);
// 	print_node(node);
// 	printf("PART1 of the tree: \n");
// 	print_tree(node->part2);
// }


void print_tree(t_cmdtree *node, const char *side) 
{
    if (!node)
        return;
    
    // Print the current part of the tree
    if (side)
        printf("[%s] ", side);
    printf("Node Type: %s, Value: %s\n", enum_to_str(node->type), node->str ? node->str : "NULL");

    // Traverse left subtree
    print_tree(node->part1, "Left");

    // Print the current node
    if (side)
        printf("[%s] ", side);
    printf("Node Type: %s, Value: %s\n", enum_to_str(node->type), node->str ? node->str : "NULL");

    // Traverse right subtree
    print_tree(node->part2, "Right");
}