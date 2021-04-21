/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   metal.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 00:14:32 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/21 12:16:10 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	METAL_H
# define METAL_H

# include "./../material.h"

typedef struct s_metal
{
	t_pixel	albedo;
	double	fuzz;
}				t_metal;

t_material		metal(t_pixel albedo, double fuzz);
bool			metal_scatter(
					t_material material,
					t_ray r_in,
					t_intersection rec,
					t_pixel *attenuation,
					t_ray *scattered);

#endif
