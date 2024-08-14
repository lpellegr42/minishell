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
# include <sys/wait.h>
# include <time.h>
# include <errno.h>

typedef struct s_env
{
	char			*key; // name of the variable (ex : USER, PATH, SHLVL...)
	char			*val; // value of the variable
	int				set; // flag to set or unset the variable (for unset)
	int				pos; // final position in ascii order (for export)
	int				init;
	struct s_env	*next; // pointer to the next node
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
} 	t_data; //fill en * simple (ptr simple) pour l'exec

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

typedef struct s_cmdtree // s_ast_node -> t_ast_node
{
	int	type; //default, need to define clearly which type i need.
	char *str; //initial_str
	char **arg; //command_args
	int fd; //in case of pipe and redir -> keep only the last fd open
	struct s_cmdtree	*part1; //left
	struct s_cmdtree	*part2; //right
}	t_cmdtree;

// End parsing struct.

typedef struct s_all
{
	t_data	*data;
	t_env	*env;
	char	**env_cpy;
	int		err;
}		t_all;

/* Functions */

/* ********************************SIGNALS*********************************** */
void	ft_handler(int sig, siginfo_t *s_info, void *context);
void	init_sig(int sig, void (*handler)(int, siginfo_t *, void *));

/* **********************************ENV************************************* */
t_env	*ft_copy_env(t_env *env, char **envp);
t_env	*ft_append_env(t_env *env, char **str);
char	*ft_getenv(char *str, t_env *env);
void	ft_modify_env(char *s1, char *s2, t_env *env);
void	ft_reset_env(t_all *all);

/* *******************************BUILTINS*********************************** */

void	ft_builtins(t_all *all);
void	ft_export(t_all *all);
void	ft_print_export(t_env *env);
char	**ft_split_export(char *s, char sep);
int		ft_check_node(char *s1, char *s2);
void	ft_env(t_env *env);
void	ft_unset(t_data *data, t_env *env);
void	ft_echo(t_all *all);
void	ft_pwd(t_all *all);
void	ft_cd(t_all *all);
void	ft_exit(t_all *all);

/* *********************************EXEC************************************* */
void	ft_exec(t_all *all);
void	ft_docmd(t_all *all);
char	*ft_getpath(char *cmd, char **envp);
char	*ft_getenv_tab(char *name, char **envp);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	**ft_get_args(char *path, char **args);
int	ft_tab_len(char **tab);

/* ******************************UTILS_LIBFT********************************* */
int		ft_strlen(char *str);
int		ft_len(char *str, int i);
int		ft_strncmp(char *s1, char *s2, int n);
int		ft_strlcpy(char *dest, char *src, int size);
int		ft_strchr(char *s, char c);
int		ft_atoi(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_join(char *s1, char *s2);
char	*ft_itoa(int n);
char	*ft_strdup(char *s);
void	ft_free_tab(char **tab);
void	ft_display_err(char *s, t_all *all, int err_status);

/* *******************************UTILS_LST********************************** */
t_env	*ft_last_node(t_env	*lst);
int		ft_isvalid(char *str);
int		ft_lstsize(t_env *lst);
void	ft_print_env(t_all *all);
void	ft_print_data(t_data *lst);

void	reset(void);
void	blue(void);
void	green(void);
void	red(void);

// 	temp

// temp/ft_split.c

char	**ft_split(char const *s, char sep);
void	ft_print_data(t_data *lst);

// temp/temp_arg.c
t_data	*parse_args(char *line, t_data *data);

//								Parsing

// 	parsing/init_parsing.c

t_cmdtree	*parsing(char *line);
t_cmdtree	*init_node(char *str);
//void	free_tree(t_cmdtree *node);
//void	free_node(t_cmdtree *node); //Not needed in header file

//	parsing/pipe_parsing.c

t_cmdtree	*parse_pipe(t_cmdtree *node);
int	search_pipe(char *str);

//	parsing/split_minishell.c

void	split_free(char **res, int count); //need to be put in another function, cause there's too many
char	**shell_split(char *s, char sep);

//	parsing/quote_parsing.c

void	quote_checker(char *str, int i, int *s_quote, int *d_quote);
void	quote_checker_arg(char c, char next_c, int *s_quote, int *d_quote);
int		is_in_quote(char *str, int pos, int flag);
int		is_unclosed_quotes(char *str);

//	parsing/parsing_utils.c

char	*my_strchr(const char *s, int c);
char	*my_substr(char const *s, unsigned int start, size_t len);
char	*my_strdup(const char *s);
size_t	my_strlen(const char *s);
void	ft_putstr(char *str);

// parsing/content_checking_utils.c

int	is_sep(char c);
int is_digit(char c);
int is_only_digit(char *str);
int is_whitespace(char c);
int	is_only_whitespace(char *str);
int	empty_line_check(char *line);
int	is_redir(char c);

	// Temp

//	temp/test.c

char* 	enum_to_str(int spec_enum); //can be removed from .h for now
void	print_tree(t_cmdtree *node);
char	**ft_split(char const *s, char sep);
//void	test_parsing(char *line);
void	free_tab(char **tab);
void	quote_checker_verif(char *str);
void	print_split(char **res);

#endif
