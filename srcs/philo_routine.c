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

// on wait la fin de la creation de tous les philo
// on decale les pair du tte
// on fait la routine eat sleep think
void	*philo_routine(void *v_philo)
{
	t_philo	*philo;

	philo = (t_philo *)v_philo;
	wait_start(philo->data);
	return (NULL);
}
