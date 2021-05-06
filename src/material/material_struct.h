/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_struct.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:24:35 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/05 21:03:46 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_STRUCT_H
# define MATERIAL_STRUCT_H

# include "./../tuple/tuple.h"
# include "./../ray/ray.h"

struct s_intersection;

typedef struct s_intersection	t_intersection;

typedef struct s_material
{
	void	*data;
	t_pixel	color;
	bool	(*scatter)(
			struct s_material material,
			t_ray r_in,
			t_intersection rec,
			t_pixel *attenuation,
			t_ray *scattered);
}								t_material;

#endif
