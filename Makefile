CXXFLAGS=-std=c++14 -Wpedantic -Wall -Wextra -Werror -Weffc++ -Wzero-as-null-pointer-constant
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Werror -ansi -Wwrite-strings

bubble-sort: bubble-sort.cpp
	echo ---------compiling bubble-sort.cpp--------------
	g++ -std=c++14 bubble-sort.cpp -o bubble-sort

clean: 
	rm bubble-sort