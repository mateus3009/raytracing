/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fatal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 22:19:07 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/30 18:46:15 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	fatal(char	*msg)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	if (msg)
	{
		ft_putstr_fd(msg, STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
	}
	exit(EXIT_FAILURE);
}
