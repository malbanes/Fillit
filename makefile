# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malbanes <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/20 18:02:04 by malbanes          #+#    #+#              #
#    Updated: 2017/01/04 16:52:24 by malbanes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC =	ft_removetetri.c ft_sqrtSup.c ft_setalpha.c struct_test.c\
		ft_placetetri.c ft_setmap.c open.c ft_rangetetri.c\
		ft_splitetri.c proto_place.c parseur.c fctlib.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	gcc $(FLAGS) -o $(NAME) $(OBJ) libft.a
	@echo "                         :.              "
	@echo "                        '.,+\`             "
	@echo "                   \`  ':+,.,,,#            "
	@echo "                  \`+ '......,,,'           "
	@echo "                  +....:.,@:,,,,#          "
	@echo "                  ;...,\`:\`\`;,,+:,:         "
	@echo "                  #;,;\`\`\`\`\`\`.\`\`#,#         "
	@echo "                  #;.:\`\`\`\`:;\`\`\`#,;         "
	@echo "                  :;\`\`\`\`\`\`\`\`\`\`:,,;         "
	@echo "                  :\`:\`\`,\`\`:\`\`\`.,,+         "
	@echo "                  @\`'\`\`;\`\`,#\`\`.:'@         "
	@echo "    #';           '\`\`\`#\`\`\`\`\`\`\`.,+;         "
	@echo "   '\`\`#           ;\`\`\`@\`\`\`\`\`\`\`:.@          "
	@echo "   \`\`\`.           '\`\`\`.\`\`\`\`\`\`\`\`\`+          "
	@echo "   .\`\`            @:'.\`\`;'#\`\`\`\`\`;          "
	@echo "   +\`\`.           #\`'\`   +\`\`\`\`\`,#          "
	@echo "  .+.\`..          .:\`\`;'\`\`\`\`\`\`@            "
	@echo ";\`\`\`\`#.\`;          @\`\`:,\`\`\`\`\`@             "
	@echo "@\`\`\`\`\`+\`+#.         @\`\`\`\`\`\`\`@,:'           "
	@echo " '#@#\`+\`.+,;+####';:,#.\`\`\`\`\`'\`\`#;+         "
	@echo ",\`\`\`\`\`#\`;',,,,,,,,,,,\`.@#;.#\`\`.;;;'.       "
	@echo ",\`\`\`\`\`\`\`@,:,,,,,,,,,,,\`\`'',\`\`\`@;;;;;#      "
	@echo " #\`\`:@@\`+:;;,,,,,,,,,#\`\`\`\`\`\`.#;;;;;;;#     "
	@echo " #\`\`\`\`#\`.+;;;;:,,+,,,;\`\`\`\`;@;;;;;;;;;;#    "
	@echo " \`@#+#.+;;;;;;;;'#,,,#\`\`\`;;;;;;;;;;;;;;+   "
	@echo "   :+#++;;;'##:  #,,,#\`\`\`#;;;;;;;;;;;;;;:  "
	@echo "                 #,,,+\`\`\`#;;;;;;;;;;;;;;;  "
	@echo "                 #,,,;\`\`\`#;;;;;'+';;;;;;;# "
	@echo "                 #,,,,\`\`\`+;;;;;''@.#';;;'' "
	@echo "                 @,,,,\`\`\`';;;;;''# ,;;;;'# "
	@echo "                 @,,,.\`\`\`';;;;''': ';;;''. "
	@echo "                 +,,,.\`\`\`';;;;''+ ;;;;''+  "
	@echo "                 :+,,,\`\`\`';;;;''# ';;''';  "
	@echo "                 \`\`+;:\`\`\`+;;;;''@;;''''#   "
	@echo "                  .\`\`\`\`\`\`#;;+#'.@#''''':   "
	@echo "                  :\`\`\`\`\`\`\`\`\`\`\`\`\`@:@'''@    "
	@echo "                  +\`\`\`\`\`\`\`\`\`\`\`\`\`#\`\`;#@     "
	@echo "                  @#\`\`\`\`\`\`\`\`\`\`\`,@\`\`\`#..    "
	@echo "                  #,,##;,,,;#@#''.\`\`+\`#    "
	@echo "                  +,,;;;:::;;''''#\`\`\`.\`    "
	@echo "                  ;,,;;;;;;;;''''#,.,,     "
	@echo "                  .,,;;;;;;;;'''''#        "
	@echo "                    .;;;;;;;;''''':        "


$(OBJ) : $(SRC)
	gcc -c $(FLAGS) $(SRC)

clean :
	/bin/rm -f $(OBJ)

fclean : clean
	/bin/rm -f $(NAME)

re : fclean all
