/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 22:17:41 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/09 22:36:16 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static bool	has_rt_extension(char *filename)
{
	size_t	len;

	len = ft_strlen(filename);
	if (len < 3)
		return (false);
	return (!ft_strcmp(".rt", filename + len - 3)
		|| !ft_strcmp(".RT", filename + len - 3));
}

static void	clean_rt_data_and_exit(t_rt_data *data, int index)
{
	ft_lstclear(&data->cameras, free);
	ft_lstclear(&data->objects, free);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	ft_putstr_fd("Failed to convert line: ", STDERR_FILENO);
	ft_putnbr_fd(index, STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
}

static bool	process_lines(int fd, t_rt_data *data)
{
	int		index;
	int		status;
	char	*line;

	index = 1;
	while (true)
	{
		status = get_next_line(fd, &line);
		if (status < 0)
		{
			clean_rt_data_and_exit(data, index);
			return (false);
		}
		if (!process_line(data, line))
		{
			clean_rt_data_and_exit(data, index);
			free(line);
			return (false);
		}
		free(line);
		if (!status)
			return (true);
		index++;
	}
}

void	rt_init(t_rt_data *data)
{
	ft_bzero(data, sizeof(t_rt_data));
	data->samples = 1;
	data->depth = 1;
	data->threads = 1;
}

bool	process_file(char *filename, t_rt_data *data)
{
	int		fd;
	char	*line;

	if (!filename)
		return (false);
	if (!has_rt_extension(filename))
		return (false);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (false);
	rt_init(data);
	return (process_lines(fd, data));
}
