/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_mutex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42lyon.fr>      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-01 19:00:57 by thmaitre          #+#    #+#             */
/*   Updated: 2025-08-01 19:00:57 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

void	printf_mutex(t_data *data, char *str, int id_philo)
{
	long	current_time;

	current_time = get_current_time();
	pthread_mutex_lock(&data->print);
	printf("%ld %d %s\n", current_time, id_philo, str);
	pthread_mutex_unlock(&data->print);
	return ;
}
