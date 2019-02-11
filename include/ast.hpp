#ifndef AST_HPP
#define AST_HPP

#include <iostream>
#include <memory>
#include <vector>

class AST {
public:
    virtual void print(std::ostream& dst) const = 0;
};

class TopLevel : public AST {};

class FunctionDeclaration : public TopLevel {
public:
    virtual void print(std::ostream& dst) const {}
private:
    
};

class Number : public AST {
public:
    Number(double num): val(num) {}
    void print(std::ostream& dst) const {
        dst << val;
    }
private:
    double val;
};

extern const AST* parseAST();

#endif