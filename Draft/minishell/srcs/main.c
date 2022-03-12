/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:56:45 by lmajerus          #+#    #+#             */
/*   Updated: 2022/03/01 11:12:21 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**get_envp(char **envp)
{
	size_t	i;
	size_t	len;
	char	**new;

	i = 0;
	len = 0;
	while (envp[i++])
		len++;
	new = malloc(sizeof(new) * (len + 1));
	i = 0;
	while (envp[i])
	{
		new[i] = ft_strdup(envp[i]);
		i++;
	}
	return (new);
}

static void	main_loop(t_mini *shell)
{
	while (19)
	{
		parser(shell);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_mini	shell;

	(void)argc;
	(void)argv;
	shell.envp = get_envp(envp);
	loop(&shell);
}
