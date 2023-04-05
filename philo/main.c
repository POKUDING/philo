/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhyupa <junhyupa@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 18:28:16 by junhyupa          #+#    #+#             */
/*   Updated: 2023/04/05 13:50:53 by junhyupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *av[])
{
	t_info	info;
	int		err;

	if (ac < 5 || ac > 6 || init_info(&info, av, ac))
		err = write(2, "argument error\n", 15);
	if (!err && init_mutex(&info))
		err = write(2, "init_mutexerr\n", 14);
	
	if (err)
		return (1);
	return (0);
}