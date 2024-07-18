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

typedef struct s_data //what i give to liv
{
	char		*cmd;	//mettre le path env - get ma fonction pipex qui permet de creer un path from funct
	char		**arg; //const ? premier argument est le nom du programme, dernier est NULL
	int			fd_out; //fd_out et in same thing
	int			fd_in;
	int			flag_out; //simple ou double redir; > ou >> O_CREATE or O_APPEND
	char 		*here_doc; //change for int fd
	struct s_data		*next;
} 	t_data; //fill en * simple (ptr simple) pour l'exec.

// my enum

typedef enum s_tokentype
{
	EXEC,
	PIPE,
	IN_REDIR,
	OUT_REDIR,
	HERE_DOC,
	DEFAULT
}			t_tokentype;

typedef struct s_parsing
{
	int	type; //default, need to define clearly which type i need.
	char *str; //initial_str
	char **arg; //command_args
	int fd; //in case of pipe and redir -> keep only the last fd open
	struct s_parsing	*part1; //left
	struct s_parsing	*part2; //right
}	t_parsing;

// End parsing struct.

/* Functions */

/* *********************************ENV.C************************************ */
t_env	*ft_copy_env(t_env *env, char **envp);

/* ******************************BUILTINS.C********************************** */
//		Parsing part

// parsing/init_parsing.c

//	parsing/parsing_utils.c

char	*ft_strchr(char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *s);

#endif
