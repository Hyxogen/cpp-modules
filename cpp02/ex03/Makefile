TARGET		:= test

SOURCES		:= main.cpp Fixed.cpp Point.cpp bsp.cpp
HEADERS		:= Fixed.hpp
OBJECTS		:= $(addsuffix .o, $(SOURCES))

CXX			:= c++
CXX_FLAGS	:= -std=c++98 -Wall -Wextra -Werror -pedantic -O0 -g3

SILENT		:= @
ifndef verbose
	SILENT	:=
endif

all: $(TARGET)

format:
	$(SILENT)clang-format -i $(SOURCES) $(HEADERS) 

$(TARGET): $(OBJECTS)
	$(SILENT)$(CXX) -o $(TARGET) $(OBJECTS) $(CXX_FLAGS)

%.cpp.o: %.cpp
	$(SILENT)$(CXX) -o $@ -c $< $(CXX_FLAGS)

clean:
	$(SILENT)rm -f $(OBJECTS)

fclean:
	$(SILENT)${MAKE} clean
	$(SILENT)rm -f $(TARGET)

re:
	${MAKE} fclean
	${MAKE} all
