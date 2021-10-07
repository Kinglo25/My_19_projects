/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:07:12 by lmajerus          #+#    #+#             */
/*   Updated: 2021/10/07 16:57:18 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_stack **lst)
{
	t_stack	*tmp;

	if (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		tmp->next = (*lst)->next;
		(*lst)->next = tmp;
	}
}

void	push_from_to(t_stack **from, t_stack **to)
{
	t_stack	*tmp;

	if (*from)
	{
		tmp = (*from)->next;
		(*from)->next = *to;
		*to = *from;
		*from = tmp;
	}
}

void	rotate_stack(t_stack **lst)
{
	t_stack	*tmp;

	if (*lst)
	{
		tmp = (*lst)->next;
		ft_lstlast(*lst)->next = (*lst);
		(*lst) = tmp;
	}
}
