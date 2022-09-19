/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:08:31 by lmajerus          #+#    #+#             */
/*   Updated: 2021/12/14 13:10:11 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error(char *errstr)
{
	perror(errstr);
	exit(EXIT_FAILURE);
}

void	ft_free(t_p *pipex)
{
	size_t	i;

	i = 0;
	while (pipex->path1[i])
		free(pipex->path1[i++]);
	free(pipex->path1);
	i = 0;
	while (pipex->path2[i])
		free(pipex->path2[i++]);
	free(pipex->path2);
	i = 0;
	while (pipex->split_cmd1[i])
		free(pipex->split_cmd1[i++]);
	free(pipex->split_cmd1);
	i = 0;
	while (pipex->split_cmd2[i])
		free(pipex->split_cmd2[i++]);
	free(pipex->split_cmd2);
}
