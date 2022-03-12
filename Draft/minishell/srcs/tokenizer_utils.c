/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 11:08:06 by lmajerus          #+#    #+#             */
/*   Updated: 2022/03/01 11:33:19 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n--)
	{
		if (*s1 != *s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		if (!*s1)
			return (0);
		s1++;
		s2++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	new = malloc(sizeof(*s) * (len + 1));
	if (!new)
		return (NULL);
	new[len] = '\0';
	while (i < len && start + i < ft_strlen(s))
	{
		new[i] = s[start + i];
		i++;
	}
	return (new);
}

/*
Compare size char from line with all possible op 
*/

int	token_search(char *line)
{
	const t_operations		tab[12] = {
	{">>", 2, TOKEN_REDIR_OUT},
	{"<<", 2, TOKEN_REDIR_IN},
	{"|", 1, TOKEN_PIPE},
	{">", 1, TOKEN_REDIR_OUT},
	{"<", 1, TOKEN_REDIR_IN},
	{" ", 1, TOKEN_SPACE},
	{"\n", 1, TOKEN_SPACE},
	{"\v", 1, TOKEN_SPACE},
	{"\t", 1, TOKEN_SPACE},
	{"\r", 1, TOKEN_SPACE},
	{"\f", 1, TOKEN_SPACE},
	{NULL, 1, 0}
	};
	const t_operations		blank = {0, 0, 0};
	int						i;

	i = 0;
	while (tab[i].op)
	{
		if (!ft_strncmp(line, tab[i].op, tab[i].size))
			return (tab[i]);
		i++;
	}
	return (blank);
}
