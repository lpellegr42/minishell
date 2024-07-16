#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdlib.h> //Basic lib
#include <unistd.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

#include <signal.h> //Usefull lib
#include <sys/types.h>
#include <time.h>


typedef struct s_env
{
	char	*key;
	char	*val;
	int		set;
	struct s_env	*next;
}	t_env;

// typedef struct s_data
// {
// 	t_env	*env;
// }	t_data;

/* *********************************ENV.C************************************ */
t_env	*ft_copy_env(t_env *env, char	**envp);

/* *****************************UTILS_LIBFT.C******************************** */
int	ft_strlen(char *str);
int	ft_len(char *str, int i);
char    *ft_strjoin(char *s1, char *s2);

/* ******************************UTILS_LST.C********************************* */
t_env	*ft_last_node(t_env	*lst);
#endif