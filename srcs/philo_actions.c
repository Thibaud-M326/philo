/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42lyon.fr>      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-02 01:49:43 by thmaitre          #+#    #+#             */
/*   Updated: 2025-08-02 01:49:43 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eating(t_philo *philo)
{
	printf_mutex(philo->data, "is eating", philo->id);
	ft_usleep(philo->data->time_to_eat);
	return ;
}

void	sleeping(t_philo *philo)
{
	printf_mutex(philo->data, "is sleeping", philo->id);
	ft_usleep(philo->data->time_to_sleep);
	return ;
}

void	thinking(t_philo *philo)
{
	printf_mutex(philo->data, "is thinking", philo->id);
	return ;
}

void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	take_forks(t_philo *philo)
{
	if (philo->id == philo->data->nb_philo - 1)
	{
		pthread_mutex_lock(philo->right_fork);
		printf_mutex(philo->data, "has taken a fork", philo->id);
		if (is_dead(philo->data))
		{
			pthread_mutex_unlock(philo->right_fork);
			return ;
		}
		pthread_mutex_lock(philo->left_fork);
		printf_mutex(philo->data, "has taken a fork", philo->id);
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		printf_mutex(philo->data, "has taken a fork", philo->id);
		if (is_dead(philo->data))
		{
			pthread_mutex_unlock(philo->left_fork);
			return ;
		}
		pthread_mutex_lock(philo->right_fork);
		printf_mutex(philo->data, "has taken a fork", philo->id);
	}
}
