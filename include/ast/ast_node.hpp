#ifndef AST_NODE_HPP
#define AST_NODE_HPP

#include <iostream>

class AST {
public:
    virtual std::string name() = 0;
    virtual void print(std::ostream& os, int level) {}
    static std::string indent(int num) {
        if (num == 0)
            return "";
        else
            return indent(num-1) + "\t|";
    }
protected:
};

#endif