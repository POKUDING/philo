/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:51:35 by junhyupa          #+#    #+#             */
/*   Updated: 2023/04/08 13:14:18 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_down_fork(t_philo *philo)
{
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;

	right_fork = &philo->info->forks[philo->num - 1].mutex;
	left_fork = &philo->info->forks[philo->num % philo->info->philo_num].mutex;
	pthread_mutex_unlock(left_fork);
	pthread_mutex_unlock(right_fork);
	philo->last_eat = nowtime();
	philo->cnt_eat++;
	philo->info->forks[philo->num - 1].status--;
	philo->info->forks[philo->num % philo->info->philo_num].status--;
}

void	pick_fork(t_philo *philo)
{
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;

	if (!philo->info->live)
		return ;
	right_fork = &philo->info->forks[philo->num - 1].mutex;
	left_fork = &philo->info->forks[philo->num % philo->info->philo_num].mutex;
	pthread_mutex_lock(right_fork);
	pthread_mutex_lock(left_fork);
	print_state(philo, 1);
	philo->info->forks[philo->num - 1].status++;
	philo->info->forks[philo->num % philo->info->philo_num].status++;
}

void	waiting(int time, t_philo *philo)
{
	int	i;

	if (!philo->info->live)
		return ;
	i = 0;
	while (i < time)
	{
		usleep(250);
		if (!philo->info->live)
			return ;
		usleep(250);
		if (!philo->info->live)
			return ;
		usleep(250);
		if (!philo->info->live)
			return ;
		usleep(250);
		if (!philo->info->live)
			return ;
		i++;
	}
}

void	*philosopher(void *philo_p)
{
	t_philo	*philo;

	philo = (t_philo *)philo_p;
	if (philo->num % 2)
		usleep(philo->info->time_to_eat * 800);
	while (philo->info->live)
	{
		pick_fork(philo);
		print_state(philo, 2);
		waiting(philo->info->time_to_eat, philo);
		// usleep(philo->info->time_to_eat * 1000);
		put_down_fork(philo);
		print_state(philo, 3);
		// if (!philo->info->live)
		// 	break ;
		waiting(philo->info->time_to_sleep, philo);
		// usleep(philo->info->time_to_sleep * 1000);
		print_state(philo, 4);
	}
	return (0);
}
