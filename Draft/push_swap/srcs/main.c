/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:00:02 by lmajerus          #+#    #+#             */
/*   Updated: 2021/10/07 16:55:52 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	create_stack(ac, av, &a);
	push_from_to(&a, &b);
	while (a)
	{
		printf("%d\n", a->num);
		a = a->next;
	}
	printf("---------\n");
	while (b)
	{
		printf("%d\n", b->num);
		b = b->next;
	}
	return (0);
}
