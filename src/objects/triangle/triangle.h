/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:10:13 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/04 20:41:13 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_H
# define TRIANGLE_H

# include "./../objects.h"

typedef struct s_triangle
{
	t_point		p1;
	t_point		p2;
	t_point		p3;
	t_point		e1;
	t_point		e2;
	t_vector	normal;
}				t_triangle;


bool			triangle(t_object **obj);
bool			triangle_intersect(
					t_object object,
					t_ray ray,
					t_range range,
					double *t);
t_vector		triangle_normal_at(
					void *data,
					t_point object_point);

#endif
