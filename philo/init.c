/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:32:38 by junhyupa          #+#    #+#             */
/*   Updated: 2023/04/10 19:46:04 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_info *info)
{
	int	i;

	i = 0;
	info->forks = (t_fork *)ft_calloc(sizeof(t_fork), info->philo_num);
	info->print = (pthread_mutex_t *)ft_calloc(sizeof(pthread_mutex_t), 1);
	info->use_live = (pthread_mutex_t *)ft_calloc(sizeof(pthread_mutex_t), 1);
	if (!info->forks || !info->print || !info->use_live)
		return (1);
	if (pthread_mutex_init(info->print, 0) || \
		pthread_mutex_init(info->use_live, 0))
		return (1);
	while (i < info->philo_num)
	{
		if (pthread_mutex_init(&info->forks[i++].mutex, 0))
			return (1);
	}
	return (0);
}

int	init_info(t_info *info, t_philo **philo, char **av, int ac)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (!ft_isdigit(av[i]))
			return (1);
	}
	info->philo_num = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	info->live = 1;
	info->must_eat = -1;
	if (info->philo_num <= 0 || info->time_to_die <= 0 || \
		info->time_to_eat <= 0 || info->time_to_sleep <= 0)
		return (1);
	if (ac == 6)
		info->must_eat = ft_atoi(av[5]);
	if (ac == 6 && info->must_eat <= 0)
		return (1);
	*philo = ft_calloc(info->philo_num, sizeof(t_philo));
	if (!philo)
		return (0);
	return (0);
}
