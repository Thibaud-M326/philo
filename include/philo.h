/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thmaitre <thmaitre@student.42lyon.fr>      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-07-31 00:18:31 by thmaitre          #+#    #+#             */
/*   Updated: 2025-07-31 00:18:31 by thmaitre         ###   ########.fr       */
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
	long				last_meal_time;
	int					meals_eaten;
	int					run_philo;
	t_data				*data;
}	t_philo;

typedef struct s_data
{
	int					nb_philo;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	int					nb_must_eat;
	int					run_monitor;
	long				start_time;
	pthread_t			monitor;
	t_philo				*philos;
	pthread_mutex_t		*forks;
	pthread_mutex_t		print;
}	t_data;

//	check_args.c
int		check_args(int ac, char **av);

//	clean_data.c
void	clean_data(t_data *data);

//	ft_atoi.c
int		ft_atoi(const char *nptr);

//	monitor_routine.c
void	*monitor_routine(void *v_data);

//	monitor_thread.c
int		create_monitor_thread(t_data *data);
int		join_monitor_thread(t_data *data);

//	philo_actions.c
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);
void	thinking(t_philo *philo);
void	put_forks(t_philo *philo);
void	take_forks(t_philo *philo);

//	philo_thread.c
int		create_philo_threads(t_data *data);
int		join_philo_threads(t_data *data);

//	philo_routine.c
int		is_dead(t_data *data);
void	*philo_routine(void *v_data);

//	print_mutex.c
void	printf_mutex_ate_enough(t_data *data);
void	printf_mutex(t_data *data, char *msg, int id_philo);

//	init_philo.c
t_data	*init_philo(t_data *data, char **av);

//	stop_simulation.c
void	stop_simulation(t_data *data);

//	time.c
long	get_current_time(void);
int		ft_usleep(long milliseconds);
