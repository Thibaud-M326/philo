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

void	take_forks(t_philo *philo)
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
		pthread_mutex_lock(&philo->last_meal_time_mtx);
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
}

void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

//on doit faire deux fonctions
//une pour les philo pair et une pour les impair
//les pair prennent la fourchette a leur droite
//les impair prennent la fourchette a leur gauche
//quand un philo prend 2 fork on doit bloquer un mutex pour le temps de manger
//dans le monitor
//prendre fork
//bloquer last_time_eat le temp de manger
//prendre le temps de manger
//mettre a jour le last_time_eat
//debloquer le last_time_eat
//poser les fork
int	eat(t_data *data, t_philo *philo)
{
	if (!is_sim_running(data))
		return (0);
	take_forks(philo);
	pthread_mutex_lock(&philo->last_meal_time_mtx);
	ft_usleep(data->time_to_eat);
	printf_mutex(philo->data, "is eating", philo->id);
	philo->last_meal_time = get_current_time();
	pthread_mutex_unlock(&philo->last_meal_time_mtx);
	pthread_mutex_lock(&philo->meals_eaten_mtx);
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->meals_eaten_mtx);
	put_forks(philo);
	return (0);
}

int	sleep(t_data *data, t_philo *philo)
{
	if (!is_sim_running(data))
		return (0);
	printf_mutex(philo->data, "is sleeping", philo->id);
	ft_usleep(philo->data->time_to_sleep);
	return (0);
}

int	think(t_data *data, t_philo *philo)
{
	if (!is_sim_running(data))
		return (0);
	printf_mutex(philo->data, "is thinking", philo->id);
	return (0);
}
