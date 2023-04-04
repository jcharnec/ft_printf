# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: areverte <areverte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/11 15:55:08 by areverte          #+#    #+#              #
#    Updated: 2023/02/11 15:55:09 by areverte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
SRC = ft_printf.c ft_print_sc.c ft_print_hex.c ft_print_ptr.c ft_print_decs.c ft_itoa.c ft_u_itoa.c

FLAGS = -Wall -Werror -Wextra
OBJ = $(SRC:.c=.o)
HEADER = ft_printf.h

RM = rm -f

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@


$(NAME) : $(OBJ) $(HEADER)
	ar rcs $(NAME) $(OBJ)

all : $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)
	@echo "$(GREEN)$(NAME) cleaned!$(NC)"

re : fclean all

.PHONY = all clean fclean re
