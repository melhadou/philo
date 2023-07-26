/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:04:22 by melhadou          #+#    #+#             */
/*   Updated: 2023/07/26 17:21:11 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int main(int ac, char *av[])
{
	// test args
	t_args args;

	if (ac == 1)
		return (1);
	if (!get_args(ac, av, &args))
	{
		printf("error");
		return (1);
	}
	printf("nb_philo: %d\n", args.nb_philo);
	return (0);
}
