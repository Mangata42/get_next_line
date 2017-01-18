/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:21:22 by nghaddar          #+#    #+#             */
/*   Updated: 2017/01/18 10:29:36 by Mangata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		new_buffer(char **line, char *buffer)
{
	*line = (char *)malloc(sizeof(char) * ft_strlen(buffer) + 1);
	ft_bzero(*line, ft_strlen(buffer) + 1);
	if (ft_strchr(buffer, '\n') == NULL)
	{
		// *line = ft_realloc((void **)line, ft_strlen(buffer) + 1)
		*line = ft_strcat(*line, buffer);
		ft_bzero(buffer, BUFF_SIZE + 1);
	}
	if (ft_strchr(buffer, '\n') != NULL)
	{
		clean_buffer(line, buffer);
		return (1);
	}
	return (0);
}

void	clean_buffer(char **line, char *buffer)
{
	char	*tmp;
	int		n;

	n = ft_strclen(buffer, '\n');
	*line = ft_realloc((void **)line, n + 1);
	*line = ft_strncat(*line, buffer, n);
	if (!(tmp = (char *)malloc(sizeof(char) * ft_strlen(ft_strchr(buffer, '\n') + 1))))
		return ;
	tmp = ft_strcpy(tmp, ft_strchr(buffer, '\n') + 1);
	ft_bzero(buffer, BUFF_SIZE + 1);
	buffer = ft_strcpy(buffer, tmp);
	free(tmp);
}

int		get_next_line(int fd, char **line)
{
	static char		buffer[BUFF_SIZE + 1];
	int				ret;

	 *line = malloc(1);
	if (ft_strlen(buffer) != 0)
		if (new_buffer(line, buffer) == 1)
			return (1);
	while (fd > 0 && fd < 256)
	{
		ret = read(fd, buffer, BUFF_SIZE);
		if (ret == 0 || ret == -1)
			return ((ret == 0) ? 0 : -1);
		buffer[ret + 1] = '\0';
		if (ft_strchr(buffer, '\n') != NULL)
		{
			clean_buffer(line, buffer);
			return (1);
		}
		*line = ft_realloc((void **)line, ft_strlen(buffer) + 1);
		*line = ft_strcat(*line, buffer);
		ft_bzero(buffer, BUFF_SIZE + 1);
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
