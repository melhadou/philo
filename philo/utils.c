/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:52:29 by melhadou          #+#    #+#             */
/*   Updated: 2023/07/26 17:36:06 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* GetTime */
int	get_time()
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return (tv.tv_sec * (int)1000 + tv.tv_usec / 1000);
}

int	valid_args(char **args)
{
	int	i;

	i = -1;
	while (args[++i])
	{
		if (is_number(args[i]))
			return (0);
	}
	return (1);
}
