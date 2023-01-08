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

# NAME = ft_container

# SRCDIR = src/
# INCDIR = inc/
# OBJDIR = obj/

# CC = c++

# SRCS     := $(wildcard $(SRCDIR)*.cpp)
# INCLUDES := $(wildcard $(INCDIR)*.hpp)
# OBJS     := $(SOURCES:$(SRCDIR)%.cpp=$(OBJDIR)%.o)
# rm        = rm -f

# FLAGS = -Wall -Wextra -Werror -g3 -std=c++98

# $(NAME): $(OBJS)
# 	$(CC) $(OBJS) -o $@
# # @$(CC) $(OBJS) $(INCLUDES) -o $@

# $(OBJS): $(OBJDIR)%.o : $(SRCDIR)%.cpp $(INCLUDES)
# 	$(CC) $(FLAGS) -c $< -o $@

# all: $(NAME)

# clean:
# 	@$(rm) $(OBJS)
# 	@$(rm) $(wildcard $(INCDIR)/*.gch)

# fclean: clean
# 	@$(rm) $(NAME)

# re: fclean all

# .PHONY: all clean fclean re


TARGET   = ft_container

CC       = c++

CFLAGS   = -Wall -Wextra -Werror -g3 -std=c++98 -std=c++11

LINKER   = c++

LDFLAGS  =

INCDIR = inc/

SRCDIR   = src/

OBJDIR   = obj/

SOURCES  := $(wildcard $(SRCDIR)*.cpp)

OBJECTS  := $(SOURCES:$(SRCDIR)%.cpp=$(OBJDIR)%.o)

INCLUDES := $(wildcard $(INCDIR)*.hpp)

rm       = rm -f

$(TARGET): $(OBJECTS)
	$(LINKER) $(LDFLAGS) $(OBJECTS) -o $@

$(OBJECTS): $(OBJDIR)%.o : $(SRCDIR)%.cpp $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(TARGET)

clean:
	$(rm) $(OBJECTS)

fclean: clean
	$(rm) $(TARGET)

re: fclean all

.PHONY: all clean fclean re
