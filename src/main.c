/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 19:58:25 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/17 00:37:29 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(void)
{
	double		aspect_ratio;
	t_camera	cam;
	t_canvas	canvas;
	t_point		look_from;
	t_point		look_at;


	look_from = point(3, 3, 3);
	look_at = point(0, 0, 0);
	aspect_ratio = 16. / 9.;
	canvas = canvas_init(800, 800 / aspect_ratio);
	cam = camera((t_camera_param){
		.look_from = look_from,
		.look_at = look_at,
		.aspect_ratio = aspect_ratio,
		.up = vector(0, 1, 0),
		.vertical_field_of_view = 90,
		.aperture = .1,
		.focus_distance = length(minus(look_from, look_at))});
	t_object a = sphere(translate(2, 0, 0));
	t_object b = sphere(matrix_identity(4));
	t_object c = sphere(translate(-2, 0, 0));
	t_list *world = ft_lstnew(&a);
	ft_lstadd_front(&world, ft_lstnew(&b));
	ft_lstadd_front(&world, ft_lstnew(&c));
	render(cam, canvas, world);
	canvas_to_ppm(canvas);

	/*t_object		s = sphere(scaling(2, 2, 2));
	t_ray			r = ray(point(0, 0, -5), vector(0, 0, 1));
	t_intersection	hit;
	bool h = intersect(s, r, (t_range){.min = .0001, .max = INFINITY}, &hit);
	printf("%f\n", hit.t);*/
	return (0);
}
