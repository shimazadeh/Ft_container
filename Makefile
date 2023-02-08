# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shabibol <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/02 17:41:06 by shabibol          #+#    #+#              #
#    Updated: 2022/07/02 17:41:08 by shabibol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET   = ft_container

CC       = c++

CFLAGS   = -Wall -Wextra -Werror -g3 -std=c++98

LINKER   = c++

SRCDIR   = src/

OBJDIR   = obj/

SOURCES  := src/main.cpp src/map_test.cpp src/stack_test.cpp src/vector_test.cpp

OBJECTS  := $(SOURCES:$(SRCDIR)%.cpp=$(OBJDIR)%.o)

INCLUDES := inc/equal.hpp inc/ft_container.hpp inc/Is_Integral.hpp inc/pair.hpp inc/SelectConst.hpp\
			inc/iterator_traits.hpp inc/iterator.hpp inc/reverse_iterator.hpp\
			inc/RBtree.hpp inc/RBtree_node.hpp inc/RBtree_iterator.hpp inc/RBtree_ReverseIterator.hpp \
			inc/stack.hpp inc/vector.hpp inc/map.hpp

rm       = rm -f

$(TARGET): $(OBJECTS)
	$(LINKER) $(OBJECTS) -o $@

$(OBJECTS): $(OBJDIR)%.o : $(SRCDIR)%.cpp $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(TARGET)

clean:
	$(rm) $(OBJECTS)

fclean: clean
	$(rm) $(TARGET)

re: fclean all

.PHONY: all clean fclean re
