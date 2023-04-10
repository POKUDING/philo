/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:28:16 by junhyupa          #+#    #+#             */
/*   Updated: 2023/04/09 17:16:10 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// int	check_all_forks_status(t_info *info)
// {
// 	int	i;

// 	i = 0;
// 	///must del function
// 	while(i < info->philo_num)
// 	{
// 		if (info->forks[i].status != 0 && info->forks[i].status != 1)
// 		{
// 			write(2, "mutext error!!!\n", 15);
// 		}
// 		i++;
// 	}
// 	return (0);
// }
int	check_live(t_info *info, int mode)
{
	int	rtn;

	pthread_mutex_lock(&info->use_live);
	if (mode == 0)
		rtn = info->live;
	else if (mode == 1)
	{
		info->live = 0;
		rtn = info->live;
	}
	pthread_mutex_unlock(&info->use_live);
	return (rtn);
}

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
				print_state(&philo[i], 5);
			else if (info->must_eat > 0 && check_all_philo_eat(philo))
				check_live(info, 1);
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
