/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42lyon.fr>      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-25 11:51:44 by thmaitre          #+#    #+#             */
/*   Updated: 2025-08-25 11:51:44 by thmaitre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>

	#include <stdio.h>
	#include <unistd.h>

typedef struct s_data	t_data;

typedef struct s_philo
{
	int					id;
	pthread_t			philo;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		last_meal_time_mtx;
	long				last_meal_time;
	pthread_mutex_t		meals_eaten_mtx;
	int					meals_eaten;
	t_data				*data;
}	t_philo;

typedef struct s_data
{
	long				start_time;
	int					nb_philo;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	int					nb_must_eat;
	pthread_mutex_t		run_sim_mtx;
	int					run_sim;
	pthread_mutex_t		print;
	pthread_mutex_t		start_sim_mtx;
	t_philo				*philos;
	pthread_mutex_t		*forks;
}	t_data;

//	srcs/check_args.c
int		check_args(int ac, char **av);

//	srcs/clean_data.c
void	clean_data(t_data *data);

//	srcs/init_philo.c
t_data	*init_philo(t_data *data, char **av);

//	srcs/philo_threads.c
int		create_philo_threads(t_data *data);

//	srcs/ft_atoi.c
int		ft_atoi(const char *nptr);
