/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:04:22 by melhadou          #+#    #+#             */
/*   Updated: 2023/07/28 12:14:06 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_death(t_data *data)
{
	int i;

	i  = 0;
	while (i < data->nb_philo)
	{
		if (get_time() - data->philos[i].last_time_eat >= (size_t) data->time_to_die)
			return (i);
		i++;
	}
	return (0);
}

int check_nb_eat(t_data *data)
{
	int i;
	i = 0;
	while (i < data->nb_philo)
	{
		if (data->philos[i].nb_eaten < data->nb_eat)
			return (1);
		i++;
	}
	return (0);
}

int main(int ac, char *av[])
{
	t_data data;

	if (ac != 5 && ac != 6)
	{
		printf("Error: Wrong number of arguments ac => %d \n", ac);
		return (1);
	}
	if (get_args(av))
		return (1);

	init_philos(ac, av, &data);
	start_philos(&data);
	int id;
	int id_eat;
	while (1)
	{
		id = check_death(&data);
		if (id)
		{
			printf("%zu ms\t%d\t died\n", get_time() - data.start_time, id + 1);
			break ;
		}
		id_eat = check_nb_eat(&data);
		if (data.nb_eat != -1 && id_eat)
		{
			printf("%zu ms\t%d\t died\n", get_time() - data.start_time, id + 1);
			break ;
		}
	}
	return (0);
}
