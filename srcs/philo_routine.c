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

int	running_sim(t_data *data)
{
	pthread_mutex_lock(&data->run_sim_mtx);
	if (data->run_sim == 0)
	{
		return (0);
		pthread_mutex_unlock(&data->run_sim_mtx);
	}
	pthread_mutex_unlock(&data->run_sim_mtx);
	return (1);
}

// on wait la fin de la creation de tous les philo
// on decale les pair du tte
// on fait la routine eat sleep think
void	*philo_routine(void *v_philo)
{
	t_philo	*philo;

	philo = (t_philo *)v_philo;
	wait_start(philo->data);
	if (philo->id % 2 == 0)
		ft_usleep(philo->data->time_to_eat);
	while (running_sim(philo->data))
	{
		eat(philo->data);
		sleep(philo->data);
		think(philo->data);
	}
	return ;
}
