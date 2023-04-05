/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:32:38 by junhyupa          #+#    #+#             */
/*   Updated: 2023/04/05 14:14:46 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_info *info)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&info->print, 0))
		return (1);
	info->forks = (pthread_mutex_t *)ft_calloc(sizeof(pthread_mutex_t), \
														info->philo_num);
	if (!info->forks)
		return (1);
	while (i < info->philo_num)
	{
		if (pthread_mutex_init(&info->forks[i++], 0))
			return (1);
	}
	return (0);
}

int	init_info(t_info *info, char **av, int ac)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (ft_isdigit(av[i]))
			return (1);
	}
	info->philo_num = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	if (info->philo_num <= 0 || info->time_to_die < 0 || \
		info->time_to_eat < 0 || info->time_to_sleep < 0)
		return (1);
	if (ac == 6)
		info->must_eat = ft_atoi(av[5]);
	else
		info->must_eat = -1;
	if (ac == 6 && info->must_eat <= 0)
		return (1);
	return (0);
}
