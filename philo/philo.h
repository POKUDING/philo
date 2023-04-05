/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:28:47 by junhyupa          #+#    #+#             */
/*   Updated: 2023/04/05 14:26:44 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>

typedef struct s_info
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
}	t_info;

typedef struct s_philo
{
	int		num;
	t_info	*info;
}	t_philo;

int		init_info(t_info *info, char **av, int ac);
int		init_mutex(t_info *info);

int		ft_atoi(const char *nptr);
int		ft_isdigit(char	*s);
void	*ft_calloc(size_t num, size_t size);

void	philosopher(void *philo);
void	pick_fork(t_philo *philo);
void	put_down_fork(t_philo *philo);

#endif