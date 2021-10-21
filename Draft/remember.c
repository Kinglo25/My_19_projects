/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remember.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 12:51:53 by lmajerus          #+#    #+#             */
/*   Updated: 2021/10/14 14:24:28 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <unistd.h>

int	main()
{
	int	arr[] = {1, 2, 3, 4, 2, 2, 2, 3, 4, 1};
	int	arr_size = sizeof(arr) / sizeof(int);
	int	start, end;
	int fd0[2];
	int	fd1[2];
	int sum_from_child_1 = 0;
	int id0, id1;
	int total_sum0, total_sum;


	if (pipe(fd0) == -1)
		return 1;
	id0 = fork();
	if (id0 == -1)
		return 2;
	if (id0 == 0)
	{
		if (pipe(fd1) == -1)
			return 1;
		id1 = fork();
		if (id1 == -1)
			return 3;
		if (id1 == 0)
		{
			start = 0;
			end = arr_size / 3;
		}
		else 
		{
			start = arr_size / 3;
			end = arr_size - start;
		}
	}
	else
	{
		start = arr_size - arr_size / 3;
		end = arr_size;
	}
	int sum = 0;
	for (int i = start; i < end; i++)
		sum += arr[i];
	printf("sum = %d\n", sum);
	if (id0 == 0)
	{
		if (id1 == 0)
		{
			close(fd1[0]);
			write(fd1[1], &sum, sizeof(sum));
			close(fd1[1]);
		}
		else
		{
			close(fd1[1]);
			read(fd1[0], &sum_from_child_1, sizeof(sum_from_child_1));
			close(fd1[0]);
			total_sum0 = sum + sum_from_child_1;
			close(fd0[0]);
			write(fd0[1], &total_sum0, sizeof(sum));
			close(fd0[1]);
		}
	}
	else
	{
		close(fd0[1]);
		read(fd0[0], &total_sum0, sizeof(sum_from_child_1));
		close(fd0[0]);
		total_sum = sum + total_sum0;
		printf("%d\n", total_sum);
		wait(NULL);
	}
}
