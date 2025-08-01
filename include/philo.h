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

typedef struct s_philo
{
	int					id;
	pthread_t			thread;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	long				last_meal_time;
	int					meals_eaten;
}	t_philo;

typedef struct s_data
{
	int					nb_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					nb_must_eat;
	int					flag_dead;
	int					flag_all_ate;
	long				start_time;
	t_philo				*philos;
	pthread_mutex_t		*forks;
}	t_data;

//	check_args.c
int		check_args(int ac, char **av);

//	ft_atoi.c
int		ft_atoi(const char *nptr);

//	init_philo.c
t_data	*init_philo(t_data *data, char **av);

//	time.c
long	get_start_time(void);
