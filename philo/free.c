/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:07:16 by junhyupa          #+#    #+#             */
/*   Updated: 2023/04/08 02:58:06 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_info(t_info *info)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&info->print);
	while (i < info->philo_num)
		pthread_mutex_destroy(&info->forks[i++]);
	free(info->forks);
}

void	free_all(t_philo *philo)
{
	int		i;
	void	*tmp;

	i = 0;
	while (i < philo->info->philo_num)
		pthread_join(philo[i++].thread, &tmp);
	free_info(philo->info);
	free(philo);
}
