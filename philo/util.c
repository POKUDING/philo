/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:19:25 by junhyupa          #+#    #+#             */
/*   Updated: 2023/04/10 19:52:26 by junhyupa         ###   ########.fr       */
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
	if (res > 2147483647)
		return (-1);
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
		i++;
	}
	if (i > 10)
		return (0);
	return (1);
}

long	nowtime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, 0);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}
