CXXOPTS=-Wall -Wextra -Wpedantic -fprofile-arcs -ftest-coverage
code: code.cc
	g++ $(CXXOPTS) -DNDEBUG $^ -o $@

clean:
	-rm -f code *.o *.gcov *.gcda *.gcno
