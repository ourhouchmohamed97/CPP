# Reset
NC      := \033[0m

# Regular colors
RPN_STACK := \033[38;2;0;255;160m
OK    	:= \033[1;32m
INFO 	:= \033[1;36m

NAME = RPN
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

HEADER = RPN.hpp
SRC = main.cpp \
	  RPN.cpp 
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@echo "$(INFO) => Starting build..$(NC)"
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo ""
	@echo "$(RPN_STACK)██████╗░██████╗░███╗░░██╗$(NC)"
	@echo "$(RPN_STACK)██╔══██╗██╔══██╗████╗░██║$(NC)"
	@echo "$(RPN_STACK)██████╔╝██████╔╝██╔██╗██║$(NC)"
	@echo "$(RPN_STACK)██╔══██╗██╔═══╝░██║╚████║$(NC)"
	@echo "$(RPN_STACK)██║░░██║██║░░░░░██║░╚███║$(NC)"
	@echo "$(RPN_STACK)╚═╝░░╚═╝╚═╝░░░░░╚═╝░░╚══╝$(NC)"
	@echo ""
	@echo "$(OK)=> done$(NC)"

%.o: %.cpp $(HEADER)
	@$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all