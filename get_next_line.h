/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 19:52:43 by nghaddar          #+#    #+#             */
/*   Updated: 2016/12/16 18:59:55 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "./libft/libft.h"

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# define BUFF_SIZE 64

int						get_next_line(const int fd, char **line);
int						ft_strclen(char *str, char c);
char					*ext_mem_n_copy(char **dst, char *src, int size);
char					*clean_buffer(char **line, char *buffer);
int						check_buffer(int fd, char **line, char *buffer,
							int *ret);

#endif
