/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 22:33:53 by melhadou          #+#    #+#             */
/*   Updated: 2023/07/26 21:20:51 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_args(char *av[])
{
	int i;

	i = 1;
	while (av[i])
	{
		// checking for invalid values
		if (!*av[i] || ft_atoi(av[i]) == -1)
		{
			printf("Error: invalid Arguments\n");
			return (1);
		}
		// checking for non digit values
		while (*av[i])
		{
			if (!ft_isdigit(*av[i]))
			{
				printf("Error: Non Numreques value\n");
				return (1);
			}
			av[i]++;
		}
		i++;
	}
	return (0);
}
