# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MakefileModulaire                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malbanes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/02 14:32:16 by malbanes          #+#    #+#              #
#    Updated: 2016/12/02 16:58:49 by malbanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = src

SRC_NAME =	ft_rangetetri.c\
			ft_setmap.c\
			ft_splitetri.c\
			ft_placetetri.c\
			ft_removetetri.c\
			ft_setalpha.c\
			open.c

OBJ_PATH = obj

CPPFLAGS = -Iinclude

LDFLAGS = -Llibft

LDLIBS = -lft

LIB = libft.h

NAME = Fillit

CC = gcc

CFLAGS = -Werror -Wall -Wextra

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o Fillit

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true

$(OBJ):
	$(CC) $(CFLAGS) $(SRC) -c 

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	rm -fv $(NAME)

re: fclean all
