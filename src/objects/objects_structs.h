/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_structs.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:10:13 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/14 23:12:45 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_STRUCTS_H
# define OBJECTS_STRUCTS_H

# include "./../tuple/tuple.h"
# include "./../ray/ray.h"

struct s_object;
struct s_hit_range;
struct s_intersection;

typedef struct s_object t_object;
typedef struct s_hit_range t_hit_range;
typedef struct s_intersection t_intersection;

typedef struct s_object
{
	void	*data;
	bool	(*intersect)(
		t_object object,
		t_ray ray,
		t_hit_range range,
		t_intersection * hit);
}				t_object;

typedef struct s_hit_range
{
	double	min;
	double	max;
}				t_hit_range;

typedef struct s_intersection
{
	bool		front_face;
	t_object	t_object;
	t_point		point;
	t_vector	normal;
	double		t;
}				t_intersection;

#endif
