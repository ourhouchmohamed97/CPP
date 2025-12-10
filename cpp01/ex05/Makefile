# Reset
NC      := \033[0m

# Regular colors
BLUE 	:= \033[0;34m
OK    	:= \033[1;32m
INFO 	:= \033[1;36m

NAME = Harl
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

HEADER = Harl.hpp
SRC = main.cpp \
	Harl.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@echo "$(INFO) => Starting build..$(NC)"
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo""
	@echo "$(BLUE)██╗░░██╗░█████╗░██████╗░██╗░░░░░$(NC)"
	@echo "$(BLUE)██║░░██║██╔══██╗██╔══██╗██║░░░░░$(NC)"
	@echo "$(BLUE)███████║███████║██████╔╝██║░░░░░$(NC)"
	@echo "$(BLUE)██╔══██║██╔══██║██╔══██╗██║░░░░░$(NC)"
	@echo "$(BLUE)██║░░██║██║░░██║██║░░██║███████╗$(NC)"
	@echo "$(BLUE)╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝╚══════╝$(NC)"
	@echo""
	@echo "$(OK)=> done$(NC)"

%.o: %.cpp $(HEADER)
	@$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all