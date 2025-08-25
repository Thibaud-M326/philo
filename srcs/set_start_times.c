/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_times.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42lyon.fr>      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-25 16:46:28 by thmaitre          #+#    #+#             */
/*   Updated: 2025-08-25 16:46:28 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	set_start_times(t_data *data)
{
	int		i;
	long	start_time;

	start_time = get_current_time();
	data->start_time = start_time;
	i = 0;
	while (i < data->nb_philo)
	{
		data->philos[i].last_meal_time = start_time;
		i++;
	}
	return (0);
}
