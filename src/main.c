/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 19:58:25 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/03 09:13:34 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_vector		a;
	t_vector		b;
	t_vector		c;
	double			r;
	t_quaternion	q;
	t_matrix		m;
	t_vector		p;

	a = vector(0, 1, 0);
	printf("a\n");
	print_tuple(a);
	printf("\n");

	b = matrix_product(rotatez(degrees_to_radians(90)), a);
	printf("b\n");
	print_tuple(b);
	printf("\n");

	c = cross(a, b);
	printf("c\n");
	print_tuple(c);
	printf("\n");

	r = vectors_angle(a, b);
	printf("r: %f\n\n", radians_to_degrees(r));

	q = quaternion(r, normalize(c));
	printf("q\n");
	print_tuple(q);
	printf("\n");

	m = rotation_quaternion(q);
	p = matrix_product(m, a);
	printf("p\n");
	print_tuple(p);
	printf("\n");

	printf("%d\n", tuple_equal(p, b));
	/*
	t_rt_data	rt;

	if (argc < 2)
		return (false);
	rt.resolution.width = 0;
	rt.resolution.height = 0;
	rt.cameras = NULL;
	rt.objects = NULL;
	process_file(argv[1], &rt); */
	return (EXIT_SUCCESS);
}
