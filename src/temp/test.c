#include "../../includes/minishell.h"

// void test_parsing(char *line)
// {
// 	split_on_pipe(line);
// }

	// PRINT PART


/*
 * @brief Convert the defined enum into their respective name for testing purpose.
 * @return Return the corresponding string.
*/
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
/*
 * @brief Print a abstract syntax tree recursively.
*/
void	print_tree(t_cmdtree *root_node)
{
	if (!node)
		return ;
	printf("\n\n/// NEW NODE ///\ntype:	%s\nstr:	$%s$\n", enum_to_str(node->type), node->str);
	print_tree(node->part1);
	print_tree(node->part2);
}

