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
	char	*id;
	char	*val;
	int		set;
}	t_env;

#endif