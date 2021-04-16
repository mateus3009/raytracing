/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 22:01:08 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/16 08:31:37 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "./../tuple/tuple.h"
# include "./../matrix/matrix.h"

typedef struct s_ray
{
	t_point		origin;
	t_vector	direction;
}				t_ray;

t_ray			ray(t_point origin, t_vector direction);
t_point			ray_at(t_ray ray, double t);
t_ray			transform_ray(t_ray r, t_matrix matrix);

#endif
