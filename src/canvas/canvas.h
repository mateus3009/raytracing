/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 11:28:30 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/15 21:23:10 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

# include "./../util/util.h"

# include "./../tuple/tuple.h"

typedef struct s_pixel
{
	double	r;
	double	g;
	double	b;
	double	a;
}				t_pixel;

typedef struct s_canvas
{
	int		width;
	int		height;
	t_pixel	*pixels;
}				t_canvas;

t_canvas		canvas_init(int width, int height);
void			canvas_destroy(t_canvas canvas);
void			write_pixel(t_canvas canvas, int width, int height, t_pixel pixel);
void			canvas_to_ppm(t_canvas canvas);

#endif
