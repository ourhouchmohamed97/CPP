# Reset
NC      := \033[0m

# Regular colors
BLUE 	:= \033[0;34m
OK    	:= \033[1;32m
INFO 	:= \033[1;36m

NAME = Weapon
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

HEADERS = Weapon.hpp \
		HumanA.hpp   \
		HumanB.hpp   \

SRC = main.cpp \
	Weapon.cpp \
	HumanA.cpp \
	HumanB.cpp \

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADERS)
	@echo "$(INFO) => Starting build..$(NC)"
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo ""
	@echo "$(BLUE)░██╗░░░░░░░██╗███████╗░█████╗░██████╗░░█████╗░███╗░░██╗$(NC)"
	@echo "$(BLUE)░██║░░██╗░░██║██╔════╝██╔══██╗██╔══██╗██╔══██╗████╗░██║$(NC)"
	@echo "$(BLUE)░╚██╗████╗██╔╝█████╗░░███████║██████╔╝██║░░██║██╔██╗██║$(NC)"
	@echo "$(BLUE)░░████╔═████║░██╔══╝░░██╔══██║██╔═══╝░██║░░██║██║╚████║$(NC)"
	@echo "$(BLUE)░░╚██╔╝░╚██╔╝░███████╗██║░░██║██║░░░░░╚█████╔╝██║░╚███║$(NC)"
	@echo "$(BLUE)░░░╚═╝░░░╚═╝░░╚══════╝╚═╝░░╚═╝╚═╝░░░░░░╚════╝░╚═╝░░╚══╝$(NC)"
	@echo ""
	@echo "$(OK)=> done$(NC)"

%.o: %.cpp $(HEADERS)
	@$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all