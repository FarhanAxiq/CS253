CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++17 -g -fsanitize=address
LDFLAGS =  -fsanitize=address

SRC = HW1.cc
OBJ = $(SRC:.cc=.o)
EXEC = HW1

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ) $(LBLIBS)

clean:
	rm -rf $(OBJ) $(EXEC)

tar: 
	HW1.tar: $(shell HW1) tar -zcvf HW1.tar HW1