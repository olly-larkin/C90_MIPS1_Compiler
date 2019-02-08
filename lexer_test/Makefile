CPPFLAGS += -W -Wall -g 

# This avoids error: ‘fileno’ was not declared in this scope
CPPFLAGS += -std=c++0x -I ../include

# Avoid warnings about yyunput not used
CPPFLAGS += -Wno-unused-function -Wno-unused-parameter

all : Parse

lexer.yy.cpp : ../src/lexer.flex
	flex -o lexer.yy.cpp  ../src/lexer.flex

Parse : lexer.yy.o Parse.o PrettyPrint.o
	mkdir -p bin
	g++ $(CPPFLAGS) -o bin/Parse $^

clean:
	rm -rf *.o *.yy.cpp bin/*