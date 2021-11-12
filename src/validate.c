/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 14:26:06 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/12 15:36:32 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/libft.h>
#include <stdint.h>
#include <fcntl.h>
#include <stdlib.h>
#include <mlx.h>
#include "game.h"

bool	missing_texture(char **tab)
{
	if ((ft_strarr_size(tab)) < 4)
		return (true);
	return (false);
}

bool	duplicate_identifier(char *info)
{
	char	*str;
	char	**tab;
	int32_t	i;
	int32_t	j;

	tab = extract_texture_path(info);
	if (missing_texture(tab))
		return (false);
	i = 0;
	while (tab[i])
	{
		j = i + 1;
		str = ft_substr(tab[i], 0, 2);
		while (tab[j])
		{
			if (!ft_strncmp(tab[j], str, 2))
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
