NAME = bureaucrat

CPPC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =  main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp \
		ShrubberyCreationForm.cpp RobotomyRequestForm.cpp Intern.cpp

OBJS = $(SRCS:.cpp=.o)

all = $(NAME)

$(NAME) : $(OBJS)
	$(CPPC) $(CPPFLAGS) $(OBJS) -o $(NAME)

%.o : %.cpp
	$(CPPC) $(CPPFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re