/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 13:00:45 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/11 08:47:37 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser_lines.h"

bool	parse_thread(t_rt_data *data, void **argv)
{
	int	thread;

	thread = *(int *)argv[0];
	if (thread < 1)
		return (false);
	data->threads = thread;
	if (thread > 4)
		data->threads = 4;
	return (true);
}
