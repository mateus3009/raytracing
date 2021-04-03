/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:11:45 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/03 10:13:30 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests_tuple.h"

void	test_dot(void)
{
	t_tuple	a;
	t_tuple	b;
	double	result;

	printf("%s\n", __func__);
	a = vector(1, 2, 3);
	b = vector(2, 3, 4);
	result = dot(a, b);
	assert(result == 20);
}
