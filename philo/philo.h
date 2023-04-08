/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:28:47 by junhyupa          #+#    #+#             */
/*   Updated: 2023/04/08 17:17:57 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_info
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	long			start_time;
	int				live;
	struct s_fork	*forks;
	pthread_mutex_t	use_live;
	pthread_mutex_t	print;
}	t_info;

typedef struct s_philo
{
	int				num;
	int				cnt_eat;
	long			last_eat;
	pthread_t		thread;
	t_info			*info;
}	t_philo;

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	int				status;
}	t_fork;

int		init_info(t_info *info, t_philo **philo, char **av, int ac);
int		init_mutex(t_info *info);

int		check_live(t_info *info, int mode);
void	*philosopher(void *philo);
void	pick_fork(t_philo *philo);
void	put_down_fork(t_philo *philo);

int		ft_atoi(const char *nptr);
int		ft_isdigit(char	*s);
void	*ft_calloc(size_t num, size_t size);
void	print_state(t_philo *philo, int state);
long	nowtime(void);

int		error_control(char *str, t_philo *philo);
void	free_info(t_info *info);
void	free_all(t_philo *philo);


#endif