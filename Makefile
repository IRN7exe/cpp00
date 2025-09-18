ifeq ($(origin CXX), default)
CXX = c++
endif

ifeq ($(origin RM), default)
RM = rm -rf
endif

TARGET = megaphone
override CXXFLAGS += -Wall -Wextra -Werror -std=c++98

SRCS =	megaphone.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(OBJS): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(TARGET): $(OBJS) Makefile               
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@ 

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(TARGET) 

re: fclean all

.PHONY: all clean fclean re

