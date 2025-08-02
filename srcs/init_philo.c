/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42lyon.fr>      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-01 00:03:20 by thmaitre          #+#    #+#             */
/*   Updated: 2025-08-01 00:03:20 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include "philo.h"

t_data	*init_data_av(t_data *data, char **av)
{
	memset(data, 0, sizeof(t_data));
	data->nb_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		data->nb_must_eat = ft_atoi(av[5]);
	else
		data->nb_must_eat = -1;
	data->start_time = get_current_time();
	if (data->start_time == -1)
		return (NULL);
	data->run_monitor = 1;
	return (data);
}

t_data	*init_data_forks(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->forks = malloc(sizeof (pthread_mutex_t) * data->nb_philo);
	if (!data->forks)
		return (NULL);
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			while (j < i)
			{
				pthread_mutex_destroy(&data->forks[i]);
				j++;
			}
			free(data->forks);
			data->forks = NULL;
			return (NULL);
		}
		i++;
	}
	return (data);
}

t_data	*init_data_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->print, NULL) != 0)
	{
		clean_data(data);
		return (NULL);
	}
	return (data);
}

t_data	*init_data_philos(t_data *data)
{
	int	i;

	i = 0;
	data->philos = malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philos)
		return (NULL);
	memset(data->philos, 0, sizeof(t_philo));
	while (i < data->nb_philo)
	{
		data->philos[i].id = i;
		data->philos[i].left_fork = &data->forks[i];
		data->philos[i].right_fork = &data->forks[(i + 1) % data->nb_philo];
		data->philos[i].last_meal_time = data->start_time;
		data->philos[i].meals_eaten = 0;
		data->philos[i].run_philo = 1;
		data->philos[i].data = data;
		i++;
	}
	return (data);
}

t_data	*init_philo(t_data *data, char **av)
{
	if (init_data_av(data, av) == NULL)
		return (NULL);
	if (init_data_forks(data) == NULL)
		return (NULL);
	if (init_data_mutex(data) == NULL)
		return (NULL);
	if (init_data_philos(data) == NULL)
		return (NULL);
	return (data);
}
