CC = c++ 

CCFLAGS = -Wall -Werror -Wextra -std=c++98 

NAME = zombie

SRC := $(wildcard *.cpp)

HEADERS := $(wildcard *.hpp)

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ) 
	$(CC) $(CCFLAGS) $(SRC) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CC) $(CCFLAGS) -c $< -o $@

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : re clean fclean all
.SECONDARY : $(OBJ)