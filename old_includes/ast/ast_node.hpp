#ifndef AST_NODE_HPP
#define AST_NODE_HPP

#include <iostream>


class AST {         // TODO: Destructors
public:
    virtual std::string name() = 0;
    virtual void print(std::ostream& os, int level) {}
    static std::string indent(int num) {
        if (num == 0)
            return "";
        else
            return indent(num-1) + "\t|";
    }

    virtual void print_py(std::ostream &os, PyContext &context){}

protected:
};

#endif