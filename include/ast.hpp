#ifndef AST_HPP
#define AST_HPP

#include <iostream>
#include <memory>
#include <vector>

//**************************************************************
//-------------------------- CLASSES ---------------------------
//**************************************************************

class AST;
class TopLevel;
class Global;
class FunctionDeclaration;
class FunctionDefinition;
class Statement;
class Declaration;
class Expression;

//**************************************************************

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
    std::vector<std::string*> arguments;
    std::string funcName;
};

class FunctionDefinition : public TopLevel {
public:
    std::string name() {return "FunctionDefinition";}
    virtual void print(std::ostream& dst, int level) const {}
protected:
    std::vector<Declaration*> arguments;
    std::string funcName;
    Statement* body;
};

//**************************************************************
//------------------------ STATEMENTS --------------------------
//**************************************************************

class Statement : public AST {};

class Block : public Statement {
public:
    std::string name() {return "Block";}
    virtual void print(std::ostream& dst, int level) const {
        for(int i = 0; i < (int)branches.size(); ++i) {
            for (int j = 0; j < level; ++j)
                dst << "\t";
            dst << branches[i]->name() << std::endl;
            branches[i]->print(dst, level+1);
        }
    }
    Block(const std::vector<Statement*>& _branches) : branches(_branches) {}
private:
    std::vector<Statement*> branches;
};

class Declaration : public Statement, public TopLevel {
public:
    std::string name() {return "Declaration";}
    virtual void print(std::ostream& dst, int level) const {
        for (int i = 0; i < level; ++i)
            dst << "\t";
        dst << type << std::endl;
        for (int i = 0; i < level; ++i)
            dst << "\t";
        dst << variable << std::endl;
    }
    Declaration(const std::string& _type, const std::string& _variable): type(_type), variable(_variable) {}
protected:
    std::string type;
    std::string variable;
};

//**************************************************************
//----------------------- EXPRESSIONS --------------------------
//**************************************************************

class Expression : public AST {};

//**************************************************************

extern AST* parseAST();

#endif