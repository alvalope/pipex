# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvalope <alvalope@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 13:43:51 by alvalope          #+#    #+#              #
#    Updated: 2023/05/26 13:08:52 by alvalope         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

PIPEX = ft_pipex.a

LIBFT_PATH = ./libftplus

LIBFT = $(LIBFT_PATH)/libft.a

HEADER = ft_pipex.h $(LIBFT_PATH)/libft.h

CC = gcc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_pipex.c ft_pipex_utils.c ft_do_commands.c ft_check_commands.c \
	ft_split_quote.c

OBJS = $(SRCS:.c=.o)

RM = rm -f

LIB = ar rcs

all: $(NAME)

$(OBJS): $(SRCS)
	@echo "Compilando archivos de pipex..."
	@$(CC) $(CFLAGS) -c $(SRCS)

$(NAME): $(OBJS) $(LIBFT) $(HEADER)
	@echo "Generando libreria pipex..."
	@$(LIB) $(PIPEX) $(OBJS)
	@$(CC) $(CFLAGS) $(PIPEX) $(LIBFT) -o $(NAME)
	@echo "\033[0;32mPROCESO TERMINADO.\033[0m"

$(LIBFT):
	@make -C $(LIBFT_PATH) all

clean:
	@echo "\033[0;31mBorrando archivos generados en la compilacion...\033[0m"
	@make -C $(LIBFT_PATH) clean
	@$(RM) $(OBJS)
	@echo "\033[0;33mLIMPIEZA TERMINADA.\033[0m"

fclean: clean
	@echo "\033[0;31mBorrando librerias generadas...\033[0m"
	@make -C $(LIBFT_PATH) libclean
	@$(RM) $(NAME) $(PIPEX)
	@echo "\033[0;33mLIMPIEZA TOTAL TERMINADA.\033[0m"

re: fclean all

.PHONY: all clean fclean re