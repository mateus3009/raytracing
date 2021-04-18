/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 19:58:25 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/18 17:56:18 by msales-a         ###   ########.fr       */
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

	look_from = matrix_product(rotatey(degrees_to_radians(40)), point(0, 0, -15));
	look_at = point(0, 0, 0);
	aspect_ratio = 3. / 2.;
	canvas = canvas_init(400, 400 / aspect_ratio);
	cam = camera((t_camera_param){
		.look_from = look_from,
		.look_at = look_at,
		.aspect_ratio = aspect_ratio,
		.up = vector(0, 1, 0),
		.vertical_field_of_view = 20,
		.aperture = .1,
		.focus_distance = length(minus(look_from, look_at))});
	t_object a = sphere();
	a.inverse_matrix = matrix_invert(rotatey(degrees_to_radians(30)));
	t_object b = sphere();
	b.inverse_matrix = matrix_invert(translate(2, 0, 0));
	t_list *world = ft_lstnew(&a);
	ft_lstadd_back(&world, ft_lstnew(&b));
	render((t_job){
		.camera = cam,
		.canvas = canvas,
		.objects = world,
		.samples_per_pixel = 1
	});
	canvas_to_ppm(canvas);
	return (0);
}
