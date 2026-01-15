# Reset
NC      := \033[0m

# Regular colors
NEON_CYAN := \033[38;2;0;255;255m
OK    	:= \033[1;32m
INFO 	:= \033[1;36m


NAME = Bureaucrat
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf


HEADER = Bureaucrat.hpp
SRC = main.cpp \
	  Bureaucrat.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@echo "$(INFO) => Starting build..$(NC)"
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo ""
	@echo "$(NEON_CYAN)██████╗░██╗░░░██╗██████╗░███████╗░█████╗░██╗░░░██╗░█████╗░██████╗░░█████╗░████████╗$(NC)"
	@echo "$(NEON_CYAN)██╔══██╗██║░░░██║██╔══██╗██╔════╝██╔══██╗██║░░░██║██╔══██╗██╔══██╗██╔══██╗╚══██╔══╝$(NC)"
	@echo "$(NEON_CYAN)██████╦╝██║░░░██║██████╔╝█████╗░░███████║██║░░░██║██║░░╚═╝██████╔╝███████║░░░██║░░░$(NC)"
	@echo "$(NEON_CYAN)██╔══██╗██║░░░██║██╔══██╗██╔══╝░░██╔══██║██║░░░██║██║░░██╗██╔══██╗██╔══██║░░░██║░░░$(NC)"
	@echo "$(NEON_CYAN)██████╦╝╚██████╔╝██║░░██║███████╗██║░░██║╚██████╔╝╚█████╔╝██║░░██║██║░░██║░░░██║░░░$(NC)"
	@echo "$(NEON_CYAN)╚═════╝░░╚═════╝░╚═╝░░╚═╝╚══════╝╚═╝░░╚═╝░╚═════╝░░╚════╝░╚═╝░░╚═╝╚═╝░░╚═╝░░░╚═╝░░░$(NC)"
	@echo ""
	@echo "$(OK)=> done$(NC)"

%.o: %.cpp $(HEADER)
	@$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all