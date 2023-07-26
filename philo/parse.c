/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 22:33:53 by melhadou          #+#    #+#             */
/*   Updated: 2023/07/26 18:22:55 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// parse the arguments for numrique values

// check args for empty values
int	get_args(int ac, char *av[], t_args *args)
{
	int	i;

	i = ac;
	if (ac == 4 || ac == 5)
	{
		if (valid_args(av))
			return 0;
		args->nb_philo = ft_atoi(av[1]);
		args->time_to_die = ft_atoi(av[1]);
		args->time_to_eat = ft_atoi(av[1]);
		args->time_to_sleep = ft_atoi(av[1]);
		if (ac == 5)
			args->nb_eat = ft_atoi(av[1]);
		else
			args->nb_eat = -1;
		return (1);
	}
	return (0);
}
