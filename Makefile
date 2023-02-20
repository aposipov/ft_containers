
NAME	=	ft_containers
CC		=	c++
W_FLAGS	=	-Wall -Wextra -Werror
S_FLAGS =	-std=c++98
INC_FLAG=	-I ./inc/
RM		=	rm -rf
OBJ 	=	$(patsubst %.cpp, %.o, $(SRC))

.PHONY:		all clean fclean re test

RED= \033[1;31m
GREEN= \033[1;32m
NC= \033[0;0m


INC		=	inc/Vector.hpp
SRC		=	src/main.cpp

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(W_FLAGS) $(S_FLAGS) $(OBJ) -o $(NAME)
			@echo -e "$(GREEN)\t\n $(NAME) compiled!\n $(NC)"

%.o : %.cpp	Makefile $(INC)
			$(CC) $(INC_FLAG) $(W_FLAGS) $(S_FLAGS) -c $< -o $@

clean:
			$(RM) $(OBJ)
			@echo -e "$(RED)*.o files are delete!$(NC)"

fclean:		clean
			$(RM) $(NAME) test_vector a.out
			@echo -e "$(RED)All files delete!$(NC)"

re:			fclean all

test:		$(NAME)
			valgrind ./$(NAME)

test_vector:	Makefile $(INC)
				$(CC) $(W_FLAGS) $(S_FLAGS) $(INC_FLAG) src/test_vector.cpp -o test_vector
				@echo -e "$(GREEN)\t\n TEST vector compiled!\n $(NC)"