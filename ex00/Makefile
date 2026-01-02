# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rteoh <rteoh@student.42kl.edu.my>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/12 22:32:39 by rteoh             #+#    #+#              #
#    Updated: 2025/12/15 15:55:12 by rteoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= btc
CXX			:= c++
CXXFLAGS	:= -Wall -Werror -Wextra -std=c++98 -pedantic
RM			:= rm -f
SOURCES		:= main.cpp BitcoinExchange.cpp
OBJECTS		:= $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp BitcoinExchange.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re