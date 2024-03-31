ECHO	:=	/usr/bin/echo
RM		:=	/usr/bin/rm -f
CXX		:=	/usr/bin/c++

SRC		:=	Megaphone

OBJ		:=	$(addsuffix .o,$(SRC))
SRC		:=	$(addsuffix .cpp,$(SRC))

CFLAG	:=	-Wall -Wextra -Werror -std=c++98

NAME	:=	megaphone

.PHONY: clean fclean re

all: $(NAME)

clean:
	$(RM) $(NAME)

fclean: clean
	$(RM) $(OBJ)

re: fclean all

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LFLAGS)

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CLFAGS)
