/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 16:54:19 by melhadou          #+#    #+#             */
/*   Updated: 2023/07/30 16:50:05 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print_fork(t_philos *philo)
{
	pthread_mutex_lock(&philo->data->prints);
	printf("%zu ms\tphilo %d\thas taken a fork\n",get_time_diff(philo->data->start_time), philo->philo_id);
	pthread_mutex_unlock(&philo->data->prints);
}

void	ft_print_sleep(t_philos *philo)
{
	pthread_mutex_lock(&philo->data->prints);
	printf("%zu ms\tphilo %d\tis sleeping\n",get_time_diff(philo->data->start_time), philo->philo_id);
	pthread_mutex_unlock(&philo->data->prints);
}

void	ft_print_think(t_philos *philo)
{
	pthread_mutex_lock(&philo->data->prints);
	printf("%zu ms\tphilo %d\tis thinking\n",get_time_diff(philo->data->start_time), philo->philo_id);
	pthread_mutex_unlock(&philo->data->prints);
}

void	ft_print_eating(t_philos *philo)
{
	pthread_mutex_lock(&philo->data->prints);
	printf("%zu ms\tphilo %d\tis eating\n",get_time_diff(philo->data->start_time), philo->philo_id);
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
	long	n;
	int					i;
	int					sign;

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

void	ft_usleep(size_t time)
{
	size_t	start;
	start = get_time();
	while ((get_time() - start) < time)
		usleep(1);
}
