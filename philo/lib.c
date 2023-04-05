/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:33:33 by junhyupa          #+#    #+#             */
/*   Updated: 2023/04/05 13:50:06 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_calloc(size_t num, size_t size)
{
	unsigned char	*tmp;
	size_t	i;

	i = 0;
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
	while (s && *s)
	{
		if (*s > 47 && *s < 58)
			return (1);
		s++;
	}
	return (0);
}
