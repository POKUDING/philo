/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:19:58 by junhyupa          #+#    #+#             */
/*   Updated: 2023/04/11 02:38:23 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state(t_philo *philo, int state)
{
	int	time;

	pthread_mutex_lock(philo->info->print);
	time = nowtime() - philo->info->start_time;
	if (!check_live(philo->info, 0))
	{
		pthread_mutex_unlock(philo->info->print);
		return ;
	}
	else if (state == 1)
		printf("%d %d has taken a fork\n", time, philo->num);
	else if (state == 2)
		printf("%d %d is eating\n", time, philo->num);
	else if (state == 3)
		printf("%d %d is sleeping\n", time, philo->num);
	else if (state == 4)
		printf("%d %d is thinking\n", time, philo->num);
	else if (state == 5)
	{
		printf("%d %d died\n", time, philo->num);
		check_live(philo->info, 1);
	}
	if (state != 5)
	{
		philo->status = state;
		philo->last_status = nowtime();
	}
	pthread_mutex_unlock(philo->info->print);
}

int	check_live(t_info *info, int mode)
{
	int	rtn;

	rtn = 0;
	if (mode == 0)
	{
		pthread_mutex_lock(info->use_live);
		rtn = info->live;
		pthread_mutex_unlock(info->use_live);
	}
	else if (mode == 1)
	{
		pthread_mutex_lock(info->use_live);
		info->live = 0;
		rtn = info->live;
		pthread_mutex_unlock(info->use_live);
	}
	return (rtn);
}

int	check_all_philo_eat(t_philo *philo)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (flag && i < philo->info->philo_num)
	{
		if (!philo[i].im_full)
			flag = 0;
		i++;
	}
	return (flag);
}

void	monitoring(t_info *info, t_philo *philo)
{
	int		i;

	while (info->live)
	{
		i = 0;
		while (i < info->philo_num)
		{
			pthread_mutex_lock(&philo[i].use_philo);
			if (info->must_eat > 0 && philo[i].cnt_eat >= info->must_eat)
				philo[i].im_full = 1;
			if (nowtime() - philo[i].last_eat >= info->time_to_die)
			{
				print_state(&philo[i], 5);
			}
			else if (info->must_eat > 0 && check_all_philo_eat(philo))
				check_live(info, 1);
			pthread_mutex_unlock(&philo[i].use_philo);
			i++;
		}
	}
}
