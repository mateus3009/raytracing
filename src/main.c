/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 19:58:25 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/21 11:51:24 by msales-a         ###   ########.fr       */
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

	look_from = point(0, 1, 10);
	look_at = point(0, 0, -1);
	aspect_ratio = 3. / 2.;
	canvas = canvas_init(400, 400 / aspect_ratio);
	cam = camera((t_camera_param){
		.look_from = look_from,
		.look_at = look_at,
		.aspect_ratio = aspect_ratio,
		.up = vector(0, 1, 0),
		.vertical_field_of_view = 30,
		.aperture = 0,
		.focus_distance = length(minus(look_from, look_at))});
	t_object p = plane();
	t_object c = cube();
	c.inverse_matrix = matrix_invert(matrix_multiply(
		translate(0, 3, -5),
		rotatey(degrees_to_radians(45))));
	c.material = lambertian(pixel(.5, .5, .5));
	t_object s1 = sphere();
	s1.inverse_matrix = matrix_invert(translate(0, 1, 0));
	s1.material = lambertian(pixel(.7, .7, .7));
	t_object s2 = sphere();
	s2.inverse_matrix = matrix_invert(translate(2, 1, 0));
	s2.material = lambertian(pixel(.8, .8, .8));
	t_list *world = NULL;
	ft_lstadd_front(&world, ft_lstnew(&p));
	ft_lstadd_front(&world, ft_lstnew(&c));
	ft_lstadd_front(&world, ft_lstnew(&s1));
	ft_lstadd_front(&world, ft_lstnew(&s2));
	render((t_job){
		.camera = cam,
		.canvas = canvas,
		.objects = world,
		.min_samples_per_pixel = 30,
		.max_samples_per_pixel = 90,
		.depth = 50
	});
	canvas_to_ppm(canvas);
	return (0);
}
