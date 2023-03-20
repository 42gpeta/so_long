# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/11 18:34:10 by gpeta             #+#    #+#              #
#    Updated: 2023/03/18 17:59:23 by gpeta            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		:= so_long


#-------------------------------------------------------#
#	INGREDIENTS											#
#-------------------------------------------------------#

LIBS		:= mlx ft
LIBS_TARGET := \
lib/libft/libft.a \
lib/libmlx/libmlx_Linux.a \
lib/libmlx/libmlx.a

INCS		:= \
include \
lib/libmlx \
lib/libft/include


SRC_DIR		:= src
SRCS		:= \
event_utils.c \
error_message.c \
pixel.c pixel_utils.c \
main.c \


SRCS		:= $(SRCS:%=$(SRC_DIR)/%)

BUILD_DIR	:= .build
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

CC 			:= cc
# CFLAGS 		:= -Wall -Wextra -Werror
CPPFLAG		:= $(addprefix -I ,$(INCS)) -MMD -MP
LDFLAGS		:= $(addprefix -L ,$(dir $(LIBS_TARGET)))
LDLIBS		:= $(addprefix -l ,$(LIBS))
MLX_FLAGS	:= -lXext -lX11 -lz -lm
NORMINETTE	:=	norminette -R CheckForbiddenSourceHeader *.c *.h

#-------------------------------------------------------#
#	UTENSILS											#
#-------------------------------------------------------#

RM			:= rm -f
MAKEFLAGS	+= --silent --no-print-directory
# MAKEFLAGS	+= --no-print-directory
DIR_DUP		= mkdir -p $(@D)


# #*********** BONUS ***********#

# BONUS_SRC_DIR := src_bonus
# BONUS_OBJ_DIR := obj_bonus
# BONUS_SRCS := 

# BONUS_SRCS := $(BONUS_SRCS:%=$(BONUS_SRCS_DIR)/%)
# BONUS_OBJ := $(BONUS_SRCS:$(BONUS_SRCS_DIR)/%.c=$(BONUS_OBJ_DIR)/%.o)

#-------------------------------------------------------#
#	RECIPES												#
#-------------------------------------------------------#

all : $(NAME)

#*******************************************************#
# (NORMAL) linker tous les *.o dans l'executable $(NAME)
# /!\ ATTENTION /!\ :il faut DE-masquer le main.c dans src plus haut
#*******************************************************#

$(NAME): $(OBJS) $(LIBS_TARGET)
	$(CC) -g $(LDFLAGS) $(OBJS) $(LDLIBS) $(MLX_FLAGS) -o $(NAME)
	$(info EXE ./$(NAME) CREATED)

#*******************************************************#
# (TEST) linker tous les *.o dans l'executable $(NAME)
# /!\ ATTENTION /!\ :il faut MASquer le main.c dans src plus haut
#*******************************************************#

# $(NAME): $(OBJS) $(LIBS_TARGET) mlxtest
# 	$(CC) -g $(LDFLAGS) $(OBJS) .build/main-test.o $(LDLIBS) $(MLX_FLAGS) -o $(NAME)
# 	$(info EXE ./$(NAME) CREATED)

$(LIBS_TARGET):
	$(MAKE) -C $(@D)

# compilation des *.c en *.o sans linker
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAG) -c -o $@ $<

# compilation fichier main de test : mlx-test
mlxtest: ./lib/libmlx/test/main.c
	cc -I include/ lib/libmlx lib/libft/include -c -o .build/main-test.o ./lib/libmlx/test/main.c

# bonus : $(OBJS) $(BONUS_OBJ)
# 	ar rc $(NAME) $(OBJS) $(BONUS_OBJ)

clean:
	for f in $(dir $(LIBS_TARGET)) ; do $(MAKE) -C $$f clean; done
	$(RM) $(OBJS) $(DEPS)
	rm .build/main-test.o
#	$(RM) $(OBJS) $(BONUS_OBJ)

fclean: clean
	for f in $(strip(dir $(LIBS_TARGET))) ; do $(MAKE) -C $$f fclean; done
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

# ************************************* #
#				MINILIBX				#
# ************************************* #

man_init:
	man ../minilibx-linux/man/man3/mlx.3

man_window:
	man ../minilibx-linux/man/man3/mlx_new_window.3

man_pixel:
	man ../minilibx-linux/man/man3/mlx_pixel_put.3

man_image:
	man ../minilibx-linux/man/man3/mlx_new_image.3

man_loop:
	man ../minilibx-linux/man/man3/mlx_loop.3

.PHONY: all clean fclean re
.SILENT:


###############################################
##	NORMINETTE : COLORMINETTE (@VEGRET)

RED          =    \033[0;91m
LIGHT_RED    =    \033[0;31m
GREEN        =    \033[0;92m

norminette:
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

norm_verif:
	nm $(NAME)