/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:49:55 by lmajerus          #+#    #+#             */
/*   Updated: 2022/03/01 11:13:08 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Create new token
*/

static t_token	*create_token(char *begin, int size, t_type type)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->content = ft_substr(begin, 0, size);
	new->size = size;
	new->type = type;
	new->next = NULL;
	return (new);
}

static t_token	last_token(t_token *token)
{
	while (token)
	{
		if (!token->next)
			return (token);
		token = token->next;
	}
	return (token);
}

static void	add_token(t_token **token, t_token new)
{
	if (!*token)
		*token = new;
	else
		last_token(*token)->next = new;
}

static int	find_next_quotes(char **line)
{
	char	quotes;

	quotes = **line;
	while (*(*line++))
		if (**line == quotes && *line++)
			return (0);
	return (1);
}

int	tokenizer(t_mini shell, t_token **first, char *line)
{
	t_operations	curr;
	char			*tmp;

	tmp = line;
	i = 0;
	while (line && *line)
	{
		curr = token_search(line);
		if (curr.op != 0 && line != tmp)
			add_token(first, create_token(tmp, line - tmp, curr.type));
		else if (curr.op != 0)
		{
			line += curr.size;
			if (curr.type != TOKEN_SPACE)
				add_token (first, create_token(curr.op, curr.size, curr.type));
			tmp = line;
		}
		else if ((line == '\'' || line == '\"') && find_next_quotes(&line))
			return (0);
		else
			line++;
	}
	if (tmp != line)
		add_token(first, create_token(tmp, line - tmp, TOKEN_LAST));
	return (1);
}
