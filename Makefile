# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/08 15:56:39 by naal-jen          #+#    #+#              #
#    Updated: 2023/05/19 11:48:59 by naal-jen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rcs
INC = -I.
NAME = cub3d.a
TARGET = cub3d

CFILES = $(wildcard ./*.c) $(wildcard ./init/*.c) $(wildcard ./parse/*.c) $(wildcard ./utils/*.c)
# CFILES = $(wildcard *.c) init/*.c parse/*.c utils/*.c

OFILES = $(CFILES:.c=.o)

all: libft $(NAME) $(TARGET)

libft:
	cd libft; \
	$(MAKE); \
	cd ..;
	cd minilibx-linux; \
	$(MAKE); \

$(NAME): $(OFILES)
	@echo "\033[35m █▒▒▒▒▒▒▒▒▒\033[0m"
	@echo "\033[35m ███▒▒▒▒▒▒▒\033[0m"
	@echo "\033[35m █████▒▒▒▒▒\033[0m"
	@echo "\033[35m ████████▒▒\033[0m"
	@echo "\033[35m ██████████\033[0m"
	@$(AR) $(ARF) $@ $^
	@echo "\033[36m compiling\033[0m"

%.o: %.c
	@$(CC) -g -c $(CFLAGS) $(INC) $< -o $@

$(TARGET): $(CFILES)
	@$(CC) -g $(CFLAGS) $(OFILES) libft/libft.a minilibx-linux/libmlx.a -lXext -lX11 -lm -o $(TARGET)

clean:
	cd libft; \
	$(MAKE) fclean; \
	cd ..; \
	cd minilibx-linux; \
	$(MAKE) clean; \
	cd ..; \
	rm -f $(OFILES) \

fclean: clean
	@echo "\033[35mclean clean clean\033[0m"
	@rm -f cub3d
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libft