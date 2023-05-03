# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/11 18:34:10 by gpeta             #+#    #+#              #
#    Updated: 2023/05/03 21:33:31 by gpeta            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =			libft.a


#-------------------------------------------------------#
#	INGREDIENTS											#
#-------------------------------------------------------#

SRC_DIR		:= src
SRC			:= \
ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
ft_toupper.c ft_tolower.c ft_atoi.c ft_strlcat.c ft_memset.c ft_bzero.c \
ft_memcpy.c ft_memmove.c ft_strchr.c ft_strrchr.c ft_strlcpy.c ft_memcmp.c ft_strnstr.c \
ft_memchr.c ft_calloc.c ft_strdup.c ft_substr.c ft_strncmp.c ft_strjoin.c ft_strtrim.c \
ft_itoa.c ft_putchar_fd.c ft_strmapi.c ft_striteri.c ft_putstr_fd.c ft_putendl_fd.c \
ft_putnbr_fd.c ft_split.c \
ft_lstnew.c \
ft_lstadd_front.c \
ft_lstsize.c \
ft_lstlast.c \
ft_lstadd_back.c \
ft_lstdelone.c \
ft_lstclear.c \
ft_lstiter.c \
ft_lstmap.c \
f_check.c ft_puthexa.c ft_putnbr_u.c ft_printf.c ft_puthexa_p.c ft_putstr.c ft_putchar.c ft_putnbr.c

SRC			:= $(SRC:%=$(SRC_DIR)/%)

BUILD_DIR	:= .build
OBJS		:= $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
DEPS		:= $(OBJS:.o=.d)

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror
CPPFLAGS	:= -MMD -MP -I include
AR			:= ar
ARFLAGS		:= -r -c -s
NORMINETTE	:= norminette -R CheckForbiddenSourceHeader *.c *.h


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

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	$(info library $@ created)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
#	$(info $@ ready)

-include $(DEPS)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

#-------------------------------------------------------#
#	SPEC												#
#-------------------------------------------------------#

.PHONY: all clean fclean re
.SILENT:
norminette :
	$(NORMINETTE)