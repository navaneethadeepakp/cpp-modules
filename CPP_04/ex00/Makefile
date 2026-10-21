NAME		=	ex00
CXX 		=	c++
CXXFLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCS		=	main.cpp Animal.cpp Dog.cpp Cat.cpp WrongAnimal.cpp
OBJ_DIR		=	objs/
OBJS		=	$(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))

all: $(NAME)

$(NAME): $(OBJS)
		$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

$(OBJ_DIR)%.o: %.cpp
		@mkdir -p $(OBJ_DIR)
		$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
		rm -rf $(OBJ_DIR)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re