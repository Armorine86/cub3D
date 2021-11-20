/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmondell <mmondell@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 09:32:09 by mmondell          #+#    #+#             */
/*   Updated: 2021/11/20 10:57:27 by mmondell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/libft.h>
#include <stdint.h>
#include <stdlib.h>
#include <mlx.h>

char	**extract_tex_data(int fd)
{
	int32_t	ret;
	char	**paths;
	char	*str;

	paths = ft_calloc(1, sizeof(char *));
	ret = 1;
	while (ret)
	{
		ret = get_next_line(fd, &str);
		if (ret == -1)
		{
			ft_strarr_free(paths);
			return (NULL);
		}
		if (str[0] == '\0')
		{
			free(str);
			continue ;
		}
		paths = ft_strarr_extend(paths, str);
		if (ft_strarr_size(paths) == 6)
			break ;
	}
	return (paths);
}
