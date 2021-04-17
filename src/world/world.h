/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:39:41 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/16 21:34:45 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include "./../ray/ray.h"
# include "./../objects/objects.h"
# include "./../canvas/canvas.h"
# include "./../camera/camera.h"

bool	hit(t_ray ray, t_list *lst, t_intersection *rec);
void	render(t_camera camera, t_canvas canvas, t_list *lst);

#endif
