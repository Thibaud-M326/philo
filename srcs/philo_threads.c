/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42lyon.fr>      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-25 15:52:00 by thmaitre          #+#    #+#             */
/*   Updated: 2025-08-25 15:52:00 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philo_threads(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	pthread_mutex_lock(&data->start_sim_mtx);
	while (i < data->nb_philo)
	{
		if (pthread_create(
				&data->philos[i].philo, NULL,
				&philo_routine, &data->philos[i]) != 0)
		{
			while (j < i)
			{
				pthread_join(data->philos[j].philo, NULL);
				j++;
			}
			return (1);
		}
		i++;
	}
	return (0);
}

int	join_philo_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_join(data->philos[i].philo, NULL);
		i++;
	}
	return (0);
}
