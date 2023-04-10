/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:07:16 by junhyupa          #+#    #+#             */
/*   Updated: 2023/04/10 18:29:33 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_control(char *str, t_philo *philo, t_info *info)
{
	if (philo && philo->thread)
		check_live(philo->info, 1);
	while (str && *str)
		write(2, str++, 1);
	free_all(philo, info);
	return (1);
}

void	free_info(t_info *info)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&info->print);
	pthread_mutex_destroy(&info->use_live);
	while (i < info->philo_num)
		pthread_mutex_destroy(&info->forks[i++].mutex);
	free(info->forks);
}

void	free_all(t_philo *philo, t_info *info)
{
	int		i;
	void	*tmp;

	i = 0;
	while (i < info->philo_num && philo && philo[i].thread)
		pthread_join(philo[i++].thread, &tmp);
	free_info(info);
	free(philo);
}
