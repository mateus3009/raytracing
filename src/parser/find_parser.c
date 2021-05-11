/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 19:55:39 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/11 16:54:28 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_rt_parser	*g_rt_parsers = (t_rt_parser[]){
	{.id = "R",
		.argc = 2,
		.line_parser = parse_resolution,
		.arg_parsers = (t_rt_arg_parser[]){
			parse_int,
			parse_int}},
	{.id = "A",
		.argc = 2,
		.line_parser = parse_ambient,
		.arg_parsers = (t_rt_arg_parser[]){
			parse_double,
			parse_color}},
	{.id = "c",
		.argc = 3,
		.line_parser = parse_camera,
		.arg_parsers = (t_rt_arg_parser[]){
			parse_point,
			parse_vector,
			parse_double}},
	{.id = "c",
		.argc = 5,
		.line_parser = parse_camera_complete,
		.arg_parsers = (t_rt_arg_parser[]){
			parse_point,
			parse_point,
			parse_vector,
			parse_double,
			parse_double}},
	{.id = "l",
		.argc = 3,
		.line_parser = parse_light,
		.arg_parsers = (t_rt_arg_parser[]){
			parse_point,
			parse_double,
			parse_color}},
	{.id = "sp",
		.argc = 3,
		.line_parser = parse_sphere,
		.arg_parsers = (t_rt_arg_parser[]){
			parse_point,
			parse_double,
			parse_color}},
	{.id = "pl",
		.argc = 3,
		.line_parser = parse_plane,
		.arg_parsers = (t_rt_arg_parser[]){
			parse_point,
			parse_vector,
			parse_color}},
	{.id = "sq",
		.argc = 4,
		.line_parser = parse_square,
		.arg_parsers = (t_rt_arg_parser[]){
			parse_point,
			parse_vector,
			parse_double,
			parse_color}},
	{.id = "cb",
		.argc = 4,
		.line_parser = parse_cube,
		.arg_parsers = (t_rt_arg_parser[]){
			parse_point,
			parse_vector,
			parse_double,
			parse_color}},
	{.id = "dk",
		.argc = 4,
		.line_parser = parse_disk,
		.arg_parsers = (t_rt_arg_parser[]){
			parse_point,
			parse_vector,
			parse_double,
			parse_color}},
	{.id = "cy",
		.argc = 6,
		.line_parser = parse_cylinder_capped,
		.arg_parsers = (t_rt_arg_parser[]){
			parse_point,
			parse_vector,
			parse_double,
			parse_double,
			parse_int,
			parse_color}},
	{.id = "cy",
		.argc = 5,
		.line_parser = parse_cylinder,
		.arg_parsers = (t_rt_arg_parser[]){
			parse_point,
			parse_vector,
			parse_double,
			parse_double,
			parse_color}},
	{.id = "cn",
		.argc = 5,
		.line_parser = parse_cone,
		.arg_parsers = (t_rt_arg_parser[]){
			parse_point,
			parse_vector,
			parse_double,
			parse_double,
			parse_color}},
	{.id = "cn",
		.argc = 5,
		.line_parser = parse_cone_capped,
		.arg_parsers = (t_rt_arg_parser[]){
			parse_point,
			parse_vector,
			parse_double,
			parse_double,
			parse_int,
			parse_color}},
	{.id = "tr",
		.argc = 4,
		.line_parser = parse_triangle,
		.arg_parsers = (t_rt_arg_parser[]){
			parse_point,
			parse_point,
			parse_point,
			parse_color}},
	{.id = "BGC",
		.argc = 1,
		.line_parser = parse_bgc,
		.arg_parsers = (t_rt_arg_parser[]){
			parse_color}},
	{.id = "DP",
		.argc = 1,
		.line_parser = parse_depth,
		.arg_parsers = (t_rt_arg_parser[]){
			parse_int}},
	{.id = "TH",
		.argc = 1,
		.line_parser = parse_thread,
		.arg_parsers = (t_rt_arg_parser[]){
			parse_int}},
	{.id = "AA",
		.argc = 1,
		.line_parser = parse_samples,
		.arg_parsers = (t_rt_arg_parser[]){
			parse_int}},
	{.id = "lambertian",
		.argc = 1,
		.line_parser = parse_lambertian,
		.arg_parsers = (t_rt_arg_parser[]){
			parse_color}},
	{.id = "metal",
		.argc = 2,
		.line_parser = parse_metal,
		.arg_parsers = (t_rt_arg_parser[]){
			parse_color,
			parse_double}},
	{.id = "dielectric",
		.argc = 2,
		.line_parser = parse_dielectric,
		.arg_parsers = (t_rt_arg_parser[]){
			parse_color,
			parse_double}},
	{.id = "rxyz",
		.argc = 3,
		.line_parser = parse_rotation,
		.arg_parsers = (t_rt_arg_parser[]){
			parse_double,
			parse_double,
			parse_double}},
	{.id = "rq",
		.argc = 2,
		.line_parser = parse_quaternion,
		.arg_parsers = (t_rt_arg_parser[]){
			parse_double,
			parse_vector}},
	{.id = "rainbow",
		.argc = 0,
		.line_parser = parse_rainbow,
		.arg_parsers = (t_rt_arg_parser[]){
			NULL}},
	NULL};

bool	find_parser(char *id, int argc, t_rt_parser *parser)
{
	t_rt_parser	*p;

	p = g_rt_parsers;
	while (p->id)
	{
		if (!ft_strcmp(p->id, id) && p->argc == argc - 1)
		{
			*parser = *p;
			return (true);
		}
		p++;
	}
	return (false);
}
