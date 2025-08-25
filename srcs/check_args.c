/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42lyon.fr>      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-30 23:52:35 by thmaitre          #+#    #+#             */
/*   Updated: 2025-07-30 23:52:35 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

void	print_usage(void)
{
	printf("Usage: ");
	printf("./philo number_of_philosophers time_to_die time_to_eat ");
	printf("time_to_sleep [number_of_times_each_philosopher_must_eat]\n");
	return ;
}

int	is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	is_pos_num(char *str_av)
{
	int	i;

	i = 0;
	while (str_av[i])
	{
		if (!is_digit(str_av[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_args(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac < 5 || ac > 6)
	{
		print_usage();
		return (0);
	}
	while (i < ac)
	{
		if (!is_pos_num(av[i]))
		{
			print_usage();
			return (0);
		}
		i++;
	}
	return (1);
}
