#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h> //Basic lib
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <string.h> //string.h for strdup testing purpose
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

typedef struct s_data //what i give to liv - s_data t_data
{
	char		*cmd;	//mettre le path env - get ma fonction pipex qui permet de creer un path from funct
	char		**arg; //const ? premier argument est le nom du programme ds cas de EXECVE, dernier est NULL
	int			fd_out; //fd_out et in same thing
	int			fd_in;
	int			flag_out; //simple ou double redir; > O_CREATE ou >> O_APPEND
	char 		*here_doc; //change for int fd
	struct s_data		*next;
} 	t_data; //fill en * simple (ptr simple) pour l'exec.

// my enum

typedef enum s_tokentype
{
	EXEC, //useless
	PIPE,
	IN_REDIR,
	OUT_REDIR,
	HERE_DOC,
	DEFAULT
}			t_tokentype;

typedef struct s_cmdtree
{
	int	type; //default, need to define clearly which type i need.
	char *str; //initial_str
	char **arg; //command_args
	int fd; //in case of pipe and redir -> keep only the last fd open
	struct s_cmdtree	*part1; //left
	struct s_cmdtree	*part2; //right
}	t_cmdtree;

// End parsing struct.

/* Functions */

/* *********************************ENV.C************************************ */

t_env	*ft_copy_env(t_env *env, char **envp);

/* ******************************BUILTINS.C********************************** */

void	ft_builtins(char *line, t_data *data, t_env *env);
void	ft_export(char *line, t_data *data, t_env *env);
void	ft_env(t_env *env);
void	ft_unset(char *line, t_data *data, t_env *env);

/* *****************************UTILS_LIBFT.C******************************** */

int		ft_strlen(char *str);
int		ft_len(char *str, int i);
int		ft_strncmp(char *s1, char *s2, int n);
int		ft_atoi(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_itoa(int n);
char	*ft_strdup(char *s);

/* ******************************UTILS_LST.C********************************* */

t_env	*ft_last_node(t_env	*lst);
void	ft_swap(t_env **lst);


//								Parsing

// 	parsing/init_parsing.c

t_cmdtree	*parsing(char *line);
t_cmdtree	*init_node(char *str);
//void	free_node(t_cmdtree *node); //Not needed in header file
void	free_tree(t_cmdtree *node);

//	parsing/parsing_utils.c

char	*my_strchr(const char *s, int c);
char	*my_substr(char const *s, unsigned int start, size_t len);
char	*my_strdup(const char *s);
size_t	my_strlen(const char *s);

//	parsing/pipe_parsing.c

t_cmdtree	*parse_pipe(t_cmdtree *node);
int	search_pipe(char *str);

//	parsing/quote_parsing.c

int	unclosed_quotes_check(char *str);

	// Temp

//	temp/test.c

char* 	enum_to_str(int spec_enum); //can be removed from .h for now
void	print_tree(t_cmdtree *node);
char	**ft_split(char const *s, char sep);
//void	test_parsing(char *line);

#endif
