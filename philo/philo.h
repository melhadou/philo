/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:52:21 by melhadou          #+#    #+#             */
/*   Updated: 2023/07/27 18:24:32 by melhadou         ###   ########.fr       */
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
	int nb_philo;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int nb_eat;
	pthread_t *tid;
	struct t_philos *philos;
	pthread_mutex_t *forks;
	pthread_mutex_t prints;
} t_data;

typedef struct t_philos
{
	int philo_id;
	int nb_eaten;
	t_data *data;
}	t_philos;

/* ************************ Philosophers Functions ******************************* */
int	get_time();
int	ft_atoi(const char *nptr);
int	ft_isdigit(int c);
int	get_args(char *av[]);
void	init_philos(int ac, char *av[],t_data *philo);

void	start_philos(t_data *philo);
int	mutex_init(t_data *data);
void	*print_id(void *id);
#endif // !PHILO_H
