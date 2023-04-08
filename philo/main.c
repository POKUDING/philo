/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:28:16 by junhyupa          #+#    #+#             */
/*   Updated: 2023/04/08 12:21:32 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_all_philo_eat(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->info->philo_num)
	{
		if (philo[i].cnt_eat < philo->info->must_eat)
			return (0);
		i++;
	}
	return (1);
}

void	monitoring(t_info *info, t_philo *philo)
{
	int		i;

	while (info->live)
	{
		i = 0;
		while (i < info->philo_num)
		{
			if (nowtime() - philo[i].last_eat >= info->time_to_die)
			{
				print_state(&philo[i], 5);
				info->live = 0;
			}
			else if (info->must_eat > 0 && check_all_philo_eat(philo))
				info->live = 0;
			i++;
		}
	}
}

int	run_thread(t_philo *philo, t_info *info)
{
	int			i;

	i = 0;
	info->start_time = nowtime();
	while (i < info->philo_num)
	{
		philo[i].num = i + 1;
		philo[i].last_eat = info->start_time;
		philo[i].info = info;
		philo[i].cnt_eat = 0;
		pthread_create(&philo[i].thread, 0, philosopher, &philo[i]);
		i++;
	}
	monitoring(info, philo);
	return (0);
}

int	main(int ac, char *av[])
{
	t_info		info;
	t_philo		*philo;
	int			err;

	if (ac < 5 || ac > 6 || init_info(&info, &philo, av, ac))
		err = write(2, "argument error\n", 15);
	if (!err && init_mutex(&info))
		err = write(2, "init_err\n", 8);
	run_thread(philo, &info);
	free_all(philo);
	if (err)
		return (1);
	return (0);
}
