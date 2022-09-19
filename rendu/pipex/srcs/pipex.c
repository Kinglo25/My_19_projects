/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 16:03:26 by lmajerus          #+#    #+#             */
/*   Updated: 2021/12/15 13:44:55 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_path(char *envp[])
{
	size_t	i;

	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp("PATH=", envp[i], 5))
			return (ft_substr(envp[i], 5, ft_strlen(envp[i])));
		i++;
	}
	ft_error("Envp undefined\n");
	return (NULL);
}

static char	**do_path(t_p *pipex, int x)
{
	size_t	i;
	char	**split;

	split = ft_split(get_path(pipex->env), ':');
	i = 0;
	while (split[i])
	{
		split[i] = ft_strjoin(split[i], "/");
		if (x == 1)
			split[i] = ft_strjoin(split[i], pipex->split_cmd1[0]);
		if (x == 2)
			split[i] = ft_strjoin(split[i], pipex->split_cmd2[0]);
		i++;
	}
	if (split == NULL)
		ft_error("Split failed\n");
	return (split);
}

static void	fill_struct(char *av[], char *envp[], t_p *pipex)
{
	pipex->fd_in = open(av[1], O_RDONLY);
	pipex->fd_out = open(av[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (pipex->fd_in < 0 || pipex->fd_out < 0)
		ft_error("Failed to open files\n");
	pipex->cmd1 = av[2];
	pipex->cmd2 = av[3];
	pipex->env = envp;
	pipex->split_cmd1 = ft_split(pipex->cmd1, ' ');
	pipex->split_cmd2 = ft_split(pipex->cmd2, ' ');
	if (pipex->split_cmd1 == NULL || pipex->split_cmd2 == NULL)
		ft_error("Split failed\n");
	pipex->path1 = do_path(pipex, 1);
	pipex->path2 = do_path(pipex, 2);
	if (pipex->path1 == NULL || pipex->path2 == NULL)
		ft_error("No path\n");
}

int	main(int ac, char *av[], char *envp[])
{
	t_p	pipex;

	if (ac != 5)
		ft_error("Invalid # of arg\n");
	fill_struct(av, envp, &pipex);
	if (pipe(pipex.end) < 0)
		ft_error("Pipe failure\n");
	exec_cmd1(&pipex);
	exec_cmd2(&pipex);
	ft_free(&pipex);
	return (0);
}
