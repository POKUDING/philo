/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:19:25 by junhyupa          #+#    #+#             */
/*   Updated: 2023/04/08 17:40:21 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_calloc(size_t num, size_t size)
{
	unsigned char	*tmp;

	tmp = (void *)malloc(num * size);
	if (tmp == NULL)
	{
		write(2, "malloc failed!\n", 15);
		return (NULL);
	}
	memset(tmp, 0, num * size);
	return ((void *)tmp);
}

int	ft_atoi(const char *nptr)
{
	int			i;
	long long	res;
	int			mns;

	i = 0;
	res = 0;
	mns = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			mns *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = (res * 10) + (nptr[i] - '0');
		i++;
	}
	return (mns * (int)res);
}

int	ft_isdigit(char	*s)
{
	size_t	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		if (i == 8 && (s[i] > '7' || s[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

void	print_state(t_philo *philo, int state)
{
	int	time;

	time = nowtime() - philo->info->start_time;
	pthread_mutex_lock(&philo->info->print);
	if (!check_live(philo->info, 0))
	{
		pthread_mutex_unlock(&philo->info->print);
		return ;
	}
	if (state == 1)
		printf("%d %d has taken a fork\n", time, philo->num);
	else if (state == 2)
		printf("%d %d is eating\n", time, philo->num);
	else if (state == 3)
		printf("%d %d is sleeping\n", time, philo->num);
	else if (state == 4)
		printf("%d %d is thinking\n", time, philo->num);
	else if (state == 5)
	{
		printf("%d %d died\n", time, philo->num);
		check_live(philo->info, 1);
	}
	pthread_mutex_unlock(&philo->info->print);
}

long	nowtime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, 0);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
