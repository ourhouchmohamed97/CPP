# Reset
NC      := \033[0m

# Regular colors
BIOLUME_LIME := \033[38;2;204;255;0m
OK    	:= \033[1;32m
INFO 	:= \033[1;36m

NAME = MutantStack
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

HEADER = MutantStack.hpp
SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@echo "$(INFO) => Starting build..$(NC)"
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo ""
	@echo "$(BIOLUME_LIME)███╗░░░███╗██╗░░░██╗████████╗░█████╗░███╗░░██╗████████╗░██████╗████████╗░█████╗░░█████╗░██╗░░██╗$(NC)"
	@echo "$(BIOLUME_LIME)████╗░████║██║░░░██║╚══██╔══╝██╔══██╗████╗░██║╚══██╔══╝██╔════╝╚══██╔══╝██╔══██╗██╔══██╗██║░██╔╝$(NC)"
	@echo "$(BIOLUME_LIME)██╔████╔██║██║░░░██║░░░██║░░░███████║██╔██╗██║░░░██║░░░╚█████╗░░░░██║░░░███████║██║░░╚═╝█████═╝░$(NC)"
	@echo "$(BIOLUME_LIME)██║╚██╔╝██║██║░░░██║░░░██║░░░██╔══██║██║╚████║░░░██║░░░░╚═══██╗░░░██║░░░██╔══██║██║░░██╗██╔═██╗░$(NC)"
	@echo "$(BIOLUME_LIME)██║░╚═╝░██║╚██████╔╝░░░██║░░░██║░░██║██║░╚███║░░░██║░░░██████╔╝░░░██║░░░██║░░██║╚█████╔╝██║░╚██╗$(NC)"
	@echo "$(BIOLUME_LIME)╚═╝░░░░░╚═╝░╚═════╝░░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚══╝░░░╚═╝░░░╚═════╝░░░░╚═╝░░░╚═╝░░╚═╝░╚════╝░╚═╝░░╚═╝$(NC)"
	@echo ""
	@echo "$(OK)=> done$(NC)"

%.o: %.cpp $(HEADER)
	@$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all