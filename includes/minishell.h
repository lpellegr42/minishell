#ifndef MINISHELL_H
#define MINISHELL_H

#include "utils.h"

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
}	t_env;

typedef struct s_data
{
	t_env	*env;
}	t_data;

/* *********************************ENV.C************************************ */
void	ft_copy_env(t_env *env, char	**envp);

/* ************************************************************************** */
#endif