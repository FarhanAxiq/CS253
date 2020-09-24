#
#	Lab 04
#	Farhan Haziq
#	Sept 18th, 2020
#
# This is a Makefile.  Its purpose is to create the program “small”.
#
# The rules, below, indicate what depends on what, and how to build
# things when they get out-of-date.  It is VERY important to know that
# what looks like eight leading spaces is really a leading tab
# character.  Leading spaces won’t work--it MUST be a tab character.
#
# For the following questions, do the command if there is one,
# and then answer the question.  If you need another line for you
# answer, continue it on the next line.
#
# As an example, I’ve already answered (1), which has nothing to do
# with anything else in this lab.
#
# Question 1 is worth 0.09 points; questions 2–14 are worth 0.07
# points each.
#
#  1) Command:  date +%A
#     Question: Describe the output of that command.
#     Answer:   It’s today’s day of the week.
#
#  2) Command:  make
#     Question: Describe what happens.  Don’t just write the commands;
#     		describe what each command does.
#     Answer:   execute the command and create executable file as defined as in the makefile
# 
#  3) Command:  ./small
#     Question: What is the output?  Reproduce the output exactly.
#     Answer:   Hi from main at main.cc:15
#				Hi from foo at foo.cc:14
#
#  4) Command:  make
#     Question: Why did nothing much happen?
#     Answer:   because the file is already compiled and executable has been created, therefore no need to do anything
#
#  5) Command:  rm small; make
#     Question: What got remade, and why?
#     Answer:   the executable small, because we deleted the executable with rm cmd
#
#  6) Command:  rm foo.o; make 
#     Question: What got remade, and why?
#     Answer:   the executable foo, because we deleted the executable with rm cmd
#
#  7) Command:  make clean 
#     Question: What did that do?
#     Answer:   delete all the generated executable
#
#  8) Command:  make 
#     Question: What got remade, and why?
#     Answer:   all the executable described in makefile as it have been cleared by the make clean command
#
#  9) Question: Why does main.o depend on foo.h?
#		I know that it’s because the Makefile says so.
#		Why was that dependency put into the Makefile?
#     Answer:   because we included the foo.h in the main.cc and the function prototype for foo.h is defined in foo.cc
#
# 10) Command:  Create a new function bar() in bar.cc & bar.h,
# 		similar to foo.cc.  Change main.cc to call the new
# 		bar() function, and type “make”.
#     Question: Why did it fail?
#     Answer:   because it isn't defined in the makefile
#
# 11) Command:  Fix the Makefile; verify with “make” until it compiles.
#     Question: Describe your changes.  Don’t just show the changed
#     		lines--describe the purpose of each change.
#     Answer:   added declaration for the bar so to let makefile know what to do with it.
#
# 12) Command:  Uncomment the CXXFLAGS= line, and type “make”.
#     Question: Why didn't anything happen?
#     Answer:   because everything is already compiled, so makefile didn't do anything
#
# 13) Command:  Force a rebuild with: make clean; make 
#     Question: What’s new about the commands executed?
#     Answer:   now with warning
#
# 14) Command: 	make clean; ls -l clean
#     Question: The target is “clean”, but no file “clean” got created.
#     		Why not?
#     Answer:  it sucessfully execute the first command but fail to do the second
#			   which is listing the directory in clean which doesn't exist
#			   it's the same as typing the command like this:
#			   $ make clean
#			   $ ls -l clean
#
# For extra fame & glory (but no extra points):
#
# 15) Command:  Consult the make manual at
# 		https://www.gnu.org/software/make/manual/make.html
#		and improve this Makefile by using $@ in the rule
#		that creates “small” itself.

# The CXX variable contains the name of the C++ compiler.  You can’t
# have plus signs in a Make variable, so X is a rotated plus sign.
CXX=g++

CXXFLAGS=-std=c++17 -Wall -Wextra -Wpedantic -Werror -Wfatal-errors -Winit-self -Wshadow -Wlogical-op -Wcomment -Wctor-dtor-privacy -Wold-style-cast -D_GLIBCXX_DEBUG -fno-diagnostics-show-option

small: main.o foo.o
	$(CXX) $(CXXFLAGS) main.o foo.o -o small

main.o: main.cc foo.h
	$(CXX) $(CXXFLAGS) -c main.cc

#foo.o: foo.cc foo.h
#	$(CXX) $(CXXFLAGS) -c foo.cc

bar.o: bar.cc bar.h
	$(CXX) $(CXXFLAGS) -c bar.cc

clean:
	-rm -f small *.o