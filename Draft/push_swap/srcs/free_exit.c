/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 17:12:40 by lmajerus          #+#    #+#             */
/*   Updated: 2021/10/06 15:44:45 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_stack **a)
{
	t_stack	*current;

	if (!*a)
		return ;
	current = *a;
	while (current)
	{
		current = (*a)->next;
		free(*a);
		*a = current;
	}
}

void	free_exit(t_stack **a)
{
	write(2, "Error\n", 6);
	free_stack(a);
	exit(1);
}
