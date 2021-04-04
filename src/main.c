/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 19:58:25 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/03 20:49:50 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(void)
{
	t_matrix	a;
	t_matrix	b;
	t_matrix	c;
	t_matrix	i;

	a = (t_matrix){.size = 4,
		.values = {
			{3,		-9,	7,	3},
			{3,		-8,	2,	-9},
			{-4,	4,	4,	1},
			{-6,	5,	-1,	1}}};
	b = (t_matrix){.size = 4,
		.values = {
			{8,	2,	2,	2},
			{3,	-1,	7,	0},
			{7,	0,	5,	4},
			{6,	-2,	0,	5}}};
	c = matrix_multiply(a, b);
	i = matrix_invert(a);
	matrix_print(matrix_multiply(b, matrix_invert(b)));
	return (0);
}
