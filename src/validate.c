/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:26:06 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/25 13:54:17 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include "texture.h"
#include "config.h"
#include "libft/libft.h"
#include "parser.h"

bool	valid_rgb(char *str)
{
	int32_t	i;
	int32_t	j;
	int32_t	num;
	char	**rgb;

	str++;
	rgb = ft_split(str, ',');
	i = -1;
	while (rgb[++i])
	{
		j = 0;
		while (rgb[i][j])
		{
			while (rgb[i][j] == ' ')
				j++;
			if (!ft_isdigit(rgb[i][j]))
				return (false);
			j++;
		}
		num = ft_atoi(rgb[i]);
		if (num < 0 || num > 255 || ft_strarr_size(rgb) < 3)
			return (false);
	}
	return (true);
}

bool	valid_file_ext(char *file, char *ext)
{
	size_t	len;
	size_t	ext_len;

	ext_len = ft_strlen(ext);
	len = ft_strlen(file);
	if (len <= ext_len)
		return (false);
	if (!ft_strncmp(file + len - ext_len, ext, ext_len + 1))
		return (true);
	return (false);
}

bool	valid_identifier(char *str)
{
	if (!ft_strncmp(str, "NO ", 3))
		return (true);
	else if (!ft_strncmp(str, "SO ", 3))
		return (true);
	else if (!ft_strncmp(str, "WE ", 3))
		return (true);
	else if (!ft_strncmp(str, "EA ", 3))
		return (true);
	else if (!ft_strncmp(str, "C ", 2))
		return (true);
	else if (!ft_strncmp(str, "F ", 2))
		return (true);
	return (false);
}

bool	no_missing_texture(char **tab)
{
	int32_t	i;
	int32_t	count;
	int32_t size;

	count = 0;
	i = 0;
	size = ft_strarr_size(tab);
	while (i < size)
	{
		if (valid_identifier(tab[i]))
			count++;
		i++;
	}
	if (count == size)
		return (true);
	return (p_error("Error: Texture Missing"));
}

bool	duplicate_identifier(char **info)
{
	char	*str;
	int32_t	i;
	int32_t	j;
	int32_t	size;

	i = 0;
	size = ft_strarr_size(info);
	while (i < size)
	{
		j = i + 1;
		str = ft_substr(info[i], 0, 3);
		while (info[j])
		{
			if (!ft_strncmp(info[j], str, 3))
			{
				free(str);
				return (p_error("Error: Duplicate Identifier Found"));
			}
			j++;
		}	
		free(str);
		i++;
	}
	return (true);
}
