# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msales-a <msales-a@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/02 18:57:50 by msales-a          #+#    #+#              #
#    Updated: 2021/05/11 17:45:30 by msales-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PRODUCT := miniRT

SOURCES := $(shell find src -type f -name *.c)

OBJECTS := $(addprefix target/,$(SOURCES:.c=.o))

LIBRARIES = ./lib/libft/libft.a

CC := clang

CC_FLAGS := -Wall -Wextra -Werror -lm -L./lib/libft -lft -lbsd -lmlx -lXext -lX11 -pthread

all : $(PRODUCT)

$(PRODUCT) : $(OBJECTS) $(LIBRARIES)
	@$(CC) $(OBJECTS) $(CC_FLAGS) -o $(PRODUCT)

clean :
	@rm -rf ./target/src ./target/test
	@$(MAKE) clean -C ./lib/libft

fclean :
	@rm -f $(PRODUCT) $(PRODUCT)_test
	@$(MAKE) fclean -C ./lib/libft

re : all clean

bonus : all

target/%.o : %.c
	@mkdir -p $(@D)
	@$(CC) -c $< -g -o $@

$(LIBRARIES) :
	@$(MAKE) -C ./lib/libft
