/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42lyon.fr>      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-01 21:05:44 by thmaitre          #+#    #+#             */
/*   Updated: 2025-08-01 21:05:44 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	stop_simulation(t_data *data)
{
	int	i;

	i = 0;
	data->run_monitor = 0;
	while (i < data->nb_philo)
	{
		data->philos[i].run_philo = 0;
		i++;
	}
	return ;
}
