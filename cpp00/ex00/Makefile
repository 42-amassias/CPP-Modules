CXX			:=	c++

CPPFLAGS	:=	-Wall -Wextra -Werror -std=c++98

NAME		:=	megaphone

BUILD_DIR	:=	build

RM			:=	rm -f

FILES		:=				\
				Megaphone

SRCS		:=	$(addsuffix .cpp,$(FILES))

OBJS		:=	$(addprefix $(BUILD_DIR)/,$(addsuffix .o,$(FILES)))

.PHONY: all clean fclean re

all: $(NAME)

clean:
	$(RM) -r $(BUILD_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

$(NAME): $(OBJS)
	$(CXX) -o $@ $^ $(LFLAGS)

$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) -o $@ -c $< $(CPPFLAGS)