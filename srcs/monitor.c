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

int	monitor(t_data *data)
{
	set_start_times(data);
	pthread_mutex_unlock(&data->start_sim_mtx);
	return (0);
}
