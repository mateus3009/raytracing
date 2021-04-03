/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite_tuple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 10:31:20 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/03 10:42:37 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./tests_tuple.h"
#include "./suite_tuple.h"

void	suite_tuple(void)
{
	t_test	*tests;

	printf("tuple\n\n");
	tests = (t_test[]){
		test_cross_one,
		test_cross_two,
		test_divide,
		test_dot,
		test_length_one,
		test_length_two,
		test_length_three,
		test_length_four,
		test_length_five,
		test_minus_one,
		test_minus_two,
		test_minus_three,
		test_negate,
		test_normalize_one,
		test_normalize_two,
		test_normalize_three,
		test_point_one,
		test_point_two,
		test_scalar_one,
		test_scalar_two,
		test_sum_one,
		test_sum_two,
		test_tuple_one,
		test_tuple_two,
		test_vector_one,
		test_vector_two,
		NULL};
	execute_tests(tests);
}
