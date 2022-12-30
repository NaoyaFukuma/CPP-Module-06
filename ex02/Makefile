NAME = Account


CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -MMD -MP
CPPFLAGS = -Iincludes

SRCS = tests.cpp Account.cpp
VPATH = srcs

OBJSDIR = objs
OBJS = $(addprefix $(OBJSDIR)/, $(SRCS:%.cpp=%.o))
DEPENDS = $(OBJS:.o=.d)

all: $(NAME)

-include $(DEPENDS)

$(NAME): $(OBJSDIR) $(OBJS)
	$(CXX) -o $(NAME) $(OBJS)

$(OBJSDIR)/%.o: %.cpp
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -o $@ -c $<

objs:
	mkdir -p objs

clean:
	$(RM) -rf $(OBJSDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
