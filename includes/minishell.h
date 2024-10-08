/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellegr <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:40:23 by lpellegr          #+#    #+#             */
/*   Updated: 2024/09/11 21:27:14 by lpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stddef.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <time.h>
# include <errno.h>

typedef struct s_env
{
	char			*key;
	char			*val;
	int				set;
	int				pos;
	int				init;
	struct s_env	*next;
}	t_env;

typedef struct s_data
{
	char			*line;
	char			*cmd;
	char			**arg;
	int				fd;
	int				flag_redir;
	struct s_data	*next;
}		t_data;

typedef struct s_all
{
	t_data	*data;
	t_env	*env;
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
void	ft_free_env(t_env *env);
void	ft_modify_env(char *s1, char *s2, t_env *env);
char	**ft_reset_env(t_env *env);

/* *******************************BUILTINS*********************************** */

void	ft_builtins(t_all *all);
void	ft_export(t_all *all);
void	ft_print_export(t_env *env);
char	**ft_malloc_tab(int len, char *s, char sep);
char	**ft_split_export(char *s, char sep);
int		ft_check_node(char *s1, char *s2);
void	ft_env(t_env *env);
void	ft_unset(t_data *data, t_env *env);
void	ft_echo(t_all *all);
void	ft_pwd(t_all *all);
void	ft_cd(t_all *all);
void	ft_exit(t_all *all);
void	ft_free_all(t_all *all);
void	ft_free_data(t_data *data);

/* *********************************EXEC************************************* */

void	ft_exec(t_all *all);
void	ft_choose_cmd(t_all *all);
void	ft_docmd(t_all *all);
void	ft_do_pipe(t_all *all);
char	*ft_getpath(char *cmd, char **envp);
char	*ft_getenv_tab(char *name, char **envp);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	**ft_get_args(char *path, char **args);
int		ft_tab_len(char **tab);
int		ft_heredoc(char *delim);
void	ft_handle_out(t_all *all);
void	ft_handle_in(t_all *all);
pid_t	create_child_process(void);
void	handle_child_process(t_all *all, int input_fd, int pipe_fd[2]);
void	perror_and_exit(char *error_message);

/* ******************************UTILS_LIBFT********************************* */

int		ft_strlen(char *str);
int		ft_len(char *str, int i);
int		ft_strncmp(char *s1, char *s2, int n);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlcpy(char *dest, char *src, int size);
int		ft_strchr(char *s, char c);
int		ft_atoi(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_join(char *s1, char *s2);
char	*ft_itoa(int n);
char	*ft_strdup(char *s);
void	ft_free_tab(char **tab);
void	ft_display_err(char *s, t_all *all, int err_status);
int		ft_strlcat(char *dest, char *src, int size);

/* *******************************UTILS_LST********************************** */

t_env	*ft_last_node(t_env	*lst);
int		ft_isvalid(char *str);
int		ft_lstsize(t_env *lst);
void	ft_print_env(t_all *all);
void	ft_print_data(t_data *lst);

//								Parsing

// parsing/content_checking_utils.c

int		is_sep(char c);
int		is_token(char c);
int		is_digit(char c);
int		is_whitespace(char c);
int		is_redir(char c);

// parsing/content_checking_utils2.c

int		is_only_whitespace(char *str, int i, int len);
int		is_only_digit(char *str);
int		is_quote(char c);
int		is_only_quote(char *str);

// 	parsing/init_parsing.c

int		initial_check(char *line, t_all *all);
t_all	*parsing(char *line, t_all *all);
t_data	*init_node(void);
t_data	*fill_args(t_data *data);

//	parsing/initial_check.c

int		empty_line_check(char *line);
int		empty_pipe_check(char *line);
int		is_unclosed_quotes(char *str);
int		redir_error_check(char *line);
int		pipe_follow_redir_check(char *line);

//	parsing/parsing_utils.c

char	*my_strchr(const char *s, int c);
char	*my_substr(char const *s, unsigned int start, size_t len);
char	*my_strdup(const char *s);
size_t	my_strlen(const char *s);
void	ft_putstr(char *str);

// parsing/parsing_utils2.c

int		tab_len(char **tab);
int		arg_tab_len(char **tab);
int		delchar(char **str, int pos, char c);
void	apply_all_clean(char **str, int *i);
void	apply_clean_on_args(t_data *node, t_all *all);

//	parsing/parsing_utils3.c

void	split_free(char **res, int count);
char	*clean_arg(char *str);
int		var_len(char *str, int i);
char	**array_remove_at(char **array, int i);
char	*replace_data_line(char *line, int len);

//	parsing/parsing_utils4.c

void	replace_err(char **arg, int i, t_all *all);

//	parsing/pipe_parsing.c

void	parse_pipe(t_data *node);
int		search_pipe(char *str);
int		check_start_pipe(char *line);
int		check_middle_pipes(char *line);
int		check_end_pipe(char *line);

//	parsing/split_minishell.c

char	*strldup(char *s, int len);
char	**shell_split(char *s, char sep);

//	parsing/quote_parsing.c

void	quote_checker(char *str, int i, int *s_quote, int *d_quote);
void	quote_checker_arg(char c, char next_c, int *s_quote, int *d_quote);
int		is_in_quote(char *str, int pos, int flag);
int		is_unclosed_quotes(char *str);
char	*clean_adjacent_quotes(char *line);

//	parsing/redir_parsing.c

void	parse_redir(t_data *data);

// parsing/var_parsing.c

char	*replace_var_on_arg(char *arg, t_all *all);
char	*return_replace_var(char *arg, char *before_var, char *res);
char	*join_var(char *arg, char *var, int i, int var_len);

// 								Temp

// temp/ft_split.c

char	**ft_split(char const *s, char sep);

//	temp/test.c

void	free_tab_tab(char **tab);
void	print_split(char **res);
void	print_parsing(t_all *all);

#endif