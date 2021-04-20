/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 19:58:25 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/20 09:46:51 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <assert.h>

int	main(void)
{
	double		aspect_ratio;
	t_camera	cam;
	t_canvas	canvas;
	t_point		look_from;
	t_point		look_at;

	look_from = point(0, 0, 20);
	look_at = point(0, 0, -1);
	aspect_ratio = 3. / 2.;
	canvas = canvas_init(1200, 1200 / aspect_ratio);
	cam = camera((t_camera_param){
		.look_from = look_from,
		.look_at = look_at,
		.aspect_ratio = aspect_ratio,
		.up = vector(0, 1, 0),
		.vertical_field_of_view = 20,
		.aperture = 0,
		.focus_distance = length(minus(look_from, look_at))});
	t_object a = cylinder();
	a.data = &((t_cylinder){.min = 1, .max = 2, .closed = true});
	a.inverse_matrix = matrix_invert(rotatex(degrees_to_radians(45)));
	t_list *world = ft_lstnew(&a);
	render((t_job){
		.camera = cam,
		.canvas = canvas,
		.objects = world,
		.samples_per_pixel = 100,
		.depth = 50
	});
	canvas_to_ppm(canvas);
	return (0);
}
