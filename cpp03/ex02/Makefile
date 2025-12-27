# Reset
NC      := \033[0m

# Regular colors
DARK_BURGUNDY := \033[38;2;129;16;32m
OK    	:= \033[1;32m
INFO 	:= \033[1;36m

NAME = FragTrap
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

HEADER = ClapTrap.hpp \
		 ScavTrap.hpp
SRC = main.cpp \
	ClapTrap.cpp \
	ScavTrap.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@echo "$(INFO) => Starting build..$(NC)"
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo""
	@echo "$(DARK_BURGUNDY)███████╗██████╗░░█████╗░░██████╗░████████╗██████╗░░█████╗░██████╗░$(NC)"
	@echo "$(DARK_BURGUNDY)██╔════╝██╔══██╗██╔══██╗██╔════╝░╚══██╔══╝██╔══██╗██╔══██╗██╔══██╗$(NC)"
	@echo "$(DARK_BURGUNDY)█████╗░░██████╔╝███████║██║░░██╗░░░░██║░░░██████╔╝███████║██████╔╝$(NC)"
	@echo "$(DARK_BURGUNDY)██╔══╝░░██╔══██╗██╔══██║██║░░╚██╗░░░██║░░░██╔══██╗██╔══██║██╔═══╝░$(NC)"
	@echo "$(DARK_BURGUNDY)██║░░░░░██║░░██║██║░░██║╚██████╔╝░░░██║░░░██║░░██║██║░░██║██║░░░░░$(NC)"
	@echo "$(DARK_BURGUNDY)╚═╝░░░░░╚═╝░░╚═╝╚═╝░░╚═╝░╚═════╝░░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░░░░$(NC)"
	@echo""
	@echo "$(OK)=> done$(NC)"

%.o: %.cpp $(HEADER)
	@$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all