#include "../../includes/minishell.h"

/** 
 * @brief Check if the given string (prompt) is empty.
 * @return 1 if the given string is empty or contains only whitespace 0 if not.
*/
int	empty_line_check(char *line)
{
	// && !line
	if (*line == '\0' || is_only_whitespace(line, 0, ft_strlen(line)))
		return (1);
	return (0);
}

int	empty_pipe_check(char *line)
{
	if (check_start_pipe(line) || check_middle_pipes(line)
		|| check_end_pipe(line))
		return (1);
	return (0);
}

/**
 * @brief This function checks if the string contains any unclosed quotes.
 * @param str The string to check.
 * @return Returns 1 if the string contains unclosed quotes, otherwise 0.
 */
int	is_unclosed_quotes(char *str)
{
	int	i;
	int	s_quote;
	int	d_quote;

	i = 0;
	s_quote = 0;
	d_quote = 0;
	while (str && str[i])
	{
		quote_checker (str, i, &s_quote, &d_quote);
		i++;
	}
	if (s_quote || d_quote)
		return (1);
	return (0);
}

int	redir_error_check(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (is_redir(line[i]))
		{
			if ((line[i] == '>' && line[i + 1] == '>') ||
			    (line[i] == '<' && line[i + 1] == '<'))
				i += 2;
			else if (line[i] == '>' || line[i] == '<')
				i++;
			while (line[i] && is_whitespace(line[i]))
				i++;
			if (!line[i] || is_token(line[i]))
				return (1);
		}
		else
			i++;
	}
	return (0);
}
