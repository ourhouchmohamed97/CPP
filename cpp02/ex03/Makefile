# Reset
NC      := \033[0m

# Regular colors
ORANGE := \033[0;33m
OK    	:= \033[1;32m
INFO 	:= \033[1;36m

NAME = BSP
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

HEADER = Fixed.hpp \
	Point.hpp
SRC = main.cpp \
	Fixed.cpp  \
	Point.cpp  \
	bsp.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@echo "$(INFO) => Starting build..$(NC)"
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo""
	@echo "$(ORANGE)██████╗░░██████╗██████╗░$(NC)"
	@echo "$(ORANGE)██╔══██╗██╔════╝██╔══██╗$(NC)"
	@echo "$(ORANGE)██████╦╝╚█████╗░██████╔╝$(NC)"
	@echo "$(ORANGE)██╔══██╗░╚═══██╗██╔═══╝░$(NC)"
	@echo "$(ORANGE)██████╦╝██████╔╝██║░░░░░$(NC)"
	@echo "$(ORANGE)╚═════╝░╚═════╝░╚═╝░░░░░$(NC)"
	@echo""
	@echo "$(OK)=> done$(NC)"

%.o: %.cpp $(HEADER)
	@$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all