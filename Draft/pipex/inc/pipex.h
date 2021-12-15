/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:03:22 by lmajerus          #+#    #+#             */
/*   Updated: 2021/12/14 13:20:17 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct t_pipex
{
	int		fd_in;
	int		fd_out;
	int		end[2];
	pid_t	id1;
	pid_t	id2;
	char	*cmd1;
	char	*cmd2;
	char	**env;
	char	**path1;
	char	**path2;
	char	**split_cmd1;
	char	**split_cmd2;
}				t_p;

// Error.c

void	ft_error(char *errstr);
void	ft_free(t_p *pipex);

// Cmd.c

void	exec_cmd1(t_p *pipex);
void	exec_cmd2(t_p *pipex);

// Pipex.c

// Utils.c

char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);

#endif