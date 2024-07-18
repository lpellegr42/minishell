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

int	first_pipe_pos(char *str)
{
	int i;

	i = ;
	while (str[i])
	{
		if (str[i] == '|') //add between quote verif.
			return (i);
		i++;
	}
	return (-1); //no pipe in the str.
}