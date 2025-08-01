/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42lyon.fr>      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-30 23:49:31 by thmaitre          #+#    #+#             */
/*   Updated: 2025-07-30 23:49:31 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "philo.h"

// j'ai initialiser les data
//je doit maintenant creer mes thread
//avec le tableau de philo contenu dans data
//je vais creer le thread monitor en premier
//je vais creer les threads philo
//les thread vont avoir leur routine
//ensuite j'attend les thread pour les fermer
//je clean_data : free et detruit les mutexe
//on sort du programme
int	main(int argc, char **argv)
{
	t_data	data;

	if (!check_args(argc, argv))
		return (0);
	if (init_philo(&data, argv) == NULL)
		return (0);
	create_monitor_thread(&data);
	join_monitor_thread(&data);
	clean_data(&data);
	return (0);
}
