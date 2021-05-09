/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_canvas_to_bmp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 22:15:57 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 15:06:41 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

static char	*get_output_name(int index)
{
	char	*number;
	char	*prefix;
	char	*suffix;

	number = ft_itoa(index);
	if (!number)
		return (NULL);
	prefix = ft_strjoin("output_", number);
	if (!prefix)
	{
		free(number);
		return (NULL);
	}
	suffix = ft_strjoin(prefix, ".bmp");
	free(number);
	free(prefix);
	return (suffix);
}

static void	all_canvas_to_bmp_(t_list *canvas, int index)
{
	char	*filename;

	if (canvas)
	{
		filename = get_output_name(index);
		if (filename)
		{
			canvas_to_bmp(*(t_canvas *)canvas->content, filename);
			free(filename);
			all_canvas_to_bmp_(canvas->next, index + 1);
		}
	}
}

void	all_canvas_to_bmp(t_list *canvas)
{
	all_canvas_to_bmp_(canvas, 0);
}
