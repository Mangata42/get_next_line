/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_fct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 21:26:37 by nghaddar          #+#    #+#             */
/*   Updated: 2016/12/16 20:16:04 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_strclen(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	return (i);
}

char		*ext_mem_n_copy(char **dst, char *src, int size)
{
	char	*ret;
	int		i;
	int		y;

	y = -1;
	ret = (char *)malloc(sizeof(char) * ft_strlen(*dst) + size + 1);
	ret = ft_memset(ret, '\0', ft_strlen(*dst) + size + 1);
	ret = ft_strcpy(ret, *dst);
	i = ft_strlen(ret);
	while (src[++y] != '\0')
		ret[i + y] = src[y];
	free(*dst);
	return (ret);
}

char	*clean_buffer(char **line, char *buffer)
{
	char	*ext;
	int		i;
	int		y;

	ext = (char *)malloc(sizeof(char) * ft_strlen(buffer) + 1);
	ext = ft_memset(ext, '\0', ft_strlen(buffer) + 1);
	i = -1;
	y = -1;
	while (buffer[++i] != '\n')
		ext[++y] = buffer[i];
	*line = ext_mem_n_copy(line,  ext, ft_strlen(ext));
	y = -1;
	ext = ft_memset(ext, '\0', ft_strlen(buffer) + 1);
	while (buffer[++i] != '\0')
		ext[++y] = buffer[i];
	ft_bzero(buffer, ft_strlen(buffer));
	buffer = ft_strcpy(buffer, ext);
	free(ext);
	return (buffer);
}
