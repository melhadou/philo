/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:41:49 by melhadou          #+#    #+#             */
/*   Updated: 2023/08/03 19:10:15 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	contole_lock(t_philos *philo, char state)
{
	if (state == 'l')
	{
		pthread_mutex_lock(&philo->data->forks[philo->id - 1]);
		ft_print(philo, get_time_diff(philo->data->start_time),
			"has taken a fork", 0);
		pthread_mutex_lock(&philo->data->forks[
			philo->id % philo->data->nb_philo]);
		ft_print(philo, get_time_diff(philo->data->start_time),
			"has taken a fork", 0);
	}
	else if (state == 'u')
	{
		pthread_mutex_unlock(&philo->data->forks[philo->id - 1]);
		pthread_mutex_unlock(&philo->data->forks[
			philo->id % philo->data->nb_philo]);
		ft_print(philo, get_time_diff(philo->data->start_time),
			"is sleping", 0);
	}
}

void	*print_id(void *arg)
{
	t_philos	*philo;

	philo = (t_philos *)arg;
	while (1)
	{
		if (philo->data->nb_must_eat == philo->nb_eaten
			&& philo->data->nb_must_eat != 0)
			break ;
		contole_lock(philo, 'l');
		ft_print(philo, get_time_diff(philo->data->start_time),
			"is eating", 0);
		pthread_mutex_lock(&philo->data->eat);
		philo->nb_eaten++;
		pthread_mutex_unlock(&philo->data->eat);
		ft_usleep(philo->data->time_to_eat);
		pthread_mutex_lock(&philo->data->time);
		philo->last_time_eat = get_time();
		pthread_mutex_unlock(&philo->data->time);
		contole_lock(philo, 'u');
		ft_usleep(philo->data->time_to_sleep);
		ft_print(philo, get_time_diff(philo->data->start_time),
			"is thinking", 0);
	}
	return (NULL);
}

void	start_philos(t_data *data)
{
	size_t	i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_create(&data->tid[i], NULL, print_id, &data->philos[i]);
		pthread_detach(data->tid[i]);
		i += 2;
	}
	usleep(100);
	i = 1;
	while (i < data->nb_philo)
	{
		pthread_create(&data->tid[i], NULL, print_id, &data->philos[i]);
		i += 2;
	}
}
