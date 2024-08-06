/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpellegr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 15:30:26 by lpellegr          #+#    #+#             */
/*   Updated: 2024/06/28 16:50:43 by lpellegr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

# define BUFFER_SIZE 5

// error_utils.c
void	free_arrays(char **array);
void	argument_error(void);
void	error_handler(char *error_msg);

// parsing_utils.c
int		parsing(int argc, char **argv);
int		argument_checking(int argc, int is_here_doc);

// string_utils.c
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(char *str);
int		ft_strncmp(char *s1, char *s2, int n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);

//sys_utils.c
int		open_file(char *file, int in_out);
void	exec(char *cmd, char **envp);
char	*get_path(char *cmd, char **envp);
char	*my_getenv(char *name, char **envp);

// ft_split.c
char	**ft_split(char const *s, char sep);

// get_next_line.c
char	*get_next_line(int fd);

//get_next_line_utils.c
char	*gnl_substr(const char *s, unsigned int start, size_t len);
char	*gnl_strjoin(char *s1, char const *s2);
char	*gnl_strdup(char const *src);
size_t	gnl_strlen(char const *s);
char	*gnl_strchr(char const *s, int c);

#endif