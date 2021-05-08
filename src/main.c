/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 19:58:25 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/07 19:19:48 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_rt_data	rt;
	t_list		*jobs;

	if (argc < 2
		|| !process_file(argv[1], &rt)
		|| !rt_data_to_job(rt, &jobs)
		|| !ft_lstsize(jobs))
		return (EXIT_FAILURE);
	render_job_with_threads(jobs->content);
	canvas_to_bmp((*(t_job*)jobs->content).canvas, "output_new.bmp");
	ft_lstclear(&jobs, clear_job);
	printf("Finish\n");
	return (EXIT_SUCCESS);
}
