# Reset
NC      := \033[0m

# Regular colors
MAGENTA := \033[0;35m
OK    	:= \033[1;32m
INFO 	:= \033[1;36m

NAME = Account
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

HEADER = Account.hpp
SRC = Account.cpp \
		tests.cpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@echo "$(INFO) => Starting build..$(NC)"
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo ""
	@echo "$(MAGENTA)░█████╗░░█████╗░░█████╗░░█████╗░██╗░░░██╗███╗░░██╗████████╗$(NC)"
	@echo "$(MAGENTA)██╔══██╗██╔══██╗██╔══██╗██╔══██╗██║░░░██║████╗░██║╚══██╔══╝$(NC)"
	@echo "$(MAGENTA)███████║██║░░╚═╝██║░░╚═╝██║░░██║██║░░░██║██╔██╗██║░░░██║░░░$(NC)"
	@echo "$(MAGENTA)██╔══██║██║░░██╗██║░░██╗██║░░██║██║░░░██║██║╚████║░░░██║░░░$(NC)"
	@echo "$(MAGENTA)██║░░██║╚█████╔╝╚█████╔╝╚█████╔╝╚██████╔╝██║░╚███║░░░██║░░░$(NC)"
	@echo "$(MAGENTA)╚═╝░░╚═╝░╚════╝░░╚════╝░░╚════╝░░╚═════╝░╚═╝░░╚══╝░░░╚═╝░░░$(NC)"
	@echo ""
	@echo "$(OK)=> done$(NC)"

%.o: %.cpp $(HEADER)
	@$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)	
	
re: fclean all