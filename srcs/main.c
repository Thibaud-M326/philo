/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42lyon.fr>      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-25 11:55:56 by thmaitre          #+#    #+#             */
/*   Updated: 2025-08-25 11:55:56 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (!check_args(argc, argv))
	{
		printf("DEBUG [%s:%d in %s()]\n", __FILE__, __LINE__, __func__);
		return (0);
	}
	if (init_philo(&data, argv) == NULL)
	{
		printf("DEBUG [%s:%d in %s()]\n", __FILE__, __LINE__, __func__);
		return (0);
	}
	if (create_philo_threads(&data) == 1)
	{
		clean_data(&data);
		printf("DEBUG [%s:%d in %s()]\n", __FILE__, __LINE__, __func__);
		return (0);
	}
	if (monitor(&data) == 1)
	{
		clean_data(&data);
		join_philo_threads(&data);
		printf("DEBUG [%s:%d in %s()]\n", __FILE__, __LINE__, __func__);
		return (0);
	}
	return (0);
}
