/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 19:58:25 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/15 18:39:23 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	teste(t_camera camera, t_canvas canvas, t_object obj)
{
	int		x;
	int		y;
	double	w;
	double	h;
	t_ray	ray;
	t_intersection	hit;

	y = canvas.height;
	while (--y >= 0)
	{
		x = -1;
		while (x++ < canvas.width - 1)
		{
			h = y / (double)(canvas.height - 1);
			w = x / (double)(canvas.width - 1);
			ray = get_ray(camera, w, h);
			bool teste = sphere_intersect(obj, ray, (t_hit_range){.min = .001, .max = INFINITY}, &hit);
			if (teste)
				write_pixel(canvas, x, y, (t_pixel){1, 1, 1, 1});
		}
	}
}

int	main(void)
{
	double		aspect_ratio;
	t_canvas	canvas;
	t_camera	cam;
	t_object	object;

	aspect_ratio = 3 / 2;
	canvas = canvas_init(100, 100 / aspect_ratio);
	object = sphere();
	cam = camera((t_camera_param){
		.look_from = point(-2, 2, 1),
		.look_at = point(0, 0, -1),
		.up = vector(0, 1, 0),
		.aperture = 0,
		.aspect_ratio = aspect_ratio,
		.focus_distance = 1,
		.vertical_field_of_view = 90
	});
	teste(cam, canvas, object);
	canvas_to_ppm(canvas);
	return (0);
}
