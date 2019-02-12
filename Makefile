CPPFLAGS += -std=c++11 -W -Wall -g -Wno-unused-parameter -Wno-unneeded-internal-declaration -Wno-unused-function
CPPFLAGS += -I include

all : bin/print_tree

src/compiler_bison.tab.cpp src/compiler_bison.tab.hpp : src/compiler_bison.y
	bison -v -d src/compiler_bison.y -o src/compiler_bison.tab.cpp

src/lexer.yy.cpp : src/lexer.flex src/compiler_bison.tab.hpp
	flex -o src/lexer.yy.cpp  src/lexer.flex

bin/print_tree : src/print_tree.o src/compiler_bison.tab.o src/lexer.yy.o src/compiler_bison.tab.o
	mkdir -p bin
	g++ $(CPPFLAGS) -o bin/print_tree $^

clean :
	@rm -rf src/*.o
	@rm -rf bin
	@rm -rf src/*.tab.cpp
	@rm -rf src/*.yy.cpp
	@rm -rf src/*.output
	@rm -rf src/*.tab.hpp
	@rm -rf test/*.got.txt
	@echo "all clean."