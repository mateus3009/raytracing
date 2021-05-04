/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 19:58:25 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/04 18:02:11 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_rt_data	rt;
	t_list		*jobs;

	if (argc < 2)
		return (EXIT_FAILURE);
	process_file(argv[1], &rt);
	rt_data_to_job(rt, &jobs);
	render_job(*(t_job*)jobs->content);
	canvas_to_bmp((*(t_job*)jobs->content).canvas, "output_new.bmp");
	ft_lstclear(&jobs, clear_job);
	return (EXIT_SUCCESS);
}
