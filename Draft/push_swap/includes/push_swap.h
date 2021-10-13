/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:09:07 by lmajerus          #+#    #+#             */
/*   Updated: 2021/10/13 12:28:41 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	long			num;
	unsigned int	index;
	struct s_stack	*next;
}					t_stack;

/* operations */

void	sa(t_stack **lst);
void	sb(t_stack **lst);
void	ss(t_stack **a, t_stack **b);

void	pa(t_stack **from, t_stack **to);
void	pb(t_stack **from, t_stack **to);

void	ra(t_stack **lst);
void	rb(t_stack **lst);
void	rr(t_stack **a, t_stack **b);

void	rra(t_stack **lst);
void	rrb(t_stack **lst);
void	rrr(t_stack **a, t_stack **b);

/* ft_split.c */

char	**ft_split(char const *s, char c, long *nb_str);

/* utils.c */

int		ft_strcmp(char *s1, char *s2);
void	is_sorted(t_stack *a);
int		is_macro(char *str);

/* free_exit.c */

void	free_exit_error(t_stack **a);
void	free_exit(t_stack **a);

/* parser.c */

void	create_stack(long ac, char **av, t_stack **a);

/* index.c */

long	index_stack(t_stack **a);

/* sort_big_stacks.c */

void	radix(t_stack **a, t_stack **b, long max_index);

/* sort_small_stacks */

void	sort_small_stacks(t_stack **a, t_stack **b, int ac);

#endif
