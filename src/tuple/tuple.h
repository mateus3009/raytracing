/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:03:35 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/03 09:11:07 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_H
# define TUPLE_H

# include "./../util/util.h"

typedef union u_tuple
{
	struct
	{
		double	x;
		double	y;
		double	z;
		double	w;
	};
	struct
	{
		double	r;
		double	g;
		double	b;
		double	a;
	};
	double	value[4];
}				t_tuple;

typedef t_tuple	t_vector;

typedef t_tuple	t_point;

typedef t_tuple	t_pixel;

typedef t_tuple	t_quaternion;

t_tuple			tuple(double x, double y, double z, double w);
t_vector		vector(double x, double y, double z);
t_point			point(double x, double y, double z);
t_tuple			sum(t_tuple a, t_tuple b);
t_tuple			minus(t_tuple a, t_tuple b);
t_tuple			scalar(t_tuple a, double b);
t_tuple			negate(t_tuple a);
t_tuple			divide(t_tuple a, double b);
double			dot(t_tuple a, t_tuple b);
double			length(t_tuple a);
t_tuple			normalize(t_tuple a);
bool			tuple_equal(t_tuple a, t_tuple b);
t_vector		cross(t_vector a, t_vector b);
t_tuple			product(t_tuple a, t_tuple b);
t_vector		reflect(t_vector vector, t_vector normal);
t_pixel			pixel(double r, double g, double b);
t_tuple			clamp_tuple(t_tuple t, double min, double max);
t_tuple			random_tuple(void);
t_tuple			random_tuple_range(double min, double max);
t_vector		random_in_unit_sphere(void);
t_vector		random_unit_sphere(void);
t_vector		random_vector_in_unit_disk(void);
t_vector		random_in_hemispere(t_vector normal);
bool			near_zero(t_tuple t);
t_vector		refract(t_vector in, t_vector n, double ratio);
double			vectors_angle(t_vector a, t_vector b);
t_tuple			quaternion(double a, t_vector v);
void			print_tuple(t_tuple t);

#endif
