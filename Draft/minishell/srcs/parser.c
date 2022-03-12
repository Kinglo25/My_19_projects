/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:27:09 by lmajerus          #+#    #+#             */
/*   Updated: 2022/03/01 11:27:57 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_syntax(t_token *first)
{
	if (!first && first->type == TOKEN_PIPE)
		return (ft_error("Syntax error"));
	while (first)
	{
		if ((first->type == TOKEN_REDIR_IN || first->type == TOKEN_REDIR_IN)
		&& (first->next->type == TOKEN_REDIR_IN || first->next->type == TOKEN_REDIR_IN))
			return (ft_error("Syntax error"));
		if ((first->type == TOKEN_REDIR_IN || first->type == TOKEN_REDIR_IN || first->type == TOKEN_PIPE)
			 && !first->next)
			return (ft_error("Syntax error"));
		if 
		
	}
}

int	parser(t_mini *shell)
{
	t_token	*first;

	first = NULL;
	shell->line = readline("Minishell 🐚 >");
	if (tokenize(shell, &first, shell->line)
		return (ft_error("Syntax error"));
	if (check_syntax(first))
		return (1);
}