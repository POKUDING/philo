/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:33:33 by junhyupa          #+#    #+#             */
/*   Updated: 2023/03/30 18:48:50 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_err(char *msg, char *msg2)
{
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(msg, 2);
	if (msg2 && *msg2)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(msg2, 2);
	}
	ft_putstr_fd("\n", 2);
}

void	error_control(char *msg, char *msg2, int n)
{
	print_err(msg, msg2);
	exit (n);
}

void	*ft_calloc(size_t num, size_t size)
{
	unsigned char	*tmp;
	size_t	i;

	i = 0;
	tmp = (void *)malloc(num * size);
	if (tmp == NULL)
	{
		ft_putstr_fd("malloc failed!", 2);
		return (NULL);
	}
	while (i < num * size)
		tmp[i++] = 0;
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
