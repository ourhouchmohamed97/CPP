# Reset
NC      := \033[0m

# Regular colors
OOP_BLUE := \033[38;2;58;86;156m
OK    	:= \033[1;32m
INFO 	:= \033[1;36m


NAME = Interface
CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -rf

HEADER = AMateria.hpp \
		 Cure.hpp \
		 Ice.hpp \
		 ICharacter.hpp \
		 Character.hpp \
		 MateriaSource.hpp \
		 IMateriaSource.hpp

SRC = main.cpp \
	  AMateria.cpp \
	  Cure.cpp \
	  Ice.cpp \
	  MateriaSource.cpp \
	  Character.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@echo "$(INFO) => Starting build..$(NC)"
	@$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)
	@echo ""
	@echo "$(OOP_BLUE)██╗███╗░░██╗████████╗███████╗██████╗░███████╗░█████╗░░█████╗░███████╗$(NC)"
	@echo "$(OOP_BLUE)██║████╗░██║╚══██╔══╝██╔════╝██╔══██╗██╔════╝██╔══██╗██╔══██╗██╔════╝$(NC)"
	@echo "$(OOP_BLUE)██║██╔██╗██║░░░██║░░░█████╗░░██████╔╝█████╗░░███████║██║░░╚═╝█████╗░░$(NC)"
	@echo "$(OOP_BLUE)██║██║╚████║░░░██║░░░██╔══╝░░██╔══██╗██╔══╝░░██╔══██║██║░░██╗██╔══╝░░$(NC)"
	@echo "$(OOP_BLUE)██║██║░╚███║░░░██║░░░███████╗██║░░██║██║░░░░░██║░░██║╚█████╔╝███████╗$(NC)"
	@echo "$(OOP_BLUE)╚═╝╚═╝░░╚══╝░░░╚═╝░░░╚══════╝╚═╝░░╚═╝╚═╝░░░░░╚═╝░░╚═╝░╚════╝░╚══════╝$(NC)"
	@echo ""
	@echo "$(OK)=> done$(NC)"

%.o: %.cpp $(HEADER)
	@$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all