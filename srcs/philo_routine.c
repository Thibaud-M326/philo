/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42lyon.fr>      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-25 16:10:54 by thmaitre          #+#    #+#             */
/*   Updated: 2025-08-25 16:10:54 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philo_routine(void *v_philo)
{
	t_philo	*philo;

	philo = (t_philo *)v_philo;
	wait_start(philo->data);
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->time_to_eat);
	while (is_sim_running(philo->data))
	{
		eat(philo->data, philo);
		if (!is_sim_running(philo->data))
			return (NULL);
		sleeping(philo->data, philo);
		if (!is_sim_running(philo->data))
			return (NULL);
		think(philo->data, philo);
	}
	return (NULL);
}
