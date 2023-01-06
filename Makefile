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

NAME = ft_container

SRCDIR = src
INCDIR = inc
OBJDIR = obj

CC = c++

SRCS     := $(wildcard $(SRCDIR)/*.cpp)
INCLUDES := $(wildcard $(INCDIR)/*.hpp)
OBJS     := $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)
rm        = rm -f

FLAGS = -Wall -Wextra -Werror -g3 -std=c++98

$(NAME): $(OBJS)
	@$(CC) $(OBJECTS) $(INCLUDES) -o $@

$(OBJECTS):	$(OBJDIR)/%.o :	$(SRCDIR)/%.cpp
	@$(CC) $(FLAGS) -cpp $< -o $@

all: $(NAME)

clean:
	@$(rm) $(OBJECTS)
	@$(rm) *.gch

fclean: clean
	@$(rm) $(NAME)

re: fclean all

.PHONY: all clean fclean re
