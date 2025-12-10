# Reset
NC      := \033[0m

# Regular colors
BLUE 	:= \033[0;34m
OK    	:= \033[1;32m
INFO 	:= \033[1;36m

NAME = replace
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(INFO) => Starting build..$(NC)"
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo ""
	@echo "$(BLUE)██████╗░███████╗██████╗░██╗░░░░░░█████╗░░█████╗░███████╗$(NC)"
	@echo "$(BLUE)██╔══██╗██╔════╝██╔══██╗██║░░░░░██╔══██╗██╔══██╗██╔════╝$(NC)"
	@echo "$(BLUE)██████╔╝█████╗░░██████╔╝██║░░░░░███████║██║░░╚═╝█████╗░░$(NC)"
	@echo "$(BLUE)██╔══██╗██╔══╝░░██╔═══╝░██║░░░░░██╔══██║██║░░██╗██╔══╝░░$(NC)"
	@echo "$(BLUE)██║░░██║███████╗██║░░░░░███████╗██║░░██║╚█████╔╝███████╗$(NC)"
	@echo "$(BLUE)╚═╝░░╚═╝╚══════╝╚═╝░░░░░╚══════╝╚═╝░░╚═╝░╚════╝░╚══════╝$(NC)"
	@echo ""
	@echo "$(OK)=> done$(NC)"

%.o: %.cpp
	@$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all