/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmajerus <lmajerus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 16:35:29 by lmajerus          #+#    #+#             */
/*   Updated: 2022/01/24 20:34:00 by lmajerus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	int				l_fork;
	int				r_fork;
	int				nb_ate;
	long long		t_last_meal;
	pthread_t		thread_id;
	struct s_glob	*g;
}				t_philo;

typedef struct s_glob
{
	int				nb_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nb_m_eat;
	int				done;
	int				died;
	long long		start_time;
	t_philo			phil[200];
	pthread_mutex_t	writing;
	pthread_mutex_t	check;
	pthread_mutex_t	forks[200];
}				t_glob;
