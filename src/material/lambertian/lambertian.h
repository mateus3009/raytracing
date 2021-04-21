/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lambertian.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 00:14:32 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/21 10:55:25 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LAMBERTIAN_H
# define LAMBERTIAN_H

# include "./../material.h"

typedef struct s_lambertian
{
	t_pixel	albedo;
}				t_lambertian;

t_material		lambertian(t_pixel albedo);
bool			lambertian_scatter(
					t_material material,
					t_ray r_in,
					t_intersection rec,
					t_pixel *attenuation,
					t_ray *scattered);

#endif
