/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:52:21 by melhadou          #+#    #+#             */
/*   Updated: 2023/08/02 19:00:05 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>

/* ************************ Philosophers Struct ******************************* */
typedef struct t_data
{
	size_t nb_philo;
	size_t time_to_die;
	size_t time_to_eat;
	size_t time_to_sleep;
	size_t nb_must_eat;
	size_t game_over;
	pthread_t *tid;
	size_t start_time;
	struct t_philos *philos;
	pthread_mutex_t eat;
	pthread_mutex_t time;
	pthread_mutex_t *forks;
	pthread_mutex_t prints;
} t_data;

typedef struct t_philos
{
	size_t id;
	size_t nb_eaten;
	size_t last_time_eat;
	t_data *data;
}	t_philos;

/* ************************ Philosophers Functions ******************************* */

void	ft_print(t_philos *philo, size_t time, char *str, int state);
void	ft_usleep(size_t time);

size_t	get_time_diff(size_t time);
size_t	get_time();

int	ft_atoi(const char *nptr);
int	ft_isdigit(int c);
int	get_args(char *av[]);
void	init_philos(int ac, char *av[],t_data *philo);

void	start_philos(t_data *philo);
int	mutex_init(t_data *data);
void	*print_id(void *id);

int	check_death(t_philos *philo);
void	check_meals(t_data *data);
#endif // !PHILO_H
