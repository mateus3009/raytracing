/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_struct.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 11:24:35 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/06 21:06:04 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_STRUCT_H
# define MATERIAL_STRUCT_H

# include "./../tuple/tuple.h"
# include "./../ray/ray.h"

struct s_job;
struct s_intersection;
struct s_scatter_params;

typedef struct s_intersection	t_intersection;
typedef struct s_scatter_params	t_scatter_params;
typedef struct s_job			t_job;

typedef struct s_material
{
	void	*data;
	t_pixel	color;
	bool	(*scatter)(t_scatter_params params);
}								t_material;

typedef struct s_scatter_params
{
	t_job			*job;
	t_material		material;
	t_ray			ray;
	t_intersection	*record;
	t_pixel			*attenuation;
	t_ray			*scattered;
}								t_scatter_params;

#endif
