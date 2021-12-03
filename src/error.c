/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 08:47:12 by mmondell          #+#    #+#             */
/*   Updated: 2021/12/03 04:44:34 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <libft/libft.h>

bool	p_index(char *msg, int i, int j)
{
	char	*line;
	char	*index;

	index = ft_ltoa(j);
	line = ft_ltoa(i);
	ft_putendl_fd(msg, STDERR_FILENO);
	ft_putstr_fd("Line: ", STDERR_FILENO);
	ft_putstr_fd(line, STDERR_FILENO);
	ft_putstr_fd(" Index: ", STDERR_FILENO);
	ft_putendl_fd(index, STDERR_FILENO);
	free(index);
	free(line);
	return (false);
}

bool	p_error(char *msg)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	return (false);
}
