/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:52:29 by melhadou          #+#    #+#             */
/*   Updated: 2023/08/02 19:04:03 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

/* GetTime */
size_t	get_time()
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

size_t	get_time_diff(size_t time)
{
	return (get_time() - time);
}

void	init_philos(int ac, char *av[],t_data *data)
{
	size_t i;

	i = 0;
	data->game_over = 0;
	data->nb_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_sleep = ft_atoi(av[3]);
	data->time_to_eat = ft_atoi(av[4]);
	if (ac == 6)
		data->nb_must_eat = ft_atoi(av[5]);
	else
		data->nb_must_eat = 0;
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
	data->start_time = get_time();
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
		data->philos[i].id = i + 1;
		data->philos[i].nb_eaten = 0;
		data->philos[i].last_time_eat = get_time();
		data->philos[i].data = data;
		i++;
	}
}

int	mutex_init(t_data *data)
{
	size_t i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (1);
		i++;
	}
	pthread_mutex_init(&data->prints, NULL);
	pthread_mutex_init(&data->eat, NULL);
	pthread_mutex_init(&data->time, NULL);
	return (0);
}

void	*print_id(void *arg)
{
	t_philos *philo;

	philo = (t_philos *)arg;

	while (1)
	{
		// if is eaten enough
		if (philo->data->nb_must_eat == philo->nb_eaten
			&& philo->data->nb_must_eat != 0)
			break ;
		pthread_mutex_lock(&philo->data->forks[philo->id - 1]);
		ft_print(philo, get_time_diff(philo->data->start_time), "has taken a fork", 0);
		pthread_mutex_lock(&philo->data->forks[philo->id % philo->data->nb_philo]);
		ft_print(philo, get_time_diff(philo->data->start_time), "has taken a fork", 0);
	
		ft_print(philo, get_time_diff(philo->data->start_time), "is eating", 0);
		pthread_mutex_lock(&philo->data->eat);
		philo->nb_eaten++;
		pthread_mutex_unlock(&philo->data->eat);

		pthread_mutex_lock(&philo->data->time);
		philo->last_time_eat = get_time();
		pthread_mutex_unlock(&philo->data->time);
	
		ft_usleep(philo->data->time_to_eat);
		pthread_mutex_unlock(&philo->data->forks[philo->id - 1]);
		pthread_mutex_unlock(&philo->data->forks[philo->id % philo->data->nb_philo]);
		ft_print(philo, get_time_diff(philo->data->start_time),"is sleping", 0);
		ft_usleep(philo->data->time_to_sleep);
		ft_print(philo, get_time_diff(philo->data->start_time), "is thinking", 0);
	}
	return NULL;
}

void	start_philos(t_data *philo)
{
	size_t i;

	i = 0;
	while (i < philo->nb_philo)
	{
		pthread_create(&philo->tid[i], NULL, print_id, &philo->philos[i]);
		pthread_detach(philo->tid[i]);
		i += 2;
	}
	usleep(100);
	i = 1;
	while (i < philo->nb_philo)
	{
		pthread_create(&philo->tid[i], NULL, print_id, &philo->philos[i]);
		i += 2;
	}
}
