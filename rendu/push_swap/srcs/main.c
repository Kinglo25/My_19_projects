/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:00:02 by lmajerus          #+#    #+#             */
/*   Updated: 2021/10/13 16:21:15 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	long	size;

	a = NULL;
	b = NULL;
	if (ac >= 2)
	{
		create_stack(ac, av, &a);
		is_sorted(a);
		size = index_stack(&a);
		if (ac == 3)
			sa(&a);
		else if (ac >= 4 && ac <= 6)
			sort_small_stacks(&a, &b, ac);
		else
			radix(&a, &b, size);
	}
	free_exit(&a);
}
