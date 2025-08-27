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

//faire une structure pour les fork et leur bool

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

//	srcs/ft_atoi.c
int		ft_atoi(const char *nptr);

//	srcs/init_philo.c
t_data	*init_philo(t_data *data, char **av);

//	srcs/is_sim_running.c
int		is_sim_running(t_data *data);

//	srcs/monitor.c
int		monitor(t_data *data);

//	srcs/philo_actions.c
int		eat(t_data *data, t_philo *philo);
int		sleeping(t_data *data, t_philo *philo);
int		think(t_data *data, t_philo *philo);

//	srcs/philo_routine.c
void	*philo_routine(void *v_philo);

//	srcs/philo_threads.c
int		create_philo_threads(t_data *data);
int		join_philo_threads(t_data *data);

//	srcs/printf_mutex.c
void	printf_mutex_ate_enough(t_data *data);
void	printf_mutex(t_data *data, char *msg, int id_philo);

//	srcs/set_start_times.c
int		set_start_times(t_data *data);

//	srcs/time.c
int		ft_usleep_sim_running(t_data *data, int milliseconds);
long	get_current_time(void);
int		ft_usleep(long milliseconds);

//	srcs/wait_start.c
void	wait_start(t_data *data);
