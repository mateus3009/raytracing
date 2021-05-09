/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 11:28:30 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 15:07:06 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CANVAS_H
# define CANVAS_H

# include "./../util/util.h"
# include "./../tuple/tuple.h"

# define BMP_HEADER_SIZE 14
# define BMP_INFO_HEADER_SIZE 40

typedef struct s_canvas
{
	int		width;
	int		height;
	t_pixel	*pixels;
}				t_canvas;

t_canvas		canvas_init(int width, int height);
void			canvas_destroy(void *data);
void			write_pixel(
					t_canvas canvas,
					int width,
					int height,
					t_pixel pixel);
void			canvas_to_ppm(t_canvas canvas);
t_pixel			get_pixel(t_canvas canvas, int width, int height);
double			pixel_diff(t_pixel a, t_pixel b);
void			canvas_to_bmp(t_canvas canvas, char *filename);
void			all_canvas_to_bmp(t_list *canvas);

#endif
