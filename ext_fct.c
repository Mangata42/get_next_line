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

void		*ft_realloc(void **dst, int size)
{
	char	*ret;
	char	*c_dst;

	c_dst = *dst;
	if (!(ret = (char *)malloc(sizeof(char) * ft_strlen(c_dst) + size)))
		return (NULL);
	ret = ft_memset(ret, '\0', ft_strlen(c_dst) + size);
	ret = ft_strcpy(ret, c_dst);
	// free(c_dst);
	return ((void *)ret);
}

char	*clean_buffer(char **line, char *buffer)
{
	char	*tmp;
	int		n;

	n = ft_strclen(buffer, '\n');
	tmp = (char *)malloc(sizeof(char) * ft_strlen(buffer + n + 1));
	tmp = ft_strcpy(tmp, buffer  + (n + 1));
	*line = ft_realloc((void **)line, n + 1);
	*line = ft_strncat(*line, buffer, n);
	ft_bzero(buffer, BUFF_SIZE);
	buffer = ft_strcpy(buffer, tmp);
	free(tmp);
}