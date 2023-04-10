/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:51:35 by junhyupa          #+#    #+#             */
/*   Updated: 2023/04/10 20:21:11 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_down_fork(t_philo *philo)
{
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;

	right_fork = &philo->info->forks[philo->num - 1].mutex;
	left_fork = &philo->info->forks[philo->num % philo->info->philo_num].mutex;
	philo->info->forks[philo->num - 1].status--;
	philo->info->forks[philo->num % philo->info->philo_num].status--;
	if (right_fork == left_fork)
		return ;
	pthread_mutex_unlock(left_fork);
	pthread_mutex_unlock(right_fork);
	pthread_mutex_lock(&(philo->use_philo));
	philo->last_eat = nowtime();
	philo->cnt_eat++;
	pthread_mutex_unlock(&(philo->use_philo));
}

void	pick_fork(t_philo *philo)
{
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;

	if (!check_live(philo->info, 0))
		return ;
	right_fork = &philo->info->forks[philo->num - 1].mutex;
	left_fork = &philo->info->forks[philo->num % philo->info->philo_num].mutex;
	pthread_mutex_lock(right_fork);
	print_state(philo, 1);
	if (left_fork == right_fork)
	{
		while (check_live(philo->info, 0))
			usleep(100);
		pthread_mutex_unlock(right_fork);
		return ;
	}
	pthread_mutex_lock(left_fork);
	print_state(philo, 1);
	philo->info->forks[philo->num - 1].status++;
	philo->info->forks[philo->num % philo->info->philo_num].status++;
}

void	waiting(int time, t_philo *philo)
{
	while (nowtime() - philo->last_status < time && check_live(philo->info, 0))
		usleep(100);
}

void	*philosopher(void *philo_p)
{
	t_philo	*philo;

	philo = (t_philo *)philo_p;
	if (philo->num % 2)
		waiting(philo->info->time_to_eat / 10 * 8, philo);
	while (check_live(philo->info, 0))
	{
		pick_fork(philo);
		print_state(philo, 2);
		waiting(philo->info->time_to_eat, philo);
		put_down_fork(philo);
		if (!check_live(philo->info, 0))
			break ;
		print_state(philo, 3);
		waiting(philo->info->time_to_sleep, philo);
		print_state(philo, 4);
	}
	return (0);
}
