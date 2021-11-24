/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 08:47:12 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/24 14:51:47 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft/libft.h"

int	p_error(char *msg)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	return (0);
}
