#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h> //Basic lib
# include <unistd.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

# include <signal.h> //Usefull lib
# include <sys/types.h>
# include <time.h>

typedef struct s_env
{
	char			*key;
	char			*val;
	int				set;
	struct s_env	*next;
}	t_env;

// Parsing struct
typedef struct s_parsing
{
	char *cmd;
}	s_parsing;

typedef enum s_tokentype
{
	EXEC, //try to create needed token, don't hesitate to comment your ideas.
	BUILTIN,
	PIPE,
	HERE_DOC,
	IN_REDIR,
	OUT_REDIR,
	DEFAULT_CMD,
}	t_tokentype; //not sure bout the right token to put, will see further.
// End parsing struct.


// typedef struct s_data
// {
// 	t_env	*env;
// }	t_data;

/* *********************************ENV.C************************************ */
t_env	*ft_copy_env(t_env *env, char	**envp);

/* ******************************BUILTINS.C********************************** */
void	ft_builtins(char *str, t_env *env);

/* *****************************UTILS_LIBFT.C******************************** */
int		ft_strlen(char *str);
int		ft_len(char *str, int i);
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_strjoin(char *s1, char *s2);

/* ******************************UTILS_LST.C********************************* */
t_env	*ft_last_node(t_env	*lst);

// Parsing part
void	parsing(char *str);

#endif
