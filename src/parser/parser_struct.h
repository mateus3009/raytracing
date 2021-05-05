/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 19:47:43 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/05 17:16:01 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_STRUCT_H
# define PARSER_STRUCT_H

# include "./../util/util.h"
# include "./../tuple/tuple.h"

typedef struct s_resolution
{
	unsigned int	width;
	unsigned int	height;
}				t_resolution;

typedef struct s_ambient_light
{
	double	ratio;
	t_pixel	color;
}				t_ambient_light;

typedef struct s_samples_pixel
{
	int	min;
	int	max;
}				t_samples_pixel;

typedef struct s_rt_data
{
	t_resolution	resolution;
	t_ambient_light	ambient;
	t_samples_pixel	samples;
	int				depth;
	t_list			*cameras;
	int				cameras_count;
	t_list			*objects;
	int				threads;
}				t_rt_data;

typedef bool	(*t_rt_arg_parser)(char *in, void **result);
typedef bool	(*t_rt_line_parser)(t_rt_data *data, void **args);

typedef struct s_rt_parser
{
	char				*id;
	int					argc;
	t_rt_arg_parser		*arg_parsers;
	t_rt_line_parser	line_parser;
}				t_rt_parser;

#endif
