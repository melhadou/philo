/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melhadou <melhadou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 20:04:22 by melhadou          #+#    #+#             */
/*   Updated: 2023/07/21 17:49:58 by melhadou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>
#include <stdio.h>

typedef struct t_data {
	int num;
	pthread_mutex_t mutex;
} t_data;

void *routing(void *dt)
{
	int i;
	t_data *data;

	data = (t_data *)dt;
	i = 0;
	while (i < 10000000)
	{
		pthread_mutex_lock(&data->mutex);
		data->num++;
		i++;
		pthread_mutex_unlock(&data->mutex);
	}
	return (0);
}

int main(int ac, char *av[])
{

	(void) ac;
	(void) av;
	t_data data;
	pthread_t t1;
	pthread_t t2;
	
	pthread_mutex_init(&data.mutex, NULL);
	if (pthread_create(&t1, NULL, routing, &data))
		return (1);
	if (pthread_create(&t2, NULL, routing, &data))
		return (1);
	if (pthread_join(t1, NULL))
		return (2);
	if (pthread_join(t2, NULL))
		return (2);
	printf("num = %d\n", data.num);
	pthread_mutex_destroy(&data.mutex);
	return (0);
}
