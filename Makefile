# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 21:27:33 by nghaddar          #+#    #+#              #
#    Updated: 2016/12/14 21:30:37 by nghaddar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line
SRCS = get_next_line.c \
		ext_fct.c

$(NAME):
	@gcc $(SRCS) -L ./libft -l ft -o $(NAME)

clean:
	@rm $(NAME)

re: clean all

all: $(NAME)
