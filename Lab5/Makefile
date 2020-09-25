CXX=g++

CXXFLAGS=-std=c++17 -Wall -Wextra -Wpedantic -Werror -Wfatal-errors -Winit-self -Wshadow -Wlogical-op -Wcomment -Wctor-dtor-privacy -Wold-style-cast -D_GLIBCXX_DEBUG -fno-diagnostics-show-option

OBJECTS = main.o ll.o

main: $(OBJECTS)
	  $(CXX) $(CXXFLAGS) -o $@ $^

$(OBJECTS):ll.h

clean:
	rm -rf $(OBJECTS)

link.tar: 
	tar -cvf link.tar Makefile main.cc ll.cc ll.h