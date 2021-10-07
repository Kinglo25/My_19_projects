/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 17:09:07 by lmajerus          #+#    #+#             */
/*   Updated: 2021/10/07 16:54:10 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
}					t_stack;

/* operations */

void	swap_stack(t_stack **lst);
void	push_from_to(t_stack **to, t_stack **from);
void	rotate_stack(t_stack **lst);

/* utils.c */

int		ft_strcmp(char *s1, char *s2);

/* free_exit.c */

void	free_exit(t_stack **a);

/* parser.c */

t_stack	*create_stack(int ac, char **av, t_stack **a);
t_stack	*ft_lstlast(t_stack *lst);

/* main.c */

#endif
