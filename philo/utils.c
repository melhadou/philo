/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:52:29 by melhadou          #+#    #+#             */
/*   Updated: 2023/07/27 10:29:46 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* GetTime */
int	get_time()
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return (tv.tv_sec * (int)1000 + tv.tv_usec / 1000);
}

void	init_philos(int ac, char *av[],t_philo *philo)
{
	philo->nb_philo = ft_atoi(av[1]);
	philo->time_to_die = ft_atoi(av[2]);
	philo->time_to_sleep = ft_atoi(av[3]);
	philo->time_to_eat = ft_atoi(av[4]);
	if (ac == 6)
		philo->nb_eat = ft_atoi(av[5]);
	else
		philo->nb_eat = -1;
	philo->last_eat = malloc(sizeof(int) * philo->nb_philo);
	philo->philo = malloc(sizeof(int) * philo->nb_philo);
}
