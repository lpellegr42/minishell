
#include "../../includes/minishell.h"

/*
	faire une fonction qui compte single quote nombre de single quote
	si nbr de single quote % 2 == 0 alors ok
	pareil pour double quotes.
*/

/*
 * @brief Check if there is unclosed quote in the given string.
 * @return -1 if there's unclosed quote
*/
int unclosed_quotes_check(char *str)
{
	int i;
	int single_quote;
	int double_quote;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			single_quote++;
		}
		else if(str[i] == '\"')
		{
			double_quote++;
		}
		i++;
	}
	if ((single_quote % 2 != 0) || (double_quote % 2 != 0))
		return (-1);
	// add a return to check which quote are in it.
	else
		return (0);
}

// int quote_cheker(char *str, int i)
// {
// 	int simple_quote;
// 	int double_quote;

// 	simple_quote = 0;
// 	double_quote = 0;


// 	/* une boucle decremente pour chercher des quotes tant que i > 0 */

// 	/* une boucle incremente pour chercher quote tant str[i] != \0 */


// }