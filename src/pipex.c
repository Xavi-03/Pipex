/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:17:09 by jtinaut-          #+#    #+#             */
/*   Updated: 2024/11/02 20:17:15 by jtinaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	son_home(int *fd_pipe, char *infile, char *cmd, char **env)
{
	int		fd;
	char	**argv;

	argv = parser_cmd(cmd, env);
	if (!argv)
		emergency_exit("malloc", argv);
	fd = open(infile, O_RDONLY);
	if (fd < 0)
		emergency_exit("open", argv);
	dup2(fd, STDIN_FILENO);
	close(fd);
	close(fd_pipe[0]);
	dup2(fd_pipe[1], STDOUT_FILENO);
	close(fd_pipe[1]);
	execve(argv[0], argv, env);
	emergency_exit("execve", argv);
}

void	father_home(int *fd_pipe, char *outfile, char *cmd, char **env)
{
	int		fd;
	char	**argv;

	argv = parser_cmd(cmd, env);
	if (!argv)
		emergency_exit("cmd", argv);
	fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		emergency_exit("open", argv);
	close(fd_pipe[1]);
	dup2(fd_pipe[0], STDIN_FILENO);
	close(fd_pipe[0]);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	execve(argv[0], argv, env);
	emergency_exit("execve", argv);
}

int	main(int argc, char **argv, char **env)
{
	int		fd_pipe[2];
	pid_t	pid;

	if (argc != 5)
	{
		write(2, "Error: 4 arguments are needed!\n", 32);
		exit(1);
	}
	if (pipe(fd_pipe) < 0)
		emergency_exit("pipe", NULL);
	pid = fork();
	if (pid == -1)
		emergency_exit("fork", NULL);
	else if (pid == 0)
		son_home(fd_pipe, argv[1], argv[2], env);
	father_home(fd_pipe, argv[4], argv[3], env);
	return (1);
}
