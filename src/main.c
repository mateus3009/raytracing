/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 19:58:25 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/08 20:28:07 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

void	all_canvas_to_bmp_(t_list *canvas, int index)
{
	char	*filename;

	if (canvas)
	{
		filename = get_output_name(index);
		if (filename)
		{
			canvas_to_bmp(*(t_canvas*)canvas->content, filename);
			free(filename);
			all_canvas_to_bmp_(canvas->next, index + 1);
		}
	}
}

void	all_canvas_to_bmp(t_list *canvas)
{
	all_canvas_to_bmp_(canvas, 0);
}

int	main(int argc, char **argv)
{
	t_display	display;
	t_list		*canvas;

	if (argc < 2)
		return (1);
	canvas = generate_canvas(argv[1], NULL);
	all_canvas_to_bmp(canvas);
	ft_lstclear(&canvas, canvas_destroy);
	return (0);
}
