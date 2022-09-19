/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:49:14 by lmajerus          #+#    #+#             */
/*   Updated: 2021/12/15 16:05:05 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd1(t_p *pipex)
{
	size_t	i;

	pipex->id1 = fork();
	if (pipex->id1 < 0)
		ft_error("Fork Failed\n");
	if (pipex->id1 == 0)
	{
		dup2(pipex->fd_in, STDIN_FILENO);
		dup2(pipex->end[1], STDOUT_FILENO);
		close(pipex->end[0]);
		i = 0;
		while (pipex->path1[i])
			execve(pipex->path1[i++], pipex->split_cmd1, pipex->env);
		ft_error("Couldn't execute the command\n");
	}
	waitpid(pipex->id1, NULL, 0);
	close(pipex->fd_in);
	close(pipex->end[1]);
}

void	exec_cmd2(t_p *pipex)
{
	size_t	i;

	pipex->id2 = fork();
	if (pipex->id2 < 0)
		ft_error("Fork Failed\n");
	if (pipex->id2 == 0)
	{
		dup2(pipex->end[0], STDIN_FILENO);
		dup2(pipex->fd_out, STDOUT_FILENO);
		i = 0;
		while (pipex->path2[i])
			execve(pipex->path2[i++], pipex->split_cmd2, pipex->env);
		ft_error("Couldn't execute the command\n");
	}
	waitpid(pipex->id2, NULL, 0);
	close(pipex->fd_out);
	close(pipex->end[0]);
}
