/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:51:35 by junhyupa          #+#    #+#             */
/*   Updated: 2023/04/05 14:27:16 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_down_fork(t_philo *philo)
{
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;

	right_fork = &philo->info->forks[philo->num];
	left_fork = &philo->info->forks[(philo ->num + 1) % philo->info->philo_num];
	pthread_mutex_unlock(left_fork);
	pthread_mutex_unlock(right_fork);
}

void	pick_fork(t_philo *philo)
{
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;

	right_fork = &philo->info->forks[philo->num];
	left_fork = &philo->info->forks[(philo ->num + 1) % philo->info->philo_num];
	pthread_mutex_lock(right_fork);
	pthread_mutex_lock(left_fork);
}

void	philosopher(void *philo)
{
	(t_philo *)philo;
	if (!(philo->num % 2))
		usleep(10);
	while(1)
	{
		pick_fork(philo);
		usleep(philo->info->time_to_eat * 1000);
		put_down_fork(philo);
		usleep(philo->info->time_to_sleep * 1000);
	}
}