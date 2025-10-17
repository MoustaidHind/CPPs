CC = c++ -Wall -Werror -Wextra -std=c++98 

NAME = account

SRC := $(wildcard *.cpp)

OBJ = $(SRC:.cpp=.o)

%.o: %.cpp %.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME) : $(OBJ) 
	$(CC) $(SRC) -o $(NAME)

all : $(NAME)

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : re clean fclean all
.SECONDARY : $(OBJ)