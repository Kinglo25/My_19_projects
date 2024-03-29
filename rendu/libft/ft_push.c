/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loic Majerus <loic.majerus@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:31:17 by Loic Majeru       #+#    #+#             */
/*   Updated: 2022/10/01 17:16:49 by Loic Majeru      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_push(t_node **head, int data)
{
    t_node *newNode;

    newNode = malloc(sizeof(t_node));
    if (!newNode)
    {
        printf("Stack overflow\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    return;
}
