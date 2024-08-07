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
	char			*key; // name of the variable (ex : USER, PATH, SHLVL...)
	char			*val; // value of the variable
	int				set; // flag to set or unset the variable (for unset)
	int				pos; // final position in ascii order (for export)
	int				init;
	struct s_env	*next; // pointer to the next node
}	t_env;

typedef struct s_data
{
	char			*cmd;	//mettre le path env
	char			**arg; //const ? NULL -> premier argument est le nom du programme.
	int				fd_out;
	int				fd_in;
	int				flag_out; //simple ou double redir; > ou >>
	char			*here_doc;
	struct s_data	*next;
}		t_data; // fill en * simple pour l'exec.

// - Parsing struct
typedef struct s_parsing
{
	char				*cmd;
	struct s_parsing	*part1;
	struct s_parsing	*part2;
}	t_parsing;

// - End parsing struct.

typedef struct s_all
{
	t_data	*data;
	t_env	*env;
	char	**env_cpy;
	int		err;
	
}		t_all;

/* Functions */

/* ********************************SIGNALS*********************************** */
void	ft_handler(int	sig, siginfo_t *s_info, void *context);
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
void	ft_env(t_env *env);
void	ft_unset(t_data *data, t_env *env);
void	ft_echo(t_all *all);
void	ft_pwd(t_all *all);
void	ft_cd(t_all *all);
void	ft_exit(t_all *all);

/* ******************************UTILS_LIBFT********************************* */
int		ft_strlen(char *str);
int		ft_len(char *str, int i);
int		ft_strncmp(char *s1, char *s2, int n);
int		ft_strlcpy(char *dest, char *src, int size);
int		ft_strchr(char *s, char c);
int		ft_atoi(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_itoa(int n);
char	*ft_strdup(char *s);
void	free_tab(char **tab);
void	ft_display_error(char *s, t_all *all, int err_status);


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

#endif
