/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:21:22 by nghaddar          #+#    #+#             */
/*   Updated: 2017/01/11 18:23:29 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 

	Les leaks viennent probablement du fait que *line est malloc à chaque fois que l'on fait appel à GNL. 
	Il faudrait peut-être créer un tmp qui récupérerait la ligne à copier ensuite dans line, puis qui
	serait free(), évitant éventuellement les différentes leaks et le malloc(1) de *line, qui sert à ne pas faire
	segfault le strlen quand *line n'est pas encore malloc().

	À voir ... 

	P.S. 1 : Le fait de vérifier l'existence de *line et de le malloc en conséquence semble corriger certaines leaks, 
	il reste maintenant à le tester en conditions réelles avec un clean_buffer() fonctionnel.

	P.S. 2 : Nope, ça segfault en temps normal.

*/

#include "get_next_line.h"

char	*clean_buffer(char **line, char *buffer)
{
	char	*tmp;
	int		i;

	tmp = (char *)malloc(sizeof(char) * BUFF_SIZE + 1);
	i = -1;
	while (buffer[++i] != '\n')
		tmp[i] = buffer[i];
	tmp[i] = '\0';
	*line = ft_realloc((void **)line, ft_strlen(tmp) + 1);
	*line = ft_strcat(*line, tmp);
	ft_bzero(tmp, BUFF_SIZE + 1);
	tmp = ft_strcpy(tmp, ft_strchr(buffer, '\n') + 1);
	ft_bzero(buffer, BUFF_SIZE + 1);
	buffer = ft_strcpy(buffer, tmp);
	free(tmp);
	return (buffer);
}

int		check_buffer(int fd, char **line, char *buffer)
{
	int	ret;

	if (ft_strlen(buffer) == 0)
		ret = read(fd, buffer, BUFF_SIZE);
	while ((ft_strchr(buffer, '\n') == NULL) && ret > 0)
	{
		*line = ft_realloc((void **)line, ret + 1);
		*line = ft_strcat(*line, buffer);
		ft_bzero(buffer, BUFF_SIZE + 1);
		ret = read(fd, buffer, BUFF_SIZE);
	}
	if (ret < 0)
		return (-1);
	if (ft_strlen(buffer) == 0 && ret == 0)
		return (0);
	buffer = clean_buffer(line, buffer);
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static	char	buffer[BUFF_SIZE + 1];

	*line = malloc(1);
	while (fd > 0 && fd < 256)
	{
		if (check_buffer(fd, line, buffer) == 1)
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

