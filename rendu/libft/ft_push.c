/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loic Majerus <loic.majerus@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 15:31:17 by Loic Majeru       #+#    #+#             */
/*   Updated: 2022/10/01 15:31:17 by Loic Majeru      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int main()
{
    int x = 0;
    t_list *test = malloc(sizeof(t_list));

    while (x < 5)
    {
        push(&test, x++);
    }
    while (test)
    {
        printf("%i\n", test->content);
    }
}

void    push(t_list **head, void *content)
{
    t_list *newNode;

    newNode = malloc(sizeof(t_list));
    if (!newNode)
        exit(0);
    newNode->content = content;
    newNode->next = *head;
    *head = newNode;
}
