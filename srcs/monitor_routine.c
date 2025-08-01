/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_routine.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42lyon.fr>      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-01 17:55:18 by thmaitre          #+#    #+#             */
/*   Updated: 2025-08-01 17:55:18 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

	#include <stdio.h>
	#include <unistd.h>

//le monitor thread sert a suivre l'etat des
//thread de philos

//si un philo n'a pas mange depuis plus longtemp
//que le time to die,
//on va afficher le philo qui est mort
//on vas mettre la variable
//philo->run_philo a 0 sur tous les philos,
//les philo vont stopper leur routine (on doit verifier
//que la variable est a 0 tous le temps, et dans toutes les boucles)
//
//autre cas de figure
//les philos on tous mange suffisament
//on check sur tous les philos si la variable
//philo->meals_eaten est arrive au data->nb_must_eat
//a chaque fois qu'un philo a atteint la variable
//on ajoute dans un tableau a son index == 1
//on verifie a chaque tour de boucle si le tableau est rempli de 1
//si oui on stoppe la verification et
//on va mettre la variable run_philo a 0 sur tous les philo
//les philo vont stopper leur routine (on doit verifier
//que la variable est a 0 tous le temps, et dans toutes les boucles)

//creer le thread
//creer sa routine
//		une fonction is_a_philo_dead()
//		une fonction is_all_philos_eaten_enough()

// si la difference entre le temp actuel et le temp du dernier repas est
// superieur a time_to_die, le philo est mort


// dernier repas : 150
// temp actuel   : 200
// time to die   : 100

// 200 - 150 = 50
// 50 < ttd

void	is_all_philos_eaten_enough(t_data *data)
{
	(void)data;
	return ;
}

void	is_a_philo_dead(t_data *data)
{
	long	current_time;
	long	last_meal;
	long	time_to_die;
	int		i;

	i = 0;
	time_to_die = data->time_to_die;
	while (i < data->nb_philo)
	{
		current_time = get_current_time();
		last_meal = data->philos[i].last_meal_time;
		if ((current_time - last_meal) > time_to_die)
		{
			printf_mutex(data, "died", data->philos[i].id);
			stop_simulation(data);
			return ;
		}
		i++;
	}
}

void	*monitor_routine(void *v_data)
{
	t_data	*data;

	data = (t_data *)v_data;
	while (data->run_monitor)
	{
		is_a_philo_dead(data);
		if (data->run_monitor)
			is_all_philos_eaten_enough(data);
	}
	return (NULL);
}
