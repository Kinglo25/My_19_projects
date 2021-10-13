/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:25:50 by lmajerus          #+#    #+#             */
/*   Updated: 2021/10/13 16:31:21 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_of_3(t_stack **a)
{
	if ((*a)->num > (*a)->next->num && (*a)->num < (*a)->next->next->num)
		sa(a);
	if ((*a)->next->num < (*a)->num && (*a)->next->num
		> (*a)->next->next->num)
	{
		sa(a);
		rra(a);
	}
	if ((*a)->next->next->num < (*a)->num
		&& (*a)->next->next->num > (*a)->next->num)
		ra(a);
	if ((*a)->next->next->num > (*a)->num
		&& (*a)->next->next->num < (*a)->next->num)
	{
		sa(a);
		ra(a);
	}
	if ((*a)->num < (*a)->next->num && (*a)->num > (*a)->next->next->num)
		rra(a);
}

static long	find_position(t_stack *a, int x)
{
	long	count;

	count = 0;
	while (a->index != 0 && x == 0)
	{
		count++;
		a = a->next;
	}
	while (a->index != 1 && x == 1)
	{
		count++;
		a = a->next;
	}
	return (count);
}

static void	stack_of_4(t_stack **a, t_stack **b, int ac)
{
	if (ac == 5)
	{
		if (find_position(*a, 0) < 3)
			while ((*a)->index != 0)
				ra(a);
		else
			while ((*a)->index != 0)
				rra(a);
		pb(a, b);
		stack_of_3(a);
		pa(b, a);
	}
}

static void	stack_of_5(t_stack **a, t_stack **b, int ac)
{
	if (ac == 6)
	{
		if (find_position(*a, 1) < 3)
			while ((*a)->index != 0)
				ra(a);
		else
			while ((*a)->index != 0)
				rra(a);
		pb(a, b);
		if (find_position(*a, 1) < 3)
			while ((*a)->index != 1)
				ra(a);
		else
			while ((*a)->index != 1)
				rra(a);
		pb(a, b);
		stack_of_3(a);
		pa(b, a);
		pa(b, a);
	}
}

void	sort_small_stacks(t_stack **a, t_stack **b, int ac)
{
	if (ac == 4)
		stack_of_3(a);
	if (ac == 5)
		stack_of_4(a, b, ac);
	if (ac == 6)
		stack_of_5(a, b, ac);
}
