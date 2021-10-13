/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 16:53:34 by lmajerus          #+#    #+#             */
/*   Updated: 2021/10/12 19:03:59 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_atoi(char *str, t_stack **a)
{
	long	ans;
	int		i;
	int		signe;

	ans = 0;
	i = 0;
	signe = 1;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1])
	{
		if (str[i] == '-')
			signe *= -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			free_exit_error(a);
		ans *= 10;
		ans += (int)(str[i] - 48);
		i++;
	}
	ans *= signe;
	if (ans > 2147483647 || ans < -2147483648)
		free_exit_error(a);
	return (ans);
}

static t_stack	*ft_lstnew(int content, t_stack **a)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		free_exit_error(a);
	new->num = content;
	new->next = NULL;
	return (new);
}

static	t_stack	*ft_lstlast(t_stack *lst)
{
	while (lst)
	{
		if (!lst->next)
			break ;
		lst = lst->next;
	}
	return (lst);
}

static void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	if (!*lst)
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}

void	create_stack(long ac, char **av, t_stack **a)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (!ft_strcmp(av[i], av[j]))
				free_exit_error(a);
			j++;
		}
		i++;
	}
	i = 1;
	while (i < ac)
		ft_lstadd_back(a, ft_lstnew(ft_atoi(av[i++], a), a));
}
