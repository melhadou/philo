/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:54:19 by melhadou          #+#    #+#             */
/*   Updated: 2023/08/03 16:22:38 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// normed funcs
void	ft_print(t_philos *philo, size_t time, char *str, int state)
{
	pthread_mutex_lock(&philo->data->prints);
	printf("%zu ms \t %zu %s\n", time, philo->id, str);
	if (state)
		return ;
	pthread_mutex_unlock(&philo->data->prints);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	long	n;

	n = 0;
	i = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		sign = 1 - 2 * (nptr[i++] == '-');
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = n * 10 + (nptr[i] - '0');
		if ((n > 2147483647 && sign == 1)
			|| (n > 2147483648 && sign == -1))
			return (-1);
		i++;
	}
	return (n * sign);
}

int	check_death(t_philos *philo)
{
	pthread_mutex_lock(&philo->data->time);
	if (get_time_diff(philo->last_time_eat) >= philo->data->time_to_die)
	{
		philo->data->game_over = 1;
		ft_print(philo, get_time_diff(philo->data->start_time), "died", 1);
		pthread_mutex_unlock(&philo->data->time);
		return (0);
	}
	pthread_mutex_unlock(&philo->data->time);
	return (1);
}

void	check_meals(t_data *data)
{
	size_t	i;

	i = 0;
	if (!data->nb_must_eat)
		return ;
	pthread_mutex_lock(&data->eat);
	while (i < data->nb_philo)
	{
		if (data->philos[i].nb_eaten < data->nb_must_eat)
		{
			pthread_mutex_unlock(&data->eat);
			return ;
		}
		i++;
	}
	pthread_mutex_unlock(&data->eat);
	data->game_over = 1;
}
