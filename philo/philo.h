/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:28:47 by junhyupa          #+#    #+#             */
/*   Updated: 2023/04/10 19:38:55 by junhyupa         ###   ########.fr       */
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
	pthread_mutex_t	*use_live;
	pthread_mutex_t	*print;
}	t_info;

typedef struct s_philo
{
	int				num;
	int				cnt_eat;
	int				status;
	long			last_eat;
	long			last_status;
	pthread_mutex_t	use_philo;
	pthread_t		thread;
	t_info			*info;
}	t_philo;

typedef struct s_fork
{
	pthread_mutex_t	mutex;
	int				status;
}	t_fork;

int		error_control(char *str, t_philo *philo, t_info *info);
void	free_info(t_info *info);
void	free_all(t_philo *philo, t_info *info);

int		init_mutex(t_info *info);
int		init_info(t_info *info, t_philo **philo, char **av, int ac);

int		check_all_forks_status(t_info *info);
void	print_state(t_philo *philo, int state);
int		check_live(t_info *info, int mode);
int		check_all_philo_eat(t_philo *philo);
void	monitoring(t_info *info, t_philo *philo);

void	put_down_fork(t_philo *philo);
void	pick_fork(t_philo *philo);
void	waiting(int time, t_philo *philo);
void	*philosopher(void *philo_p);

void	*ft_calloc(size_t num, size_t size);
int		ft_atoi(const char *nptr);
int		ft_isdigit(char	*s);
long	nowtime(void);

#endif