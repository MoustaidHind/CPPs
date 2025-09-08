CC = c++ -Wall -Werror -Wextra -std=c++98 

NAME = phonebook

SRC = phonebook.cpp

OBJ = $(SRC:.cpp=.o)


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