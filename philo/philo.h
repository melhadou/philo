/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:52:21 by melhadou          #+#    #+#             */
/*   Updated: 2023/08/03 18:00:17 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>

/* ************************ Philosophers Struct ********* */

typedef struct t_data
{
	size_t			nb_philo;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			nb_must_eat;
	size_t			game_over;
	size_t			start_time;
	pthread_t		*tid;
	pthread_mutex_t	eat;
	pthread_mutex_t	time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	prints;
	struct t_philos	*philos;
}	t_data;

typedef struct t_philos
{
	size_t	id;
	size_t	nb_eaten;
	size_t	last_time_eat;
	t_data	*data;
}	t_philos;

/* ******************** Philosophers Functions ************* */
size_t	get_time_diff(size_t time);
size_t	get_time(void);
int		ft_atoi(const char *nptr);
int		ft_isdigit(int c);
int		get_args(char *av[]);
int		mutex_init(t_data *data);
int		check_death(t_philos *philo);
int		starter(int ac, char **av);
void	ft_print(t_philos *philo, size_t time, char *str, int state);
void	ft_usleep(size_t time);
void	init_args(int ac, char **av, t_data *data);
void	contole_lock(t_philos *philo, char state);
void	init_philos(int ac, char *av[], t_data *data);
void	start_philos(t_data *philo);
void	*print_id(void *id);
void	check_meals(t_data *data);
void	free_and_destroy(t_data *data);
#endif // !PHILO_H
