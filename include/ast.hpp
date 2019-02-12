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
    virtual void print(std::ostream& dst, int level) const = 0;
    virtual void push_back(TopLevel* branch) {}
    virtual std::string name() = 0;
};

class TopLevel : public AST {};

class Global : public AST {
public:
    std::string name() {return "Global";}
    virtual void print(std::ostream& dst, int level) const {
        for(int i = 0; i < (int)branches.size(); ++i) {
            for (int j = 0; j < level; ++j)
                dst << "\t";
            dst << branches[i]->name() << std::endl;
            branches[i]->print(dst, level+1);
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
    std::string name() {return "FunctionDeclaration";}
    virtual void print(std::ostream& dst, int level) const {}
protected:
    
};

class FunctionDefinition : public TopLevel {
public:
    std::string name() {return "FunctionDefinition";}
    virtual void print(std::ostream& dst, int level) const {}
protected:
    
};

class Declaration : public TopLevel {
public:
    std::string name() {return "Declaration";}
    virtual void print(std::ostream& dst, int level) const {
        for (int i = 0; i < level; ++i)
            dst << "\t";
        dst << print_CType(type) << std::endl;
        for (int i = 0; i < level; ++i)
            dst << "\t";
        dst << variable << std::endl;
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

extern AST* parseAST();

#endif