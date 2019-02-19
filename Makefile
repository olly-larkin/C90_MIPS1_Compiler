CPPFLAGS += -std=c++11 -W -Wall -g -Wno-unused-parameter -Wno-unneeded-internal-declaration -Wno-unused-function
CPPFLAGS += -I include

CMPSRC:= compiler_src
TRNSRC:= translator_src

all : bin/print_tree

$(CMPSRC)/compiler_bison.tab.cpp $(CMPSRC)/compiler_bison.tab.hpp : $(CMPSRC)/compiler_bison.y
	bison -v -d $(CMPSRC)/compiler_bison.y -o $(CMPSRC)/compiler_bison.tab.cpp

$(CMPSRC)/lexer.yy.cpp : $(CMPSRC)/lexer.flex $(CMPSRC)/compiler_bison.tab.hpp
	flex -o $(CMPSRC)/lexer.yy.cpp  $(CMPSRC)/lexer.flex

bin/print_tree : $(CMPSRC)/print_tree.o $(CMPSRC)/compiler_bison.tab.o $(CMPSRC)/lexer.yy.o $(CMPSRC)/compiler_bison.tab.o
	mkdir -p bin
	g++ $(CPPFLAGS) -o bin/print_tree $^

clean :
	@rm -rf bin
	@rm -rf $(CMPSRC)/*.o
	@rm -rf $(CMPSRC)/*.tab.cpp
	@rm -rf $(CMPSRC)/*.yy.cpp
	@rm -rf $(CMPSRC)/*.output
	@rm -rf $(CMPSRC)/*.tab.hpp
	@rm -rf $(TRNSRC)/*.o
	@rm -rf $(TRNSRC)/*.tab.cpp
	@rm -rf $(TRNSRC)/*.yy.cpp
	@rm -rf $(TRNSRC)/*.output
	@rm -rf $(TRNSRC)/*.tab.hpp
	@echo "\nall clean.\n"