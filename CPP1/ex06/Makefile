SRC = main.cpp \
		Harl.cpp
NAME = harlFilter
CC = g++
CFLAGS = -std=c++98 -Wall -Wextra -Werror
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@

re : fclean all

clean :
	rm -f $(OBJ)

fclean : clean
	rm -rf $(NAME)

.PHONY : all re clean fclean