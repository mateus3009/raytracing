/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metal.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 00:14:32 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/06 08:40:21 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	METAL_H
# define METAL_H

# include "./../material.h"

typedef struct s_metal
{
	double	fuzz;
}				t_metal;

t_material		metal(t_pixel color, double fuzz);
bool			metal_scatter(
					t_material material,
					t_ray r_in,
					t_intersection rec,
					t_pixel *attenuation,
					t_ray *scattered);

#endif
