# Reset
NC      := \033[0m

# Regular colors
ELECTRIC_PURPLE := \033[38;2;189;0;255m
OK    	:= \033[1;32m
INFO 	:= \033[1;36m


NAME = convert
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf


HEADER = ScalarConverter.hpp
SRC = main.cpp \
	  ScalarConverter.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@echo "$(INFO) => Starting build..$(NC)"
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo ""
	@echo "$(ELECTRIC_PURPLE)░█████╗░░█████╗░███╗░░██╗██╗░░░██╗███████╗██████╗░████████╗$(NC)"
	@echo "$(ELECTRIC_PURPLE)██╔══██╗██╔══██╗████╗░██║██║░░░██║██╔════╝██╔══██╗╚══██╔══╝$(NC)"
	@echo "$(ELECTRIC_PURPLE)██║░░╚═╝██║░░██║██╔██╗██║╚██╗░██╔╝█████╗░░██████╔╝░░░██║░░░$(NC)"
	@echo "$(ELECTRIC_PURPLE)██║░░██╗██║░░██║██║╚████║░╚████╔╝░██╔══╝░░██╔══██╗░░░██║░░░$(NC)"
	@echo "$(ELECTRIC_PURPLE)╚█████╔╝╚█████╔╝██║░╚███║░░╚██╔╝░░███████╗██║░░██║░░░██║░░░$(NC)"
	@echo "$(ELECTRIC_PURPLE)░╚════╝░░╚════╝░╚═╝░░╚══╝░░░╚═╝░░░╚══════╝╚═╝░░╚═╝░░░╚═╝░░░$(NC)"
	@echo ""
	@echo "$(OK)=> done$(NC)"

%.o: %.cpp $(HEADER)
	@$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all