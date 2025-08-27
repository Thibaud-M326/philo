/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42lyon.fr>      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-27 14:21:52 by thmaitre          #+#    #+#             */
/*   Updated: 2025-08-27 14:21:52 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_forks_even(t_philo *philo)
{
	pthread_mutex_lock(&philo->right_fork->fork);
	if (philo->right_fork->available == 1)
	{
		philo->right_fork->available = 0;
		printf_mutex(philo->data, "has taken a fork", philo->id);
	}
	if (!is_sim_running(philo->data))
	{
		philo->right_fork->available = 1;
		pthread_mutex_unlock(&philo->right_fork->fork);
		return (1);
	}
	pthread_mutex_lock(&philo->left_fork->fork);
	if (philo->left_fork->available == 1)
	{
		philo->left_fork->available = 0;
		printf_mutex(philo->data, "has taken a fork", philo->id);
	}
	return (0);
}

int	take_forks_odd(t_philo *philo)
{
	pthread_mutex_lock(&philo->left_fork->fork);
	if (philo->left_fork->available == 1)
	{
		philo->left_fork->available = 0;
		printf_mutex(philo->data, "has taken a fork", philo->id);
	}
	if (!is_sim_running(philo->data))
	{
		philo->left_fork->available = 1;
		pthread_mutex_unlock(&philo->left_fork->fork);
		return (1);
	}
	pthread_mutex_lock(&philo->right_fork->fork);
	if (philo->right_fork->available == 1)
	{
		philo->right_fork->available = 0;
		printf_mutex(philo->data, "has taken a fork", philo->id);
	}
	return (0);
}

int	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		if (take_forks_even(philo) == 1)
			return (1);
	}
	else
	{
		if (take_forks_odd(philo) == 1)
			return (1);
	}
	return (0);
}
