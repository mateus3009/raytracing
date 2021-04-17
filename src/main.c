/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 19:58:25 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/16 21:34:51 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(void)
{
	double		aspect_ratio;
	t_camera	cam;
	t_object	obj;
	t_canvas	canvas;
	t_point		look_from;
	t_point		look_at;


	look_from = point(0, 0, 2);
	look_at = point(0, 0, -1);
	aspect_ratio = 16. / 9.;
	canvas = canvas_init(300, 300 / aspect_ratio);
	cam = camera((t_camera_param){
		.look_from = look_from,
		.look_at = look_at,
		.aspect_ratio = aspect_ratio,
		.up = vector(0, 1, 0),
		.vertical_field_of_view = 90,
		.aperture = .1,
		.focus_distance = length(minus(look_from, look_at))});
	obj = sphere();
	t_list *k = ft_lstnew(&obj);
	render(cam, canvas, k);
	canvas_to_ppm(canvas);
	return (0);
}
