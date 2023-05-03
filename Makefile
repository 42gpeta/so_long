# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/11 18:34:10 by gpeta             #+#    #+#              #
#    Updated: 2023/05/03 21:34:06 by gpeta            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		:= so_long


#-------------------------------------------------------#
#	INGREDIENTS											#
#-------------------------------------------------------#

LIBS		:= ft mlx
LIBS_TARGET := \
lib/libmlx/libmlx_Linux.a \
lib/libmlx/libmlx.a \
lib/libft/libft.a \

INCS		:= \
include \
lib/libmlx \
lib/libft/include \


SRC_DIR		:= src
SRCS		:= \
error_message.c  \
event.c  \
control_string_map.c  string_map.c  xpm.c  \
map_check.c  map_check_parameters.c  \
move.c  move_parameters.c  \
pathfinding.c  pathfinding_utils.c  \
so_long.c  \
/gnl/get_next_line.c  /gnl/get_next_line_utils.c  \
main.c  \


SRCS		:= $(SRCS:%=$(SRC_DIR)/%)

BUILD_DIR	:= .build
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

CC 			:= cc
CFLAGS 		:= -Wall -Wextra -Werror 
CPPFLAG		:= $(addprefix -I ,$(INCS)) -MMD -MP
LDFLAGS		:= $(addprefix -L ,$(dir $(LIBS_TARGET)))
LDLIBS		:= $(addprefix -l ,$(LIBS))
MLX_FLAGS	:= -lXext -lX11 -lz -lm
NORMINETTE	:=	norminette -R CheckForbiddenSourceHeader ./*/*.c ./*/*.h

#-------------------------------------------------------#
#	UTENSILS											#
#-------------------------------------------------------#

RM			:= rm -f
MAKEFLAGS	+= --silent --no-print-directory
# MAKEFLAGS	+= --no-print-directory
DIR_DUP		= mkdir -p $(@D)


#-------------------------------------------------------#
#	RECIPES												#
#-------------------------------------------------------#

all : $(NAME)

$(NAME): $(OBJS) $(LIBS_TARGET)
	$(CC) -g $(LDFLAGS) $(OBJS) $(LDLIBS) $(MLX_FLAGS) -o $(NAME)
	$(info EXE ./$(NAME) CREATED)

$(LIBS_TARGET):
	$(MAKE) -C $(@D)

# compilation des *.c en *.o sans linker
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAG) -ggdb -c -o $@ $<

clean:
	for f in $(dir $(LIBS_TARGET)) ; do $(MAKE) -C $$f clean; done
	$(RM) $(OBJS) $(DEPS)

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