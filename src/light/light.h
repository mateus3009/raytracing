/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:06:48 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/07 21:27:46 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIGHT_H
# define LIGHT_H

# include "./../tuple/tuple.h"
# include "./../material/material.h"
# include "./../objects/objects.h"

typedef struct s_light
{
	t_pixel	color;
	t_point	origin;
}				t_light;

bool	light(t_light **light, double brightness, t_pixel color, t_point origin);

#endif
