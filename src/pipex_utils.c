/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtinaut- <jtinaut-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 20:17:24 by jtinaut-          #+#    #+#             */
/*   Updated: 2024/11/02 20:17:25 by jtinaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_memory(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		if (arr[i])
			free(arr[i]);
	free(arr);
}

void	emergency_exit(char *func_error, char **arr)
{
	if (arr)
		free_memory(arr);
	perror(func_error);
	exit(1);
}

int	path_explorer(char **env, char ***arr, char **path, char *cmd)
{
	int		i;
	char	*tmp;

	i = -1;
	while (env[++i] && ft_strncmp(env[i], "PATH=", 4) != 0)
		;
	if (ft_strncmp(env[i], "PATH=", 4) != 0)
		return (1);
	env[i] = ft_strchr(env[i], '=');
	*arr = ft_split(++env[i], ':');
	i = -1;
	while ((*arr)[++i])
	{
		tmp = ft_strjoin((*arr)[i], "/");
		*path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!(*path))
			return (1);
		if (access(*path, F_OK) == 0)
			break ;
		free(*path);
		*path = NULL;
	}
	return (0);
}

char	*path_finder(char **env, char *cmd)
{
	char	*path;
	char	**arr;

	if (path_explorer(env, &arr, &path, cmd))
	{
		if (arr)
			free_memory(arr);
		return (NULL);
	}
	free_memory(arr);
	if (!path)
	{
		return (cmd);
	}
	free(cmd);
	return (path);
}

char	**parser_cmd(char *cmd, char **env)
{
	char	**argv;

	argv = ft_split(cmd, ' ');
	if (!argv)
		return (NULL);
	argv[0] = path_finder(env, argv[0]);
	if (!argv[0])
		return (NULL);
	return (argv);
}
