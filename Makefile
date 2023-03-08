# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/11 18:34:10 by gpeta             #+#    #+#              #
#    Updated: 2023/03/08 18:49:06 by gpeta            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############################################
##	ARGUMENTS

NAME =			so_long
CC = 			cc
CFLAGS = 		-Wall -Wextra -Werror
# pour les fichiers *.h
CPPFLAG =		-I minilibx-linux
MLX_FLAGS =	-lmlx -lXext -lX11
DIR_DUP = mkdir -p $(@D)
RM := rm -f
NORMINETTE =	norminette -R CheckForbiddenSourceHeader *.c *.h
MAKEFLAGS += --no-print-directory

###############################################
##	SOURCES

#*********** MANDATORY ***********#

SRC_DIR := src
OBJ_DIR := obj
SRCS := main.c

SRCS := $(SRCS:%=$(SRC_DIR)/%)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

#*********** BONUS ***********#

BONUS_SRC_DIR := src_bonus
BONUS_OBJ_DIR := obj_bonus
BONUS_SRCS := 

BONUS_SRCS := $(BONUS_SRCS:%=$(BONUS_SRCS_DIR)/%)
BONUS_OBJ := $(BONUS_SRCS:$(BONUS_SRCS_DIR)/%.c=$(BONUS_OBJ_DIR)/%.o)

###############################################
##	RULES

all : $(NAME)

# linker tous les *.o dans l'executable $(NAME)
$(NAME) : $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	$(info EXE ./$(NAME) CREATED)
#	$(CC) $(OBJS) -Lminilibx-linux -lminilibx-linux -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz -o $(NAME)
#	$(CC) $(OBJS) -L./../minilibx-linux -l./../minilibx-linux -L/usr/lib -I./../minilibx-linux -lXext -lX11 -lm -lz -o $(NAME)

# compilation des *.c en *.o sans linker
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAG) -c -o $@ $<
	$(info FILES $(@F) LINKED)
#	$(CC) $(CFLAGS) $(CPPFLAG) $(MLX_FLAGS) -03 -c -o $@ $<

# bonus : $(OBJS) $(BONUS_OBJ)
# 	ar rc $(NAME) $(OBJS) $(BONUS_OBJ)

clean :
	$(RM) $(OBJS) $(BONUS_OBJ)

fclean : clean
	$(RM) $(NAME)

re : 
	$(MAKE) fclean
	$(MAKE) all

# ************************************* #
#				MINILIBX				#
# ************************************* #

test :
	$(CC) $(MLX_FLAGS) main.c

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
.SILENT:


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