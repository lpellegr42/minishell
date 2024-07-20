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
void	print_tree(t_cmdtree *node)
{
	if (!node)
		return ;
	print_tree(node->part1);
	print_node(node); //data to change - create another function.
	print_tree(node->part2);
	print_node(node); // same
}