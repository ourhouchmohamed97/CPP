# Reset
NC      := \033[0m

# Regular colors
RED     := \033[0;31m
YELLOW  := \033[0;33m
BLUE    := \033[0;34m
MAGENTA := \033[0;35m
OK    	:= \033[1;32m
INFO 	:= \033[1;36m
WHITE   := \033[0;37m


NAME = PhoneBook
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

HEADER = PhoneBook.hpp
SRC = PhoneBook.cpp \
		Contact.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@echo "$(INFO) => Starting build..$(NC)"
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo ""
	@echo "$(MAGENTA)██████╗░██╗░░██╗░█████╗░███╗░░██╗███████╗  ██████╗░░█████╗░░█████╗░██╗░░██╗$(NC)"
	@echo "$(MAGENTA)██╔══██╗██║░░██║██╔══██╗████╗░██║██╔════╝  ██╔══██╗██╔══██╗██╔══██╗██║░██╔╝$(NC)"
	@echo "$(MAGENTA)██████╔╝███████║██║░░██║██╔██╗██║█████╗░░  ██████╦╝██║░░██║██║░░██║█████═╝░$(NC)"
	@echo "$(MAGENTA)██╔═══╝░██╔══██║██║░░██║██║╚████║██╔══╝░░  ██╔══██╗██║░░██║██║░░██║██╔═██╗░$(NC)"
	@echo "$(MAGENTA)██║░░░░░██║░░██║╚█████╔╝██║░╚███║███████╗  ██████╦╝╚█████╔╝╚█████╔╝██║░╚██╗$(NC)"
	@echo "$(MAGENTA)╚═╝░░░░░╚═╝░░╚═╝░╚════╝░╚═╝░░╚══╝╚══════╝  ╚═════╝░░╚════╝░░╚════╝░╚═╝░░╚═╝$(NC)"
	@echo ""
	@echo "$(OK)=> done$(NC)"

%.o: %.cpp $(HEADER)
	@$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all
