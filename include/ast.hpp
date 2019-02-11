#ifndef AST_HPP
#define AST_HPP

#include <iostream>
#include <memory>
#include <vector>

enum CType {
    BOOL,
    CHAR,
    DOUBLE,
    FLOAT,
    INT,
    LONG,
    REGISTER,
    SHORT,
    SIGNED,
    UNSIGNED,
    VOID
};

std::string print_CType(CType val);

class AST;
class Global;
class TopLevel;
class FunctionDeclaration;
class FunctionDefinition;
class Declaration;

class AST {
public:
    virtual ~AST() {}
    virtual void print(std::ostream& dst) const = 0;
    virtual void push_back(TopLevel* branch) {}
    const std::string name;
};

class TopLevel : public AST {};

class Global : public AST {
public:
    const std::string name = "Global";
    virtual void print(std::ostream& dst) const {
        for(int i = 0; i < (int)branches.size(); ++i) {
            dst << "\t" << branches[i]->name << std::endl;
        }
    }
    Global(TopLevel* first) {
        branches.push_back(first);
    }
    void push_back(TopLevel* branch) {
        branches.push_back(branch);
    }
protected:
    std::vector<TopLevel*> branches;
};

//**************************************************************
//----------------------- GLOBAL SCOPE -------------------------
//**************************************************************

class FunctionDeclaration : public TopLevel {
public:
    const std::string name = "FunctionDeclaration";
    virtual void print(std::ostream& dst) const {}
protected:
    
};

class FunctionDefinition : public TopLevel {
public:
    const std::string name = "FunctionDefinition";
    virtual void print(std::ostream& dst) const {}
protected:
    
};

class Declaration : public TopLevel {
public:
    const std::string name = "Declaration";
    virtual void print(std::ostream& dst) const {
        dst << "\t" << print_CType(type) << std::endl
            << variable << std::endl;
    }
    Declaration(CType _type, const std::string& _variable): type(_type), variable(_variable) {}
protected:
    CType type;
    std::string variable;
};

//**************************************************************
//------------------------ STATEMENTS --------------------------
//**************************************************************



//**************************************************************
//----------------------- EXPRESSIONS --------------------------
//**************************************************************

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