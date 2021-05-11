/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_lines.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 21:28:16 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/11 16:53:40 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_LINES_H
# define PARSER_LINES_H

# include "./../parser.h"
# include "./../../camera/camera.h"
# include "./../../objects/objects.h"
# include "./../../transform/transform.h"

bool	parse_camera(t_rt_data *data, void **argv);
bool	parse_sphere(t_rt_data *data, void **args);
bool	parse_plane(t_rt_data *data, void **args);
bool	parse_cube(t_rt_data *data, void **args);
bool	parse_cylinder(t_rt_data *data, void **args);
bool	parse_resolution(t_rt_data *data, void **argv);
bool	parse_ambient(t_rt_data *data, void **argv);
bool	parse_square(t_rt_data *data, void **args);
bool	parse_disk(t_rt_data *data, void **args);
bool	parse_triangle(t_rt_data *data, void **args);
bool	parse_cone(t_rt_data *data, void **args);
bool	parse_camera_complete(t_rt_data *data, void	**argv);
bool	parse_thread(t_rt_data *data, void **argv);
bool	parse_samples(t_rt_data *data, void **argv);
bool	parse_depth(t_rt_data *data, void **argv);
bool	parse_bgc(t_rt_data *data, void **argv);
bool	parse_light(t_rt_data *data, void **args);
bool	parse_metal(t_rt_data *data, void **argv);
bool	parse_lambertian(t_rt_data *data, void **argv);
bool	parse_dielectric(t_rt_data *data, void **argv);
bool	parse_quaternion(t_rt_data *data, void **argv);
bool	parse_rotation(t_rt_data *data, void **argv);
bool	parse_cylinder_capped(t_rt_data *data, void	**args);
bool	parse_rainbow(t_rt_data *data, void	**args);
bool	parse_cone_capped(t_rt_data *data, void **args);

#endif
