# Reset
NC      := \033[0m

# Regular colors
ELECTRIC_ORANGE := \033[38;2;255;140;0m
OK    	:= \033[1;32m
INFO 	:= \033[1;36m

NAME = iter
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

HEADER = iter.hpp
SRC = main.cpp 
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@echo "$(INFO) => Starting build..$(NC)"
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo ""
	@echo "$(ELECTRIC_ORANGE)██╗████████╗███████╗██████╗░$(NC)"
	@echo "$(ELECTRIC_ORANGE)██║╚══██╔══╝██╔════╝██╔══██╗$(NC)"
	@echo "$(ELECTRIC_ORANGE)██║░░░██║░░░█████╗░░██████╔╝$(NC)"
	@echo "$(ELECTRIC_ORANGE)██║░░░██║░░░██╔══╝░░██╔══██╗$(NC)"
	@echo "$(ELECTRIC_ORANGE)██║░░░██║░░░███████╗██║░░██║$(NC)"
	@echo "$(ELECTRIC_ORANGE)╚═╝░░░╚═╝░░░╚══════╝╚═╝░░╚═╝$(NC)"
	@echo ""
	@echo "$(OK)=> done$(NC)"

%.o: %.cpp $(HEADER)
	@$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all