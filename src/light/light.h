/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:06:48 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/20 21:52:41 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "./../tuple/tuple.h"
# include "./../material/material.h"
# include "./../objects/objects.h"

typedef struct s_light
{
	t_pixel	intensity;
	t_point	origin;
}				t_light;

t_light			light(
					t_pixel intensity,
					t_point origin);
t_pixel			lighting(
					t_light light,
					t_intersection hit);

#endif
