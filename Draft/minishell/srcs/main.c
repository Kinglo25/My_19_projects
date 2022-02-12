/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:17:50 by lmajerus          #+#    #+#             */
/*   Updated: 2022/02/11 17:36:35 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_cmd		cmd;
	t_minishell	minishell;

	(void)ac;
	(void)av;
	(void)env;
	(void)cmd;
	while (19)
	{
		minishell.user_input = readline("🐚 ");
		free(minishell.user_input);
	}
	return (0);
}
