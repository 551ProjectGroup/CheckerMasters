checkers: main.cpp boardstate.cpp
	g++ -ggdb3 -pedantic -Werror -Wall --std=gnu++98 -o checkers main.cpp boardstate.cpp

