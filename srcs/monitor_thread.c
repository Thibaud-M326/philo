/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_thread.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42lyon.fr>      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-01 17:18:13 by thmaitre          #+#    #+#             */
/*   Updated: 2025-08-01 17:18:13 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

int	create_monitor_thread(t_data *data)
{
	if (pthread_create(&data->monitor, NULL, &monitor_routine, data) != 0)
		return (0);
	return (1);
}

int	join_monitor_thread(t_data *data)
{
	if (pthread_join(data->monitor, NULL) != 0)
		return (0);
	return (1);
}
