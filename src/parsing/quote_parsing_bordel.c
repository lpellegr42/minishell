
#include "../../includes/minishell.h"

// //TODO: 
// // cas a traiter

// // i = 0
// // si \ devant la quote
// // si je suis 

// // does not work cause if there's unclosed quote in closed quote, it doesn't count

// /*
//  * @brief Check if there is unclosed quote in the given string.
//  * @return -1 if there's unclosed quote.
// */
// int unclosed_quotes_check(char *str)
// {
// 	int i;
// 	int single_quote;
// 	int double_quote;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '\'')
// 			single_quote++;
// 		else if (str[i] == '\"')
// 			double_quote++;
// 		i++;
// 	}
// 	if ((single_quote % 2 != 0) || (double_quote % 2 != 0))
// 		return (-1);
// 	// add a return to check which quote are in it.
// 	else
// 		return (0);
// }

// /*
//  * @brief Check if the given string contain unclosed quote
//  * @return 0 if quotes are closed. 1 if there are unclosed quotes.
//  * 
// */
// int	unclosed_quote_check(char *str)
// {
// 	if (single_quote_counter(line) % 2 == 0 && double_quote_counter(line) == 0)
// 		return (0);
// 	return (1);
// }

//https://cdn.intra.42.fr/users/ab912c10f3741c839585613bf500c128/begonzal.jpg

// // int quote_cheker(char *str, int i)
// // {
// // 	if(error_check(str) == 1)
// // 	{
// // 		return (-1);
// // 	}


// // 	/* une boucle decremente pour chercher des quotes tant que i > 0 */

// // 	/* une boucle incremente pour chercher quote tant str[i] != \0 */
// // }

// void quote_checker(char *str, int pos)
// {
// 	int	is_in_squote;
// 	int	is_in_dquote; //is_dquote_open;

// 	int i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] == '"' || str[i] == '\'')
// 		{
// 			if (str[i] == '"' && is_in_dquote == 1)
// 				is_in_dquote = 0;
// 			else if (str[i] == '"' && is_in_dquote == 0)
// 				is_in_dquote = 1;
// 			else if (str[i] == '\'' && is_in_squote == 1)
// 				is_in_squote = 0;
// 			else if (str[i] == '\'' && is_in_dquote == 1)
// 				is_in_squote = 0;
// 		}
// 	}
// }

// // pas suffisant mais base de fonction ok.

// int is_in_dquote(char *str, int pos, )