/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hugo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 16:57:57 by lmajerus          #+#    #+#             */
/*   Updated: 2021/03/04 18:15:53 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef enum	{false, true} bool;

int		main(void)
{
	char *s1;
	int x = 42;
	bool m = false;

	s1 = "no it's not fking geek";
	printf("{%3.3s}\n{%.3d}\n%d\n", s1, x, m);
}