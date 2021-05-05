/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:10:13 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/05 00:26:23 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARE_H
# define SQUARE_H

# include "./../objects.h"

typedef struct s_square_build
{
	t_point		origin;
	double		half_size;
	t_vector	direction;
	t_pixel		color;
}				t_square_build;

bool			square(t_object **obj, t_square_build params);
bool			square_intersect(
					t_object object,
					t_ray ray,
					t_range range,
					double *t);
t_vector		square_normal_at(
					void *data,
					t_point object_point);

#endif
