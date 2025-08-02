/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_routine.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42lyon.fr>      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-02 00:50:41 by thmaitre          #+#    #+#             */
/*   Updated: 2025-08-02 00:50:41 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead(t_data *data)
{
	if (data->run_monitor)
		return (1);
	return (0);
}

void	*philo_routine(void *v_philo)
{
	t_philo	*philo;

	philo = (t_philo *)v_philo;
	while (!is_dead(philo->data))
	{
		take_forks(philo);
		if (is_dead(philo->data))
			put_forks(philo);
		eating(philo);
		put_forks(philo);
		if (!is_dead(philo->data))
			sleeping(philo);
		if (!is_dead(philo->data))
			thinking(philo);
	}
	return (NULL);
}
