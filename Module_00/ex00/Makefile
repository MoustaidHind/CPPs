CC = c++ -Wall -Werror -Wextra -std=c++98 

NAME = megaphone

SRC = megaphone.cpp

OBJ = $(SRC:.cpp=.o)

$(NAME) : $(OBJ)
	$(CC) $(OBJ) -o $(NAME) 

all : $(NAME)

clean : 
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : 
	clean fclean

.PHONY : re clean fclean all
.SECONDARY : $(OBJ)