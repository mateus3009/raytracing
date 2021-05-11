/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_strtoken.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 22:30:33 by msales-a          #+#    #+#             */
/*   Updated: 2021/05/10 09:52:57 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	free_strtoken(char	***tokens, int argc)
{
	if (tokens && *tokens)
	{
		while (argc--)
			free((*tokens)[argc]);
		free(*tokens);
	}
}
