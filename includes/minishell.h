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
	struct s_env	*next; // pointer to the next node
}	t_env;

typedef struct s_data
{
	char		*cmd;	//mettre le path env
	char		**arg; //const ? NULL -> premier argument est le nom du programme.
	int			fd_out;
	int			fd_in;
	int			flag_out; //simple ou double redir; > ou >>
	char 		*here_doc;
	struct s_data		*next;
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
void	ft_print_list(char *str, t_env *lst);

// Parsing part
//t_data	*parsing(char *str);

#endif
