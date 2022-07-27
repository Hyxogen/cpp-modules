TARGET		:= test

SOURCES		:= main.cpp Data.cpp
HEADER_DEPS	:= $(addsuffix .d,$(SOURCES))
OBJECTS		:= $(addsuffix .o, $(SOURCES))

CXX		:= clang++
CXX_FLAGS	:= -I. -std=c++11 -Wall -Wextra -Werror -Wconversion -pedantic -O0 -g3 -fsanitize=address,undefined -MMD

SILENT		:= @
ifndef verbose
	SILENT	:=
endif

.PHONY: all
all: $(TARGET)

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

