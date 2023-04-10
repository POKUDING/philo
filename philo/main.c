/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:28:16 by junhyupa          #+#    #+#             */
/*   Updated: 2023/04/10 18:20:56 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	run_thread(t_philo *philo, t_info *info)
{
	int			i;

	i = 0;
	info->start_time = nowtime();
	while (i < info->philo_num)
	{
		philo[i].num = i + 1;
		philo[i].last_eat = info->start_time;
		philo[i].last_status = info->start_time;
		philo[i].info = info;
		philo[i].cnt_eat = 0;
		philo[i].status = 0;
		pthread_mutex_init(&philo[i].use_philo, 0);
		if (pthread_create(&philo[i].thread, 0, philosopher, &philo[i]))
			return (1);
		i++;
	}
	monitoring(info, philo);
	return (0);
}

int	main(int ac, char *av[])
{
	t_info		info;
	t_philo		*philo;

	memset(&info, 0, sizeof(t_info));
	philo = NULL;
	if (ac < 5 || ac > 6 || init_info(&info, &philo, av, ac))
		return (error_control("argument error\n", philo, &info));
	if (init_mutex(&info))
		return (error_control("init_err\n", philo, &info));
	if (run_thread(philo, &info))
		return (error_control("run_thread error\n", philo, &info));
	free_all(philo, &info);
	return (0);
}
