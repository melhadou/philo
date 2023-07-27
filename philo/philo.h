/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:52:21 by melhadou          #+#    #+#             */
/*   Updated: 2023/07/27 10:15:47 by melhadou         ###   ########.fr       */
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
typedef struct t_philo
{
	int nb_philo;
	int time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int nb_eat;
	unsigned int *last_eat;
	pthread_t *philo;
} t_philo;


// utils function
int	get_time();
void	init_philos(int ac, char *av[],t_philo *philo);

// ft_utils functions
int	ft_atoi(const char *nptr);
int	ft_isdigit(int c);

// parse functions
int	get_args(char *av[]);
#endif // !PHILO_H
