/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42lyon.fr>      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-25 16:20:37 by thmaitre          #+#    #+#             */
/*   Updated: 2025-08-25 16:20:37 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	is_a_philo_dead(t_data *data)
{
	int		i;
	long	last_meal_time;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_lock(&data->philos[i].last_meal_time_mtx);
		last_meal_time = data->philos[i].last_meal_time;
		if (get_current_time() - last_meal_time >= data->time_to_die)
		{
			printf_mutex(data, "died", data->philos[i].id);
			pthread_mutex_lock(&data->run_sim_mtx);
			data->run_sim = 0;
			pthread_mutex_unlock(&data->run_sim_mtx);
			pthread_mutex_unlock(&data->philos[i].last_meal_time_mtx);
			return ;
		}
		pthread_mutex_unlock(&data->philos[i].last_meal_time_mtx);
		usleep(100);
		i++;
	}
}

int	is_philos_ate_enough(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_lock(&data->philos[i].meals_eaten_mtx);
		if (data->philos[i].meals_eaten != data->nb_must_eat)
		{
			pthread_mutex_unlock(&data->philos[i].meals_eaten_mtx);
			return (1);
		}
		pthread_mutex_unlock(&data->philos[i].meals_eaten_mtx);
		i++;
	}
	pthread_mutex_lock(&data->run_sim_mtx);
	data->run_sim = 0;
	pthread_mutex_unlock(&data->run_sim_mtx);
	return (0);
}

int	monitor(t_data *data)
{
	set_start_times(data);
	pthread_mutex_unlock(&data->start_sim_mtx);
	while (is_sim_running(data))
	{
		is_a_philo_dead(data);
		// if (is_sim_running(data) && data->nb_must_eat != -1)
		// 	is_philos_ate_enough(data);
	}
	return (0);
}
