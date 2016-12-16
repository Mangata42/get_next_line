/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:21:22 by nghaddar          #+#    #+#             */
/*   Updated: 2016/12/16 20:35:00 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_buffer(int fd, char **line, char *buffer, int *ret)
{
	if (ft_strlen(buffer) == 0)
		*ret = read(fd, buffer, BUFF_SIZE);
	if (ft_strlen(buffer) == 0)
		return (0);
	while ((ft_strchr(buffer, '\n') == NULL) && *ret > 0)
	{
			*line = ext_mem_n_copy(line, buffer, BUFF_SIZE);
			ft_bzero(buffer, BUFF_SIZE);
			*ret = read(fd, buffer, BUFF_SIZE);
			check_buffer(fd, line, buffer, ret);
	}
	buffer = clean_buffer(line, buffer);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static	char	buffer[BUFF_SIZE];
	int				ret;

	ret = 42;
	*line = malloc(1);
	while ((fd > 0 && fd < 256) && ret > 0)
	{
		if (check_buffer(fd, line, buffer, &ret) == 1)
			return (1);
		else
			return (0);
	}
	return (-1);
}

int		main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		ret;

	if (argc != 2)
	{
		ft_putstr("file you stoopid");
		return (-1);
	}
	ret = 42;
	fd = open(argv[1], O_RDONLY);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		ft_putendl(line);
	}
	free(line);
	return (0);
}
