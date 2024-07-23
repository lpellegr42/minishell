#include "../../includes/minishell.h"

int	is_between_quote(char *str, int pos, int verif_flag)
{
	int	i;
	//verif_flag = 0; //verif single_quote
	//verif_flag = 1;
	int *s_quote;
	int *d_quote;

	*s_quote = 0;
	*d_quote = 0;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			//*s_quote = !(*s_quote);
			is_in_quote(str, i, *s_quote, *d_quote);
		}
		i++;
	}

}

void is_in_quote(char *str, int i, int *s_quote, int *d_quote)
{
	if ((i = 0 || str[i - 1] != '\\') && *s_quote == 0 && *d_quote == 0)
		*s_quote = 1;
	if ()
	
}

// So compare:

// echo ""hello""    # just prints hello
// echo "\"hello\""  # prints "hello", because the escaped
//                   # quotes are part of the string
// echo "$PATH"      # prints the value of the PATH variable
// echo "\$PATH"     # prints $PATH
// echo ""'$PATH'""  # prints $PATH, because it's in
//                   # single-quotes (with zero-lenght
//                   # double-quoted sections on each side

// Also, single- and double-quotes have no special meaning within the other type of quote. So:

// echo "'hello'"    # prints 'hello', because the single-quotes
//                   # are just ordinary characters in a
//                   # double-quoted string
// echo '"hello"'    # similarly, prints "hello"
// echo "'$PATH'"    # prints the PATH variable with
//                   # single-quotes around it (because
//                   # $variable expands in double-quotes)
