/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 19:05:45 by lmajerus          #+#    #+#             */
/*   Updated: 2021/10/07 19:15:26 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **lst)
{
	t_stack	*tmp;

	if (*lst)
	{
		tmp = *lst;
		while ((*lst)->next)
			*lst = (*lst)->next;
		(*lst)->next = tmp;
		*lst = tmp->next;
		tmp->next = NULL;
	}
	write(1, "ra\n", 3);
}

void	rb(t_stack **lst)
{
	t_stack	*tmp;

	if (*lst)
	{
		tmp = *lst;
		while ((*lst)->next)
			*lst = (*lst)->next;
		(*lst)->next = tmp;
		*lst = tmp->next;
		tmp->next = NULL;
	}
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (*a)
	{
		tmp = *a;
		while ((*a)->next)
			*a = (*a)->next;
		(*a)->next = tmp;
		*a = tmp->next;
		tmp->next = NULL;
	}
	if (*b)
	{
		tmp = *b;
		while ((*b)->next)
			*b = (*b)->next;
		(*b)->next = tmp;
		*b = tmp->next;
		tmp->next = NULL;
	}
	write(1, "rr\n", 3);
}
