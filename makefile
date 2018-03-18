# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: awajsbro <awajsbro@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/28 16:56:20 by awajsbro          #+#    #+#              #
#    Updated: 2018/03/18 16:15:46 by awajsbro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

TMP = tmp.a

SRC 	=	ft_printf.c \
			ft_init_arg.c \
			ft_signed_buff.c \
			ft_unsigned_buff.c \
			ft_print_setup.c \
			ft_pars_color.c \
			ft_letter_buff.c \
			ft_buff_charcode.c \
			ft_length_pars.c \
			ft_change_color.c \
			ft_change_back.c \

OBJ = $(SRC:.c=.o)

LIB_DIR = ./libft/

LIBFT = ./libft/libft.a

all : $(NAME)

$(NAME) :
	@$(MAKE) -C $(LIB_DIR)
	@gcc -Wextra -Wall -Werror -c $(SRC)
	@ar rc $(TMP) $(OBJ)
	@libtool -static -o $(NAME) $(TMP) $(LIBFT)
	@rm -f $(TMP)
	@ranlib $(NAME)
	@echo "\033[36m	LIBFTPRINTF.A\033[33m ====\033[1m> \033[32;1mREADY TO USE\033[0m"

clean :
	@$(MAKE) clean -C $(LIB_DIR)
	@rm -f $(OBJ)
	@echo "\033[31;1m	CLEANING DONE\033[0m"

fclean : clean
	@rm -f $(NAME) $(LIBFT)
	@echo "\033[36m	LIBFTPRINTF.A\033[33m ====\033[1m> \033[31;1mDELETED\033[0m"

re : fclean all
