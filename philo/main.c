/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:04:22 by melhadou          #+#    #+#             */
/*   Updated: 2023/08/02 19:02:40 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char *av[])
{
	t_data data;
	size_t i;

	i = 0;
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
		if (data.nb_must_eat)
		{
			check_meals(&data);
			if (data.game_over)
			{
				printf("All philos ate %zu times\n", data.nb_must_eat);
				return (1);
			}
		}

		while (i < data.nb_philo)
		{
			if (!check_death(&data.philos[i]))
				return (1);
			i++;
		}
		i = 0;
	}
	return (0);
}
