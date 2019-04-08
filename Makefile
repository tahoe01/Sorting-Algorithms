CXXFLAGS=-std=c++14 -Wpedantic -Wall -Wextra -Werror -Weffc++ -Wzero-as-null-pointer-constant
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings

timing: timing.cpp
	echo ---------compiling timing.cpp--------------
	g++ -std=c++14 timing.cpp -o timing

clean: 
	rm timing