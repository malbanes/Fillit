# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malbanes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/20 18:02:04 by malbanes          #+#    #+#              #
#    Updated: 2016/12/08 13:42:32 by malbanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fillit

SRC =	ft_removetetri.c ft_sqrtSup.c ft_setalpha.c struct_test.c\
		ft_placetetri.c ft_setmap.c open.c ft_rangetetri.c\
		ft_splitetri.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) libft.a

$(OBJ) : $(SRC)
	gcc -c $(FLAGS) $(SRC)

clean :
	/bin/rm -f $(OBJ)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
