/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:52:29 by melhadou          #+#    #+#             */
/*   Updated: 2023/07/27 18:48:37 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

/* GetTime */
int	get_time()
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return (tv.tv_sec * (int)1000 + tv.tv_usec / 1000);
}

void	init_philos(int ac, char *av[],t_data *data)
{
	int i;

	i = 0;
	data->nb_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_sleep = ft_atoi(av[3]);
	data->time_to_eat = ft_atoi(av[4]);
	if (ac == 6)
		data->nb_eat = ft_atoi(av[5]);
	else
		data->nb_eat = -1;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->forks)
		return ;
	data->tid = malloc(sizeof(pthread_t) * data->nb_philo);
	if (!data->tid)
	{
		free(data->forks);
		return ;
	}
	data->philos = malloc(sizeof(t_philos) * data->nb_philo);
	if (!data->tid)
	{
		free(data->forks);
		free(data->tid);
		return ;
	}
	// init mutex;
	mutex_init(data);
	while (i < data->nb_philo)
	{
		data->philos[i].philo_id = i;
		data->philos[i].nb_eaten = 0;
		data->philos[i].data = data;
	}
}

int	mutex_init(t_data *data)
{
	int i;
	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (1);
		i++;
	}
	pthread_mutex_init(&data->prints, NULL);
	return (0);
}


void	*print_id(void *arg)
{
	t_philos *philo;

	philo = (t_philos *)arg;
	while (1)
	{
		// lock fork;
		pthread_mutex_lock(&philo->data->forks[philo->philo_id]);
		pthread_mutex_lock(&philo->data->forks[philo->philo_id + 1 % philo->data->nb_philo]);
		pthread_mutex_lock(&philo->data->prints);
		printf("Philosopher %d has taken a fork\n", philo->philo_id);
		pthread_mutex_unlock(&philo->data->prints);
		// start eating
		pthread_mutex_lock(&philo->data->prints);
		printf("Philosopher %d started eating\n", philo->philo_id);
		usleep(philo->data->time_to_eat * 1000);
		pthread_mutex_unlock(&philo->data->prints);
		
		// realsing forks
		pthread_mutex_unlock(&philo->data->forks[philo->philo_id]);
		pthread_mutex_unlock(&philo->data->forks[philo->philo_id + 1 % philo->data->nb_philo]);
		// unlcok fork;
	}
	return NULL;
}

void	start_philos(t_data *philo)
{
	int i;

	i = 0;
	while (1)
	{
		if (i == philo->nb_philo)
			break ;
		pthread_create(&philo->tid[i], NULL, print_id, &philo->philos[i]);
		i += 1;
	}
	// i = 1;
	// while (1)
	// {
	// 	if (i == philo->nb_philo)
	// 		break ;
	// 	pthread_create(&philo->tid[i], NULL, print_id, &philo->philos[i]);
	// 	i += 2;
	// }
}
