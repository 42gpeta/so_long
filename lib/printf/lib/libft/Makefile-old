# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/11 18:34:10 by gpeta             #+#    #+#              #
#    Updated: 2022/12/23 15:31:49 by gpeta            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############################################
##	ARGUMENTS

NAME =			libft.a
CC = 			cc
CFLAGS = 		-Wall -Wextra -Werror
NORMINETTE =	norminette -R CheckForbiddenSourceHeader *.c *.h

###############################################
##	SOURCES

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
ft_toupper.c ft_tolower.c ft_atoi.c ft_strlcat.c ft_memset.c ft_bzero.c \
ft_memcpy.c ft_memmove.c ft_strchr.c ft_strrchr.c ft_strlcpy.c ft_memcmp.c ft_strnstr.c \
ft_memchr.c ft_calloc.c ft_strdup.c ft_substr.c ft_strncmp.c ft_strjoin.c ft_strtrim.c \
ft_itoa.c ft_putchar_fd.c ft_strmapi.c ft_striteri.c ft_putstr_fd.c ft_putendl_fd.c \
ft_putnbr_fd.c ft_split.c

OBJ = $(SRC:.c=.o)

BONUS = ft_lstnew.c \
ft_lstadd_front.c \
ft_lstsize.c \
ft_lstlast.c \
ft_lstadd_back.c \
ft_lstdelone.c \
ft_lstclear.c \
ft_lstiter.c \
ft_lstmap.c

BONUS_OBJ = $(BONUS:.c=.o)

###############################################
##	RULES

all : $(NAME)

%.o : %.c
	$(CC) -o $@ -c $^ $(CFLAGS)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)

bonus : $(BONUS_OBJ)
	ar rc $(NAME) $(BONUS_OBJ)

clean :
	rm -rf $(OBJ) $(BONUS_OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

norminette :
	$(NORMINETTE)

.PHONY : all clean fclean re