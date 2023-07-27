/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:04:22 by melhadou          #+#    #+#             */
/*   Updated: 2023/07/27 10:31:15 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char *av[])
{
	t_philo philo;

	if (ac != 5 && ac != 6)
	{
		printf("Error: Wrong number of arguments ac => %d \n", ac);
		return (1);
	}

	if (get_args(av))
		return (1);

	init_philos(ac, av, &philo);
	return (0);
}
