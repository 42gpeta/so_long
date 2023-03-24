# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/11 18:34:10 by gpeta             #+#    #+#              #
#    Updated: 2022/12/28 18:26:28 by gpeta            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############################################
##	ARGUMENTS

NAME =			libftprintf.a
SCD_MAKEFILE =	libft
CC = 			cc
CFLAGS = 		-Wall -Wextra -Werror
NORMINETTE =	norminette -R CheckForbiddenSourceHeader *.c *.h

###############################################
##	SOURCES

SRC = f_check.c \
ft_printf.c \
ft_putchar.c \
ft_puthexa.c \
ft_puthexa_p.c \
ft_putnbr.c \
ft_putnbr_u.c \
ft_putstr.c

SRC_H = ft_printf.h

OBJ = $(SRC:.c=.o)

###############################################
##	RULES ft_printf

all : $(NAME)

%.o : %.c
	$(CC) -o $@ -c $^ $(CFLAGS)

$(NAME) : $(OBJ)
	ar crs $(NAME) $(OBJ) $(SRC_H)
	make -C $(SCD_MAKEFILE)
	ar crsv $(NAME) libft/$(SCD_MAKEFILE).a

# bonus : $(OBJ) $(BONUS_OBJ)
# 	ar rc $(NAME) $(OBJ) $(BONUS_OBJ)

clean :
	rm -rf $(OBJ)
#	rm -rf $(OBJ) $(BONUS_OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

library :
	ar -t $(NAME)
	ar -t $(SCD_MAKEFILE)/$(SCD_MAKEFILE).a

###############################################
##	RULES libft

$(SCD_MAKEFILE) : 
	make -C $(SCD_MAKEFILE)
	ar crsv $(NAME) libft/$(SCD_MAKEFILE).a

addlibft :
	ar crsv $(NAME) libft/$(SCD_MAKEFILE).a

clean2 :
	make -C $(SCD_MAKEFILE) clean

fclean2 : 
	make -C $(SCD_MAKEFILE) fclean

re2 : fclean2 $(SCD_MAKEFILE)


.PHONY : all clean fclean re library all2 clean2 fclean2 re2 libft norm_verif


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
	nm $(OBJ)