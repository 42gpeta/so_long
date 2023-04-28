# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/11 18:34:10 by gpeta             #+#    #+#              #
#    Updated: 2023/03/09 16:02:28 by gpeta            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		:= printf
# SCD_MAKEFILE	:= libft


#-------------------------------------------------------#
#	INGREDIENTS											#
#-------------------------------------------------------#

LIBS		:= ft
LIBS_TARGET	:= lib/libft/libft.a

INCS		:= \
include \
lib/libft/include


SRC_DIR 	:= src
SRC			:= \
f_check.c \
ft_printf.c \
ft_putchar.c \
ft_puthexa.c \
ft_puthexa_p.c \
ft_putnbr.c \
ft_putnbr_u.c \
ft_putstr.c \
main.c
SRC			:= $(SRC:%=$(SRC_DIR)/%)

BUILD_DIR	:= .build
OBJS		:= $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= $(addprefix -I ,$(INCS)) -MMD -MP
LDFLAGS		:= $(addprefix -L ,$(dir $(LIBS_TARGET)))
LDLIBS		:= $(addprefix -l ,$(LIBS))
NORMINETTE 	:= norminette -R CheckForbiddenSourceHeader *.c *.h


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

all: $(NAME)

$(NAME): $(OBJS) $(LIBS_TARGET)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME)
	$(info exe ./$@ created)

$(LIBS_TARGET):
	$(MAKE) -C $(@D)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $^

-include $(DEPS)

# bonus : $(OBJ) $(BONUS_OBJ)
# 	ar rc $(NAME) $(OBJ) $(BONUS_OBJ)

clean:
	for f in $(dir $(LIBS_TARGET)) ; do $(MAKE) -C $$f clean; done
	$(RM) $(OBJS) $(DEPS)
#	rm -rf $(OBJ) $(BONUS_OBJ)

fclean: clean
	for f in $(dir $(LIBS_TARGET)) ; do $(MAKE) -C $$f fclean; done
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all


# ###############################################
# ##	RULES libft

# $(SCD_MAKEFILE) : 
# 	make -C $(SCD_MAKEFILE)
# 	ar crsv $(NAME) libft/$(SCD_MAKEFILE).a

# addlibft :
# 	ar crsv $(NAME) libft/$(SCD_MAKEFILE).a

# clean2 :
# 	make -C $(SCD_MAKEFILE) clean

# fclean2 : 
# 	make -C $(SCD_MAKEFILE) fclean

# re2 : fclean2 $(SCD_MAKEFILE)

#-------------------------------------------------------#
#	SPEC												#
#-------------------------------------------------------#

library:
	ar -t $(NAME)
	ar -t $(SCD_MAKEFILE)/$(SCD_MAKEFILE).a

# .PHONY: all clean fclean re library all2 clean2 fclean2 re2 libft norm_verif
.PHONY: all clean fclean re norm_verif
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
	nm $(OBJ)