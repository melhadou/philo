/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 22:33:53 by melhadou          #+#    #+#             */
/*   Updated: 2023/08/02 19:11:05 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// normed
int	get_args(char **av)
{
	int		i;
	char	*str;

	i = 1;
	while (av[i])
	{
		if (!*av[i] || ft_atoi(av[i]) == -1 || ft_atoi(av[i]) == 0)
		{
			printf("Error: invalid Arguments\n");
			return (1);
		}
		str = av[i];
		while (*str)
		{
			if (!ft_isdigit(*str))
			{
				printf("Error: Non Numreques value\n");
				return (1);
			}
			str++;
		}
		i++;
	}
	return (0);
}
