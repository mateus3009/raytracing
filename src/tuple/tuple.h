/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:03:35 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/15 20:51:56 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLE_H
# define TUPLE_H

# include "./../util.h"

typedef struct u_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}				t_tuple;

typedef t_tuple	t_vector;

typedef t_tuple	t_point;

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

#endif
