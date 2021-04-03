/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:11:45 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/03 10:13:43 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_tuple.h"

void	test_length_one(void)
{
	t_vector	a;
	double		magnitude;

	printf("%s\n", __func__);
	a = vector(1, 0, 0);
	magnitude = length(a);
	assert(magnitude == 1);
}

void	test_length_two(void)
{
	t_vector	a;
	double		magnitude;

	printf("%s\n", __func__);
	a = vector(0, 1, 0);
	magnitude = length(a);
	assert(magnitude == 1);
}

void	test_length_three(void)
{
	t_vector	a;
	double		magnitude;

	printf("%s\n", __func__);
	a = vector(0, 0, 1);
	magnitude = length(a);
	assert(magnitude == 1);
}

void	test_length_four(void)
{
	t_vector	a;
	double		magnitude;

	printf("%s\n", __func__);
	a = vector(1, 2, 3);
	magnitude = length(a);
	assert(magnitude == sqrt(14));
}

void	test_length_five(void)
{
	t_vector	a;
	double		magnitude;

	printf("%s\n", __func__);
	a = vector(-1, -2, -3);
	magnitude = length(a);
	assert(magnitude == sqrt(14));
}
