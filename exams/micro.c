/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:29:08 by lmajerus          #+#    #+#             */
/*   Updated: 2022/06/07 13:17:18 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

enum e_std
{
	STD_IN,
	STD_OUT,
	STD_ERR
};

enum e_type
{
	TYPE_END,
	TYPE_PIPE,
	TYPE_BREAK
};

typedef struct s_base
{
	char			**argv;
	int				type;
	int				size;
	int				pipe[2];
	struct s_base	*next;
	struct s_base	*prev;
}				t_base;

int ft_strlen(char *str)
{
	int i = 0;

	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char *ft_strdup(char *str)
{
	int size = ft_strlen(str);
	char *new;

	if (!str)
		return (NULL);
	if (!(new = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	new[size] = '\0';
	while (--size >= 0)
		new[size] = str[size];
	return (new);
}

void	exit_fatal(void)
{
	write(STD_ERR, "Error: fatal\n", ft_strlen("Error: fatal\n"));
	exit(EXIT_FAILURE);
}

void exit_execve(char *str)
{
	write(STD_ERR, "error: cannot execute ", ft_strlen("error: cannot execute "));
	write(STD_ERR, str, ft_strlen(str));
	write(STD_ERR, "\n", 1);
	exit(EXIT_FAILURE);
}

int exit_cd_1()
{
	write(STD_ERR, "error: cd: bad arguments\n", ft_strlen("error: cd: bad arguments\n"));
	return (EXIT_FAILURE);
}

int exit_cd_2(char *str)
{
	write(STD_ERR, "error: cd: cannot change directory to ", ft_strlen("error: cd: cannot change directory to "));
	write(STD_ERR, str, ft_strlen(str));
	write(STD_ERR, "\n", 1);
	return (EXIT_FAILURE);
}


int	get_size(char **av)
{
	int	i;

	i = 0;
	while (av[i] && strcmp(av[i], ";") && strcmp(av[i], "|"))
		i++;
	return (i);
}

void	free_all(t_base *ptr)
{
	t_base	*tmp;
	int		i;

	while (ptr)
	{
		tmp = ptr->next;
		i = 0;
		while (i < ptr->size)
			free(ptr->argv[i++]);
		free(ptr->argv);
		free(ptr);
		ptr = tmp;
	}
	ptr = NULL;
}

int	check_end(char *av)
{
	if (!av)
		return (TYPE_END);
	if (strcmp(av, ";") == 0)
		return (TYPE_BREAK);
	if (strcmp(av, "|") == 0)
		return (TYPE_PIPE);
	return (0);
}

void	ft_lstadd_back(t_base **ptr, t_base *new)
{
	t_base	*begin;

	if (!(*ptr))
		*ptr = new;
	else
	{
		begin = *ptr;
		while (begin->next)
			begin = begin->next;
		begin->next = new;
		new->prev = begin;
	}
}

int	parser(t_base **ptr, char **av)
{
	t_base	*new;
	int		size;

	size = get_size(av);
	new = malloc(sizeof(t_base));
	if (!new)
		exit_fatal();
	new->argv = malloc((size + 1) * sizeof(char *));
	if (!new->argv)
		exit_fatal();
	new->size = size;
	new->next = NULL;
	new->prev = NULL;
	new->argv[size] = NULL;
	while (size-- >= 0)
		new->argv[size] = ft_strdup(av[size]);
	new->type = check_end(av[new->size]);
	ft_lstadd_back(ptr, new);
	return (new->size);
}

void	exec_cmd(t_base *tmp, char **env)
{
	int		status;
	int		pipe_open;
	pid_t	pid;

	pipe_open = 0;
	if (tmp->type == TYPE_PIPE || (tmp->prev && tmp->prev->type == TYPE_PIPE))
	{
		pipe_open = 1;
		if (pipe(tmp->pipe))
			exit_fatal();
	}
	pid = fork();
	if (pid < 0)
		exit_fatal();
	else if (pid == 0)
	{
		if (tmp->type == TYPE_PIPE && dup2(tmp->pipe[STD_OUT], STD_OUT) < 0)
			exit_fatal();
		if (tmp->prev && tmp->prev->type == TYPE_PIPE && dup2(tmp->pipe[STD_IN], STD_IN) < 0)
			exit_fatal();
		if (execve(tmp->argv[0], tmp->argv, env) < 0)
			exit_execve(tmp->argv[0]);
		exit(EXIT_SUCCESS);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (pipe_open)
		{
			close(tmp->pipe[STD_OUT]);
			if (!tmp->next || tmp->type == TYPE_BREAK)
				close(tmp->pipe[STD_IN]);
		}
		if (tmp->prev && tmp->prev->type == TYPE_PIPE)
			close(tmp->prev->pipe[STD_IN]);
	}
}

void	exec_cmds(t_base *ptr, char **env)
{
	t_base	*tmp;

	tmp = ptr;
	while (tmp)
	{
		if (strcmp(tmp->argv[0], "cd") == 0)
		{
			if (tmp->size < 2)
				exit_cd_1();
			else if (chdir(tmp->argv[1]))
				exit_cd_2(tmp->argv[1]);
		}
		else
			exec_cmd(tmp, env);
		tmp = tmp->next;
	}
}

int	main(int ac, char **av, char **env)
{
	t_base	*ptr;
	int		i;

	ptr = NULL;
	i = 1;
	if (ac > 1)
	{
		while (av[i])
		{
			if (strcmp(av[i], ";") == 0)
			{
				i++;
				continue ;
			}
			i += parser(&ptr, av + i);
			if (!av[i])
				break ;
			else
				i++;
		}
		if (ptr)
			exec_cmds(ptr, env);
		free_all(ptr);
	}
	return (0);
}