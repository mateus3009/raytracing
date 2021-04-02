# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/02 18:57:50 by msales-a          #+#    #+#              #
#    Updated: 2021/04/02 20:10:21 by msales-a         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PRODUCT := miniRT

SOURCES := $(shell find src -type f -name *.c)

OBJECTS := $(addprefix target/,$(SOURCES:.c=.o))

TEST := $(shell find test -type f -name *.c)

TEST_OBJECTS := $(addprefix target/,$(TEST:.c=.o))

OBJECTS_WITHOUT_MAIN := $(filter-out %main.o, $(OBJECTS))

CC := clang -O3

all : $(PRODUCT)

$(PRODUCT) : $(OBJECTS)
	@$(CC) $(OBJECTS) -o $(PRODUCT)

clean :
	@rm -rf ./target/src ./target/test

fclean :
	@rm -f $(PRODUCT) $(PRODUCT)_test

re : all clean

bonus : all

test : $(PRODUCT)_test

$(PRODUCT)_test : $(OBJECTS_WITHOUT_MAIN) $(TEST_OBJECTS)
	@$(CC) $(OBJECTS_WITHOUT_MAIN) $(TEST_OBJECTS) -o $(PRODUCT)_test

target/%.o : %.c
	@mkdir -p $(@D)
	@$(CC) -c $< -o $@
