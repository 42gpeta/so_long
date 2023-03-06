# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/11 18:34:10 by gpeta             #+#    #+#              #
#    Updated: 2023/03/06 15:08:32 by gpeta            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############################################
##	ARGUMENTS

NAME =			so_long
CC = 			cc
CFLAGS = 		-Wall -Wextra -Werror
MLX_COMPILE =	-lmlx -lXext -lX11
NORMINETTE =	norminette -R CheckForbiddenSourceHeader *.c *.h

###############################################
##	SOURCES

SRC =

OBJ = $(SRC:.c=.o)

BONUS =

BONUS_OBJ = $(BONUS:.c=.o)

###############################################
##	RULES

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I/usr/include -Imlx_linux -03 -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -Lminilibx-linux -lminilibx-linux -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz -o $(NAME)
#	$(CC) $(OBJ) -L./../minilibx-linux -l./../minilibx-linux -L/usr/lib -I./../minilibx-linux -lXext -lX11 -lm -lz -o $(NAME)

# librairie ? #
# $(NAME) : $(OBJ)
# 	ar rc $(NAME) $(OBJ)

bonus : $(OBJ) $(BONUS_OBJ)
	ar rc $(NAME) $(OBJ) $(BONUS_OBJ)

clean :
	rm -rf $(OBJ) $(BONUS_OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

# ************************************* #
#				MINILIBX				#
# ************************************* #

test :
	$(CC) $(MLX_COMPILE) main.c

man_init :
	man ../minilibx-linux/man/man3/mlx.3

man_window :
	man ../minilibx-linux/man/man3/mlx_new_window.3

man_pixel :
	man ../minilibx-linux/man/man3/mlx_pixel_put.3

man_image :
	man ../minilibx-linux/man/man3/mlx_new_image.3

man_loop :
	man ../minilibx-linux/man/man3/mlx_loop.3

.PHONY : all clean fclean re


###############################################
##	NORMINETTE : COLORMINETTE (@VEGRET)

RED          =    \033[0;91m
LIGHT_RED    =    \033[0;31m
GREEN        =    \033[0;92m
norminette :
	@$(NORMINETTE) | grep -v Norme | awk '{\
	if ($$NF == "OK!") { \
	    print "$(GREEN)"$$0"$(END)" \
	} else if ($$NF == "Error!") { \
	    print "$(RED)$(BOLD)"$$0"$(END)" \
	} else if ($$1 == "Error:") { \
	    print "$(LIGHT_RED)"$$0"$(END)" \
	} else { print }}'

###############################################
##	NORMINETTE : verif norminette (@VEGRET)

norm_verif :
	nm $(NAME)