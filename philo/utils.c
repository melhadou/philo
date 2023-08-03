/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:52:29 by melhadou          #+#    #+#             */
/*   Updated: 2023/08/03 16:41:57 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_args(int ac, char **av, t_data *data)
{
	data->nb_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_sleep = ft_atoi(av[3]);
	data->time_to_eat = ft_atoi(av[4]);
	if (ac == 6)
		data->nb_must_eat = ft_atoi(av[5]);
	else
		data->nb_must_eat = 0;
	data->game_over = 0;
	data->start_time = get_time();
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
	if (!data->forks)
		return ;
	data->tid = malloc(sizeof(pthread_t) * data->nb_philo);
	if (!data->tid)
	{
		free(data->forks);
		return ;
	}
}

void	init_philos(int ac, char *av[], t_data *data)
{
	size_t	i;

	init_args(ac, av, data);
	data->philos = malloc(sizeof(t_philos) * data->nb_philo);
	if (!data->tid)
	{
		free(data->forks);
		free(data->tid);
		return ;
	}
	i = 0;
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
	size_t	i;

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
