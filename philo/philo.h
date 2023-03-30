/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:28:47 by junhyupa          #+#    #+#             */
/*   Updated: 2023/03/31 01:49:43 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h>

typedef struct	s_info
{
	int	phlio_num;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat;
	pthread_mutex_t	print;
	pthread_mutex_t	*forks;
}	t_info;

typedef struct	s_philo
{
}	t_philo;

int		init_info(t_info *info, char **av, int ac);
int	init_mutex(t_info *info);

int		ft_atoi(const char *nptr);
int		ft_isdigit(char	*s);
void	*ft_calloc(size_t num, size_t size);
void	error_control(char *msg, char *msg2, int n);
void	print_err(char *msg, char *msg2);

#endif