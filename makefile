# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malbanes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/20 18:02:04 by malbanes          #+#    #+#              #
#    Updated: 2017/01/06 17:52:32 by malbanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC =	ft_deplacetetri.c ft_sqrtsup.c ft_setalpha.c struct_test.c\
		ft_placetetri.c ft_setmap.c fillit.c ft_rangetetri.c\
		ft_splitetri.c parseur.c fctlib.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ)

$(OBJ) : $(SRC)
	gcc -c $(FLAGS) $(SRC)

clean :
	/bin/rm -f $(OBJ)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
