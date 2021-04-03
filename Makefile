# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/02 18:57:50 by msales-a          #+#    #+#              #
#    Updated: 2021/04/03 12:38:59 by msales-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PRODUCT := miniRT

SOURCES := $(shell find src -type f -name *.c)

OBJECTS := $(addprefix target/,$(SOURCES:.c=.o))

TEST := $(shell find test -type f -name *.c)

TEST_OBJECTS := $(addprefix target/,$(TEST:.c=.o))

OBJECTS_WITHOUT_MAIN := $(filter-out %main.o, $(OBJECTS))

CC := clang -O3

CC_FLAGS := -Wall -Wextra -Werror -g -lm -L./lib/libft -lft -L./lib/minilibx-linux -lmlx -lXext -lX11 -lbsd

all : $(PRODUCT)

$(PRODUCT) : $(OBJECTS)
	@$(MAKE) -C ./lib/libft
	@$(MAKE) -C ./lib/minilibx-linux
	@$(CC) $(OBJECTS) $(CC_FLAGS) -o $(PRODUCT)

clean :
	@rm -rf ./target/src ./target/test

fclean :
	@rm -f $(PRODUCT) $(PRODUCT)_test

re : all clean

bonus : all

test : $(PRODUCT)_test
	@./$(PRODUCT)_test

$(PRODUCT)_test : $(OBJECTS_WITHOUT_MAIN) $(TEST_OBJECTS)
	@$(MAKE) -C ./lib/libft
	@$(MAKE) -C ./lib/minilibx-linux
	@$(CC) $(OBJECTS_WITHOUT_MAIN) $(TEST_OBJECTS) $(CC_FLAGS) -o $(PRODUCT)_test

target/%.o : %.c
	@mkdir -p $(@D)
	@$(CC) -c $< -g -o $@
