/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_lines.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 21:28:16 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/02 13:03:43 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_LINES_H
# define PARSER_LINES_H

# include "./../parser.h"
# include "./../../camera/camera.h"
# include "./../../objects/objects.h"
# include "./../../transform/transform.h"

bool	parse_camera(t_rt_data *data, void	**argv);
bool	parse_sphere(t_rt_data *data, void	**args);
bool	parse_resolution(t_rt_data *data, void **argv);

#endif
