/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suite_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 12:09:56 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/03 12:37:42 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./tests_camera.h"

void	suite_camera(void)
{
	t_test *tests;

	printf("\ncamera\n\n");
	tests = (t_test[]){
		test_canvas_init,
		NULL};
	execute_tests(tests);
}
