ifeq ($(origin CXX), default)
CXX = c++
endif

ifeq ($(origin RM), default)
RM = rm -rf
endif

TARGET = phonebook
override CXXFLAGS += -Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp Phonebook.cpp Contact.cpp
HEADERS = Phonebook.hpp Contact.hpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(OBJS): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJS) Makefile $(HEADERS)              
	$(CXX) -I. $(CXXFLAGS) $(OBJS) -o $@ 

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(TARGET) 

re: fclean all

.PHONY: all clean fclean re

