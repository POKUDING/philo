/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 18:19:25 by junhyupa          #+#    #+#             */
/*   Updated: 2023/04/05 18:28:49 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>

long	nowtime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, 0);
	printf("%ld, %ld\n", tv.tv_sec, tv.tv_usec);
	return (tv.tv_sec);
}

int	main()
{
	nowtime();
}