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

void	eat(t_philo *philo)
{
	(void)philo;
	return ;
}

void	sleep(t_philo *philo)
{
	(void)philo;
	return ;
}

void	think(void)
{
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
			return (1);
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
			return (1);
		}
		pthread_mutex_lock(philo->right_fork);
		printf_mutex(philo->data, "has taken a fork", philo->id);
	}
}
