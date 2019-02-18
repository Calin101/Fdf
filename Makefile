# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: calin <calin@student.le-101.fr>            +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/01/17 14:05:02 by calin        #+#   ##    ##    #+#        #
#    Updated: 2019/02/13 17:07:37 by calin       ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = fdf

SRCS =  main.c\
		color.c\
		parsing.c\
		ft_utils.c\
		ft_utils2.c\
		get_infos.c\
		get_infos2.c\
		moove.c\
		moove2.c\

FLAG = -Wall -Wextra -Werror

MLX = -framework OpenGL -framework AppKit

OBJ = $(SRCS:.c=.o)

CC = gcc $(FLAG)

LIBFT = libft/libft.a

RM = /bin/rm -f

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) -o $(NAME) $^ minilibx_macos/libmlx.a $(MLX) && echo "\n$(NAME) compiled :\033[0;32m DONE !\033[0m"

$(LIBFT):
	@make -C libft/

%.o:%.c
	@$(CC) -o $@ -c $< && echo "\033[7;32m \033[0m\c"

clean:
	@make clean -C libft/
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C libft/
	@echo "$(NAME) clean :\033[0;32m DONE !\033[0m"

norme:
	@norminette $(SRCS) fdf.h
	@make norme -C libft/

re:	fclean all

.PHONY: all clean fclean re norme