/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ext_fct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 21:26:37 by nghaddar          #+#    #+#             */
/*   Updated: 2017/01/11 13:50:29 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	return (NULL);
}