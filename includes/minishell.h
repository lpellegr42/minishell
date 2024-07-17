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

/* Struct & enum */


typedef struct s_env
{
	char			*key;
	char			*val;
	int				set;
	struct s_env	*next;
}	t_env;


typedef struct s_data
{
	char		*cmd;	//env
	char		**arg; //const ? NULL
	int			fd_out;
	int			fd_in;
	int			flag_out; //simple ou double redir; > ou >>
	char 		*here_doc;
	t_data		*next;
} 	t_data; // fill en * simple pour l'exec.


// - Parsing struct
typedef struct s_parsing
{
	char *cmd;
	struct s_parsing	*part1;
	struct s_parsing	*part2;
}	t_parsing;

// - End parsing struct.

/* Functions */

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
