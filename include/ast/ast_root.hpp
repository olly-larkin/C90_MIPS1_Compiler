#ifndef AST_NODE_HPP
#define AST_NODE_HPP

#include <iostream>

#include "../PyContext.hpp"

class AST {
public:

    static std::string indent(int num) {
        if (num == 0)
            return "";
        else
            return indent(num-1) + "\t|";
    }
    
    virtual ~AST() {}
    virtual void print(std::ostream& os, int level) {}
    virtual void printPy(std::ostream &os, PyContext &context) {}
    virtual void generateMIPS() {}  //TODO: code gen
protected:
};

#endif