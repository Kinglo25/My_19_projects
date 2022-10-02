/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loic Majerus <loic.majerus@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 17:04:22 by Loic Majeru       #+#    #+#             */
/*   Updated: 2022/10/01 17:15:37 by Loic Majeru      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_pop(t_node **head)
{
    t_node *tmp;
    int     buff;

    if (*head == NULL)
    {
        printf("Stack underflow\n");
        exit(0);
    }
    tmp = (*head)->next;
    buff = (*head)->data;
    free(*head);
    *head = tmp;
    return (buff);
}