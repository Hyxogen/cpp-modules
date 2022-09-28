TARGET		:= test

SOURCES		:= main.cpp ClapTrap.cpp
HEADERS		:= ClapTrap.hpp
HEADER_DEPS	:= $(addsuffix .d,$(SOURCES))
OBJECTS		:= $(addsuffix .o, $(SOURCES))

CXX			:= c++
CXX_FLAGS	:= -I. -std=c++98 -Wall -Wextra -Werror -Wshadow -pedantic -O3 -g0 -MMD

SILENT		:= @
ifndef verbose
	SILENT	:=
endif

.PHONY: all
all: $(TARGET)

.PHONY: format
format:
	$(SILENT)clang-format -i $(SOURCES) $(HEADERS) 

$(TARGET): $(OBJECTS)
	$(SILENT)$(CXX) -o $(TARGET) $(OBJECTS) $(CXX_FLAGS)

-include $(HEADER_DEPS)
%.cpp.o: %.cpp
	$(SILENT)$(CXX) $(CXX_FLAGS) -o $@ -c $<

.PHONY: clean
clean:
	$(SILENT)rm -f $(OBJECTS) $(HEADER_DEPS)

.PHONY: fclean
fclean:
	$(SILENT)${MAKE} clean
	$(SILENT)rm -f $(TARGET)

.PHONY: re
re:
	${MAKE} fclean
	${MAKE} all

