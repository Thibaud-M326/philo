/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42lyon.fr>      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-25 17:54:25 by thmaitre          #+#    #+#             */
/*   Updated: 2025-08-25 17:54:25 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		printf_mutex(philo->data, "has taken a fork", philo->id);
		if (!is_sim_running(philo->data))
		{
			pthread_mutex_unlock(philo->right_fork);
			return (1);
		}
		pthread_mutex_lock(philo->left_fork);
		printf_mutex(philo->data, "has taken a fork", philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		printf_mutex(philo->data, "has taken a fork", philo->id);
		if (!is_sim_running(philo->data))
		{
			pthread_mutex_unlock(philo->left_fork);
			return (1);
		}
		pthread_mutex_lock(philo->right_fork);
		printf_mutex(philo->data, "has taken a fork", philo->id);
	}
	return (0);
}

void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

int	eat(t_data *data, t_philo *philo)
{
	if (!is_sim_running(data))
		return (0);
	if (take_forks(philo) == 1)
		return (1);
	printf_mutex(philo->data, "is eating", philo->id);
	ft_usleep_sim_running(data, data->time_to_eat);
	pthread_mutex_lock(&philo->last_meal_time_mtx);
	philo->last_meal_time = get_current_time();
	pthread_mutex_unlock(&philo->last_meal_time_mtx);
	pthread_mutex_lock(&philo->meals_eaten_mtx);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meals_eaten_mtx);
	put_forks(philo);
	return (0);
}

int	sleeping(t_data *data, t_philo *philo)
{
	if (!is_sim_running(data))
		return (0);
	printf_mutex(philo->data, "is sleeping", philo->id);
	ft_usleep_sim_running(data, philo->data->time_to_sleep);
	return (0);
}

int	think(t_data *data, t_philo *philo)
{
	long	tte;
	long	tts;

	tte = data->time_to_eat;
	tts = data->time_to_sleep;
	if (!is_sim_running(data))
		return (0);
	if (data->nb_philo % 2 != 0)
		ft_usleep_sim_running(data, 2 * tte - tts);
	if (is_sim_running(data))
		printf_mutex(philo->data, "is thinking", philo->id);
	return (0);
}
