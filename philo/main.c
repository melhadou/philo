/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:04:22 by melhadou          #+#    #+#             */
/*   Updated: 2023/07/30 18:16:10 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_data *data)
{
	int i;

	i  = 0;
	while (i < data->nb_philo)
	{
		if (get_time_diff(data->philos[i].last_time_eat) >= (size_t)data->time_to_die)
			return (i + 1);
		i++;
	}
	return (0);
}

int	check_nb_eat(t_data *data)
{
	int i;

	i = 0;
	while (i < data->nb_philo)
	{
		if (data->philos[i].nb_eaten >= data->nb_eat)
			return (i + 1);
		i++;
	}
	return (-1);
}

void ft_print_death(t_data *data, int id)
{
	pthread_mutex_lock(&data->prints);
	printf("%zu ms\t%d\t died\n", get_time_diff(data->start_time), id);
}

int	main(int ac, char *av[])
{
	t_data data;
	int id;
	int id_eat;

	if (ac != 5 && ac != 6)
	{
		printf("Error: Wrong number of arguments ac => %d \n", ac);
		return (1);
	}
	if (get_args(av))
		return (1);

	init_philos(ac, av, &data);
	start_philos(&data);
 while (1)
	{
		id = check_death(&data);
		if (id)
		{
			ft_print_death(&data, id);
			break; // Exit the loop if a philosopher dies
		}

		if (data.nb_eat != -1) // Check if meal requirements are enabled
		{
			id_eat = check_nb_eat(&data);
			if (id_eat != -1)
			{
				ft_print_death(&data, id_eat);
				break; // Exit the loop if a philosopher has met meal requirements
			}
		}
	}
	return (0);
}
