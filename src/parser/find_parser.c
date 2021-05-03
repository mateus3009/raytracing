/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 19:55:39 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/03 18:12:12 by msales-a         ###   ########.fr       */
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
		.line_parser = NULL,
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
	{.id = "l",
		.argc = 3,
		.line_parser = NULL,
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
		.line_parser = NULL,
		.arg_parsers = (t_rt_arg_parser[]){
			parse_point,
			parse_vector,
			parse_double,
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
	{.id = "tr",
		.argc = 4,
		.line_parser = NULL,
		.arg_parsers = (t_rt_arg_parser[]){
			parse_point,
			parse_point,
			parse_point,
			parse_color}},
	NULL};

bool	find_parser(char *id, int argc, t_rt_parser *parser)
{
	t_rt_parser	*p;

	p = g_rt_parsers;
	while (p->arg_parsers)
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
