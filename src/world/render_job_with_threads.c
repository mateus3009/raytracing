/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_job_with_threads.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:45:02 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/05 17:04:36 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include <pthread.h>

static void	clean_threads(int size, pthread_t *threads)
{
	while (size--)
		pthread_cancel(threads[size]);
	free (threads);
}

bool	render_job_with_threads(t_job *job)
{
	pthread_t			*threads;
	t_handle_job_data	*data;
	int					index;

	threads = ft_calloc(sizeof(pthread_t), job->threads);
	if (!threads)
		return (false);
	data = ft_calloc(sizeof(t_handle_job_data), job->threads);
	if (!data)
	{
		free(threads);
		return (false);
	}
	index = -1;
	while (++index < job->threads)
	{
		data[index] = (t_handle_job_data){.job = job, .thread_id = index};
		if (pthread_create(&(threads[index]), NULL, render_job, &(data[index])))
		{
			clean_threads(index, threads);
			free(data);
			return (false);
		}
	}
	index = -1;
	while (++index < job->threads)
	{
		if (pthread_join(threads[index], NULL))
		{
			clean_threads(index, threads);
			free(data);
			return (false);
		}
	}
	return (true);
}
