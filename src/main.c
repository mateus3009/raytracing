/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 19:58:25 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/18 09:34:30 by msales-a         ###   ########.fr       */
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

	look_from = point(-50, 50, -50);
	look_at = point(0, 0, 0);
	aspect_ratio = 3. / 2.;
	canvas = canvas_init(800, 800 / aspect_ratio);
	cam = camera((t_camera_param){
		.look_from = look_from,
		.look_at = look_at,
		.aspect_ratio = aspect_ratio,
		.up = vector(0, 1, 0),
		.vertical_field_of_view = 20,
		.aperture = .1,
		.focus_distance = length(minus(look_from, look_at))});
	t_object a = sphere();
	a.inverse_matrix = matrix_invert(translate(0, 0, 0));
	t_object b = plane();
	b.inverse_matrix = matrix_invert(rotatez(degrees_to_radians(40)));
	t_list *world = ft_lstnew(&a);
	ft_lstadd_front(&world, ft_lstnew(&b));
	render(cam, canvas, world);
	canvas_to_ppm(canvas);

	return (0);
}
