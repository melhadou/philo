/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 19:52:21 by melhadou          #+#    #+#             */
/*   Updated: 2023/07/26 17:36:48 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdlib.h>

// struct of args
typedef struct t_args
{
	int		nb_philo;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		nb_eat;
}	t_args;

// utils function
int	get_time();
int	valid_args(char **args);

// ft_utils functions
int	ft_atoi(const char *nptr);
int	ft_isdigit(int c);
int	ft_error();
int	is_number(char *str);

// parse functions
int	get_args(int ac, char *av[], t_args *args);
#endif // !PHILO_H
