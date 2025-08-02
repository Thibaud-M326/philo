/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42lyon.fr>      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-01 17:55:18 by thmaitre          #+#    #+#             */
/*   Updated: 2025-08-01 17:55:18 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "philo.h"

int	philos_ate_enough(t_data *data, int *philos_meals_eaten)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (philos_meals_eaten[i] == 0)
			return (0);
		i++;
	}
	return (1);
}

int	is_all_philos_eaten_enough(t_data *data)
{
	int	*philos_meals_eaten;
	int	i;

	i = 0;
	philos_meals_eaten = malloc(sizeof (int) * data->nb_philo);
	if (!philos_meals_eaten)
		return (-1);
	memset(philos_meals_eaten, 0, sizeof (int) * data->nb_philo);
	while (i < data->nb_philo)
	{
		if (data->philos[i].meals_eaten == data->nb_must_eat)
			philos_meals_eaten[i] = 1;
		i++;
	}
	if (philos_ate_enough(data, philos_meals_eaten))
	{
		printf_mutex_ate_enough(data);
		stop_simulation(data);
	}
	free(philos_meals_eaten);
	return (1);
}

void	is_a_philo_dead(t_data *data)
{
	long	current_time;
	long	last_meal;
	long	time_to_die;
	int		i;

	i = 0;
	time_to_die = data->time_to_die;
	while (i < data->nb_philo)
	{
		current_time = get_current_time();
		last_meal = data->philos[i].last_meal_time;
		if ((current_time - last_meal) > time_to_die)
		{
			printf_mutex(data, "died", data->philos[i].id);
			stop_simulation(data);
			return ;
		}
		i++;
	}
}

void	*monitor_routine(void *v_data)
{
	t_data	*data;

	data = (t_data *)v_data;
	while (data->run_monitor)
	{
		is_a_philo_dead(data);
		if (data->run_monitor && data->nb_must_eat != -1)
		{
			if (is_all_philos_eaten_enough(data) == -1)
				stop_simulation(data);
		}
	}
	return (NULL);
}
