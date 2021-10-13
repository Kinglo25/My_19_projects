/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:45:48 by lmajerus          #+#    #+#             */
/*   Updated: 2021/10/13 15:28:22 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	lstsize(t_stack *lst)
{
	long	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = (lst)->next;
	}
	return (size);
}

static void	put_in_tab(t_stack *a, int *tab)
{
	long	i;

	i = 0;
	while (a)
	{
		tab[i] = a->num;
		a = a->next;
		i++;
	}
}

static void	sort_tab(int *tab, long size)
{
	long	i;
	long	j;
	int		tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

static void	put_index_in_stack(t_stack **a, long size, int *tab)
{
	unsigned int	i;
	t_stack			*tmp;

	i = 0;
	while (i < size)
	{
		tmp = *a;
		while (tmp)
		{
			if (tmp->num == tab[i])
			{
				tmp->index = i;
				break ;
			}
			tmp = tmp->next;
		}
		i++;
	}
}

long	index_stack(t_stack **a)
{
	int				*tab;
	long			size;

	size = lstsize(*a);
	tab = malloc(size * sizeof(int));
	if (!tab)
		free_exit_error(a);
	put_in_tab(*a, tab);
	sort_tab(tab, size);
	put_index_in_stack(a, size, tab);
	free(tab);
	return (size);
}
