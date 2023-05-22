# ************************************************************************** #
#                                                                            #
#                                                        :::      ::::::::   #
#   Makefile                                           :+:      :+:    :+:   #
#                                                    +:+ +:+         +:+     #
#   By: naal-jen <marvin@42.fr>                    +#+  +:+       +#+        #
#                                                +#+#+#+#+#+   +#+           #
#   Created: 2022/05/04 15:58:14 by naal-jen          #+#    #+#             #
#   Updated: 2022/05/09 10:25:50 by naal-jen         ###   ########.fr       #
#                                                                            #
# ************************************************************************** #

# \ = is used to Splitting Long Lines 3.1.1

# ;\ = indicates a multiline command and keeps the instance of the terminal for 
# the next command

# % = the same as * 'wildcard'
# $@ = means what is before the : in the target
# $^ = means what is after the : in the target
# $< = the first prerequisite (usually a source file)
# -I.  = adds include directory of header files.
# -f = force the removal even if the files have been already deleted. 

# -c = Compile or assemble the source files, but do not link.
# The linking stage simply is not done. The ultimate output is
# in the form of an object file for each source file.
# By default, the object file name for a source file is made by replacing
# the suffix .c, .i, .s, etc., with .o. Unrecognized input files,
# not requiring compilation or assembly, are ignored.


CC = gcc
CFLAGS = -Wall -Wextra -Werror
INC = -I.
AR = ar
ARF = -rcs
NAME = libft.a

MAN = isalpha isdigit isalnum isascii isprint strlen memset bzero memcpy\
		memmove strlcpy strlcat toupper tolower strchr strrchr strncmp memchr\
		memcmp strnstr atoi calloc strdup substr strjoin strtrim split itoa\
		strmapi striteri putchar_fd putstr_fd putendl_fd putnbr_fd get_next_line\

MANFC = $(addprefix ft_,$(addsuffix .c, $(MAN)))
MANO = $(MANFC:.c=.o)

BON = lstnew lstadd_front lstsize lstlast lstadd_back lstdelone lstclear\
		lstiter lstmap
BONFC = $(addprefix ft_,$(addsuffix .c, $(BON)))
BONO = $(BONFC:.c=.o)

all: $(NAME)

$(NAME): $(MANO)
	$(AR) $(ARF) $@ $^

%.o: %.c
	@$(CC) -c $(CFLAGS) $(INC) $< -o $@

clean:
	@rm -f $(MANO) $(BONO)

fclean: clean
	@rm -f $(NAME)

re: fclean all

bonus:	$(BONO)
	$(AR) $(ARF) $(NAME) $^

.PHONY: bonus all clean fclean re
