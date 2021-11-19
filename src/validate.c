/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:26:06 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/18 14:42:46 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/libft.h>
#include <stdint.h>
#include <fcntl.h>
#include <stdlib.h>
#include <mlx.h>
#include "game.h"

bool	valid_extension(char *file, char *ext)
{
	size_t	len;
	size_t	ext_len;

	ext_len = ft_strlen(ext);
	len = ft_strlen(file);
	if (len <= ext_len)
		return(false);
	if (!ft_strncmp(file + len - ext_len, ext, ext_len))
		return (true);
	return (false);
}

bool	missing_texture(char **tab)
{
	int32_t	i;
	int32_t count;

	count = 0;
	i = 0;
	while (i < 6)
	{
		if (!ft_strncmp(tab[i], "NO", 2) || !ft_strncmp(tab[i], "SO", 2)
			|| !ft_strncmp(tab[i], "EA", 2) || !ft_strncmp(tab[i], "WE", 2)
			||	!ft_strncmp(tab[i], "C", 1) || !ft_strncmp(tab[i], "F", 1))
			count++;
		i++;
	}
	if (count == 6)
		return (false);
	return (true);
}

bool	duplicate_identifier(char **info)
{
	char	*str;
	int32_t	i;
	int32_t	j;

	i = 0;
	if (missing_texture(info))
		return (false);
	while (info[i])
	{
		j = i + 1;
		str = ft_substr(info[i], 0, 2);
		while (info[j])
		{
			if (!ft_strncmp(info[j], str, 2))
			{
				free(str);
				return (false);
			}
			j++;
		}	
		i++;
	}
	return (true);
}
