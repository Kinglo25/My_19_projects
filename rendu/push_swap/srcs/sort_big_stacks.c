/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stacks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 15:05:44 by lmajerus          #+#    #+#             */
/*   Updated: 2021/10/12 18:20:13 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(t_stack **a, t_stack **b, long i, long max_index)
{
	long	num;
	long	j;
	long	count;

	j = 0;
	count = 0;
	while (j < max_index)
	{
		num = (*a)->index;
		if (((num >> i) & 1) == 1)
			ra(a);
		else
		{
			pb(a, b);
			count++;
		}
		j++;
	}
	while (count--)
		pa(b, a);
}

void	radix(t_stack **a, t_stack **b, long max_index)
{
	long	max_bits;
	long	i;

	i = 0;
	max_bits = 0;
	while ((max_index >> max_bits) != 0)
		max_bits++;
	while (i < max_bits)
	{	
		sort(a, b, i, max_index);
		i++;
	}
}
