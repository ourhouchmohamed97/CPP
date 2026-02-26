# Reset
NC      := \033[0m

# Regular colors
DIGITAL_GOLD := \033[38;2;255;185;50m
OK    	:= \033[1;32m
INFO 	:= \033[1;36m

NAME = btc
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

HEADER = BitcoinExchange.hpp
SRC = main.cpp \
	  BitcoinExchange.cpp 
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@echo "$(INFO) => Starting build..$(NC)"
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo ""
	@echo "$(DIGITAL_GOLD)██████╗░██╗████████╗░█████╗░░█████╗░██╗███╗░░██╗$(NC)"
	@echo "$(DIGITAL_GOLD)██╔══██╗██║╚══██╔══╝██╔══██╗██╔══██╗██║████╗░██║$(NC)"
	@echo "$(DIGITAL_GOLD)██████╦╝██║░░░██║░░░██║░░╚═╝██║░░██║██║██╔██╗██║$(NC)"
	@echo "$(DIGITAL_GOLD)██╔══██╗██║░░░██║░░░██║░░██╗██║░░██║██║██║╚████║$(NC)"
	@echo "$(DIGITAL_GOLD)██████╦╝██║░░░██║░░░╚█████╔╝╚█████╔╝██║██║░╚███║$(NC)"
	@echo "$(DIGITAL_GOLD)╚═════╝░╚═╝░░░╚═╝░░░░╚════╝░░╚════╝░╚═╝╚═╝░░╚══╝$(NC)"

	@echo ""
	@echo "$(OK)=> done$(NC)"

%.o: %.cpp $(HEADER)
	@$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all