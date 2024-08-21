#include "../../includes/minishell.h"

// PRINT PART

void	print_split(char **res)
{
	int i;

	i = 0;
	while (res[i] != NULL)
	{
		ft_putstr(res[i]);
		write(1, "\n", 1);
		i++;
	}
}

void	print_parsing(t_all *all)
{
	int i = 0;
	while (all->data)
	{
		printf("data[%i]:%s\n", i, all->data->line);
		printf ("	cmd:%s\n", all->data->cmd);
		int j = 0;
		while(all->data->arg[j])
		{
			printf("		arg[%i]:%s\n", j, all->data->arg[j]);
			j++;
		}
		all->data = all->data->next;
		i++;
	}
}

// FREE PART

/**
 * Free a char** completely. (RENAME free_string_array and 
 *  delete doublon with ft_free_tab.)
*/
void free_tab_tab(char **tab)
{
	int i;

	i = 0;
	while(tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
}

void ft_free_tab(char **tab)
{
	int i;

	i = 0;
	while(tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

// void	quote_checker_verif(char *str)
// {
//     // char *test_str1 = "This is a 'test' string";
//     // char *test_str2 = "This is a 'test' string";
    
//     if (is_unclosed_quotes(str))
//         printf("String 1 has unclosed quotes.\n");
//     else
//         printf("String 1 is correctly closed.\n");
    
//     // if (is_unclosed_quotes(test_str2))
//     //     printf("String 2 has unclosed quotes.\n");
//     // else
//     //     printf("String 2 is correctly closed.\n");
// }

// /*
//  * @brief Convert the defined enum into their respective name for testing purpose.
//  * @return Return the corresponding string.
// */
// char* enum_to_str(int spec_enum)
// {
// 	// if (spec_enum ==  EXEC)
// 	// 	return ("EXEC");
// 	if (spec_enum == PIPE)
// 		return ("PIPE");
// 	else if (spec_enum == IN_REDIR)
// 		return ("IN_REDIR");
// 	else if (spec_enum == OUT_REDIR)
// 		return ("OUT_REDIR");
// 	else if (spec_enum == HERE_DOC)
// 		return ("HERE_DOC");
// 	else if (spec_enum == DEFAULT)
// 		return ("DEFAULT");
// 	else
// 		return("Error");
// }


// BTREE LEGACY PART

// /*
//  * @brief Print a abstract syntax tree recursively.
// */
// void	print_tree(t_cmdtree *node)
// {
// 	if (!node)
// 		return ;
// 	printf("\n\n/// NEW NODE ///\ntype:	%s\nstr:	$%s$\n", enum_to_str(node->type), node->str);
// 	print_tree(node->part1);
// 	print_tree(node->part2);
// }