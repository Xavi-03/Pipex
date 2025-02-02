/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:17:34 by jtinaut-          #+#    #+#             */
/*   Updated: 2024/11/02 20:17:36 by jtinaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>

void	father_home(int *fd_pipe, char *outfile, char *cmd, char **env);
void	son_home(int *fd_pipe, char *infile, char *cmd, char **env);
char	**parser_cmd(char *cmd, char **env);
void	emergency_exit(char *func_error, char **arr);
char	*path_finder(char **env, char *cmd);
int		path_explorer(char **env, char ***arr, char **path, char *cmd);
void	free_memory(char **arr);

#endif
