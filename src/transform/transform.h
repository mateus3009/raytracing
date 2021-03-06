/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 09:15:44 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/03 16:56:16 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
# define TRANSFORM_H

# include "./../util/util.h"
# include "./../matrix/matrix.h"

typedef struct s_shearing
{
	double	xy;
	double	xz;
	double	yx;
	double	yz;
	double	zx;
	double	zy;
}				t_shearing;

t_matrix	translate(double x, double y, double z);
t_matrix	scaling(double x, double y, double z);
t_matrix	rotatex(double radians);
t_matrix	rotatey(double radians);
t_matrix	rotatez(double radians);
t_matrix	shearing(t_shearing p);
t_matrix	rotation_quaternion(t_quaternion q);
t_matrix	rotatexyz(double x, double y, double z);
t_matrix	from_to_rotation(t_vector a, t_vector b);

#endif
