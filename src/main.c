/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 19:58:25 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/16 20:10:49 by msales-a         ###   ########.fr       */
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
			bool teste = intersect(obj, ray, (t_hit_range){.min = .001, .max = INFINITY}, &hit);
			if (teste)
			{
				t_tuple k = divide(sum(normalize(hit.normal), vector(1, 1, 1)), 2);
				if (k.x < 0 || k.y < 0 || k.z < 0)
					k = k;
				write_pixel(canvas, x, y,
					(t_tuple_pixel)k);
			}
		}
	}
}


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
	teste(cam, canvas, obj);
	canvas_to_ppm(canvas);
	return (0);
}
