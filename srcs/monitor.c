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
	if (pthread_mutex_unlock(&data->start_sim_mtx) != 0)
		return (1);

	return (0);
}
