/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_job_with_threads.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:45:02 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/10 21:04:29 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"
#include <pthread.h>

static bool	clean_threads_and_data(
	int size,
	pthread_t **threads,
	t_handle_job_data **data)
{
	while (size--)
		pthread_cancel((*threads)[size]);
	free (*threads);
	free(*data);
	return (false);
}

static bool	create_thread_and_data(
	t_job *job,
	pthread_t **threads,
	t_handle_job_data **data)
{
	*threads = ft_calloc(sizeof(pthread_t), job->threads);
	if (!*threads)
		return (false);
	*data = ft_calloc(sizeof(t_handle_job_data), job->threads);
	if (!*data)
	{
		free(*threads);
		return (false);
	}
	return (true);
}

static bool	init_thread_and_data(
	t_job *job,
	pthread_t **threads,
	t_handle_job_data **data)
{
	int	index;

	index = -1;
	while (++index < job->threads)
	{
		(*data)[index] = (t_handle_job_data){.job = job, .thread_id = index};
		if (pthread_create(&((*threads)[index]),
			NULL, render_job, &((*data)[index])))
			return (clean_threads_and_data(index, threads, data));
	}
	return (true);
}

static bool	wait_threads_and_free(
	t_job *job,
	pthread_t **threads,
	t_handle_job_data **data)
{
	int	index;

	index = -1;
	while (++index < job->threads)
	{
		if (pthread_join((*threads)[index], NULL))
			return (clean_threads_and_data(index, threads, data));
	}
	return (!clean_threads_and_data(index, threads, data));
}

bool	render_job_with_threads(t_job *job)
{
	pthread_t			*threads;
	t_handle_job_data	*data;
	int					index;

	if (!create_thread_and_data(job, &threads, &data))
		return (false);
	if (!init_thread_and_data(job, &threads, &data))
		return (false);
	return (wait_threads_and_free(job, &threads, &data));
}
