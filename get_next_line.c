/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:21:22 by nghaddar          #+#    #+#             */
/*   Updated: 2017/01/18 19:23:05 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	clean_buffer(char **line, char *buffer)
{
	char	*tmp;
	int		n;

	n = ft_strclen(buffer, '\n');
	*line = ft_realloc((void **)line, n + 1);
	*line = ft_strncat(*line, buffer, n);
	tmp = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	ft_bzero(tmp, BUFF_SIZE + 1);
	tmp = ft_strcpy(tmp, ft_strchr(buffer, '\n') + 1);
	ft_bzero(buffer, BUFF_SIZE + 1);
	buffer = ft_strcpy(buffer, tmp);
	free(tmp);
}

int		get_next_line(int fd, char **line)
{
	static	char	buffer[BUFF_SIZE + 1];
	int				ret;

	if (fd < 0 || fd > 256)
		return (-1);
	if (*line)
		ft_bzero(*line, ft_strlen(*line));
	while (ft_strchr(buffer, '\n') == NULL)
	{
		*line = ft_realloc((void **)line, ft_strlen(buffer) + 1);
		*line = ft_strcat(*line, buffer);
		ft_bzero(buffer, BUFF_SIZE + 1);
		ret = read(fd, buffer, BUFF_SIZE);
		if (ret <= 0)
			return (ret == 0 ? 0 : 1);
		buffer[ret + 1] = '\0';
	}
	clean_buffer(line, buffer);
	return (1);
}

// int		main(int argc, char **argv)
// {
// 	char	*line;
// 	int		fd;
// 	int		ret;

// 	if (argc != 2)
// 	{
// 		ft_putstr("file you stoopid");
// 		return (-1);
// 	}
// 	fd = open(argv[1], O_RDONLY);
// 	ret = 42;
// 	while (ret > 0)
// 	{
// 		ret = get_next_line(fd, &line);
// 		ft_putstr(line);
// 	}
// 	return (0);
// }
