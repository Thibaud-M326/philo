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

//le monitor doit checker sur tous les philo dans une boucle si
//l'un d'eux est mort
//on doit bloquer le moniteur tant que philo->last_time_eat_mtx
//car cela veut dire que le philo a deja pris la fourchette et est en train
//de manger
int	monitor(t_data *data)
{
	set_start_times(data);
	pthread_mutex_unlock(&data->start_sim_mtx);

	return (0);
}
