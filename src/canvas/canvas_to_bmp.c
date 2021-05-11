/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas_to_bmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 13:08:28 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/11 13:49:03 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

static void	write_bmp_header(t_canvas canvas,
	unsigned char *buffer,
	unsigned int file_size)
{
	buffer[0] = 'B';
	buffer[1] = 'M';
	buffer[2] = file_size;
	buffer[2] = file_size >> 8;
	buffer[2] = file_size >> 16;
	buffer[2] = file_size >> 24;
	buffer[10] = BMP_HEADER_SIZE + BMP_INFO_HEADER_SIZE;
}

static void	write_bmp_info_header(t_canvas canvas, unsigned char *buffer)
{
	buffer[0] = BMP_INFO_HEADER_SIZE;
	buffer[4] = canvas.width >> 0;
	buffer[5] = canvas.width >> 8;
	buffer[6] = canvas.width >> 16;
	buffer[7] = canvas.width >> 24;
	buffer[8] = canvas.height >> 0;
	buffer[9] = canvas.height >> 8;
	buffer[10] = canvas.height >> 16;
	buffer[11] = canvas.height >> 24;
	buffer[12] = 1;
	buffer[14] = 24;
}

static void	write_bmp_body(t_canvas canvas, unsigned char *buffer)
{
	unsigned int	row;
	unsigned int	column;
	t_pixel			pixel;

	row = 0;
	while (row < canvas.height)
	{
		column = canvas.width;
		while (column--)
		{
			pixel = get_pixel(canvas, canvas.width - 1 - column, row);
			buffer[2] = clamp(pixel.r * 255, 0, 255);
			buffer[1] = clamp(pixel.g * 255, 0, 255);
			buffer[0] = clamp(pixel.b * 255, 0, 255);
			buffer = buffer + 3;
		}
		row++;
	}
}

static void	bmp(t_canvas canvas, int fd)
{
	unsigned int	padding_size;
	unsigned int	file_size;
	unsigned char	*buffer;

	padding_size = (4 - ((canvas.width * 3) % 4)) % 4;
	file_size = BMP_HEADER_SIZE + BMP_INFO_HEADER_SIZE
		+ canvas.height * canvas.width * 3 + padding_size * canvas.height;
	buffer = ft_calloc(file_size, sizeof(unsigned char));
	write_bmp_header(canvas, buffer, file_size);
	write_bmp_info_header(canvas, buffer + BMP_HEADER_SIZE);
	write_bmp_body(canvas, buffer + BMP_HEADER_SIZE + BMP_INFO_HEADER_SIZE);
	if (write(fd, buffer, file_size * sizeof(unsigned char)) < 0)
		exit(EXIT_FAILURE);
	free(buffer);
}

void	canvas_to_bmp(t_canvas canvas, char *filename)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (fd <= 0)
		exit(EXIT_FAILURE);
	bmp(canvas, fd);
	close(fd);
}
