TARGET		:= nokia

SOURCES		:= Main.cpp PhoneBook.cpp Contact.cpp Util.cpp
HEADERS		:= PhoneBook.h Contact.h Util.h TableFmt.h Lexical_Cast.h
OBJECTS		:= $(addsuffix .o, $(SOURCES))

CXX			:= clang++
CXX_FLAGS	:= -std=c++98 -Wall -Wextra -Werror -pedantic -O3 -g0

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
