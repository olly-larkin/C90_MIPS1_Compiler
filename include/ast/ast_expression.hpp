#ifndef AST_EXPRESSION_HPP
#define AST_EXPRESSION_HPP

#include "ast_node.hpp"

class Expression : public AST {};

class ArgumentExpressionList : public Expression {   //TODO: make this class
public:
    virtual std::string name() { return "Argument Expression List:"; };
private:
};

class Postfix_ArrIndex : public Expression {
public:
    Postfix_ArrIndex(Expression* _postfix, Expression* _index) : postfix(_postfix), index(_index) {}
    std::string name() { return "Array Index:"; }
    void print(std::ostream& os, int level) {
        os << indent(level) << "Array: " << postfix->name() << std::endl;
        postfix->print(os, level+1);
        os << indent(level) << "Index: " << index->name() << std::endl;
        index->print(os, level+1);
    }
protected:
    Expression *postfix, *index;
};

class Postfix_FnCall : public Expression {
public:
    Postfix_FnCall(Expression* _postfix) : postfix(_postfix), argList(NULL) {}
    Postfix_FnCall(Expression* _postfix, ArgumentExpressionList* _argList) : postfix(_postfix), argList(_argList) {}
    std::string name() { return "Function Call:"; }
    void print(std::ostream& os, int level) {
        os << indent(level) << "Function: " << postfix->name() << std::endl;
        postfix->print(os, level+1);
        if (argList != NULL) {
            os << indent(level) << "Arguments: " << argList->name() << std::endl;
            argList->print(os, level+1);
        }
    }
protected:
    Expression *postfix;
    ArgumentExpressionList *argList;
};

class Postfix_DotIdentifier : public Expression {
public:
    Postfix_DotIdentifier(Expression *_postfix, const std::string &_identifier) : postfix(_postfix), identifier(_identifier) {}
    std::string name() { return "Dot:"; }
    void print(std::ostream& os, int level) {
        os << indent(level) << "Identifier: " << std::endl << indent(level+1) << identifier << std::endl;
        os << indent(level) << postfix->name() << std::endl;
        postfix->print(os, level+1);
    }
protected:
    Expression *postfix;
    std::string identifier;
};

class Postfix_ArrowIdentifier : public Expression {
public:
    Postfix_ArrowIdentifier(Expression *_postfix, const std::string &_identifier) : postfix(_postfix), identifier(_identifier) {}
    std::string name() { return "Arrow:"; }
    void print(std::ostream& os, int level) {
        os << indent(level) << "Identifier: " << std::endl << indent(level+1) << identifier << std::endl;
        os << indent(level) << postfix->name() << std::endl;
        postfix->print(os, level+1);
    }
protected:
    Expression *postfix;
    std::string identifier;
};

class Postfix_DecOp : public Expression {
public:
    Postfix_DecOp(Expression *_postfix) : postfix(_postfix){} //TODO: make copy constructor?
    std::string name() { return "Post-assign decrement:"; }
    void print(std::ostream& os, int level){
        os << indent(level) << postfix->name() << std::endl;
        postfix->print(os, level+1);
    }
protected:
    Expression *postfix;
};

class Postfix_IncOp : public Expression {
public:
    Postfix_IncOp(Expression *_postfix) : postfix(_postfix){} //TODO: make copy constructor?
    std::string name() { return "Post-assign increment:"; }
    void print(std::ostream& os, int level){
        os << indent(level) << postfix->name() << std::endl;
        postfix->print(os, level+1);
    }
protected:
    Expression *postfix;
};

class PrimaryExp_Identifier : public Expression {
public:
    PrimaryExp_Identifier(const std::string &_identifier) : identifier(_identifier){}
    std::string name() { return "Identifier:"; }
    void print(std::ostream& os, int level){
        os << indent(level) << identifier << std::endl;
    }
protected:
    std::string identifier;
};


class PrimaryExp_Constant : public Expression {
public:
    PrimaryExp_Constant(double _constant) : constant(_constant){}
    std::string name() { return "Constant:"; }
    void print(std::ostream& os, int level){
        os << indent(level) << constant << std::endl;
    }
protected:
    double constant;
};


class PrimaryExp_StrLiteral : public Expression {
    public:
    PrimaryExp_StrLiteral(const std::string &_string) : string(_string){}
    std::string name() { return "String Literal:"; }
    void print(std::ostream& os, int level){
        os << indent(level) << string << std::endl;
    }
protected:
    std::string string;
};


class PrimaryExp_EnumVal : public Expression {
public:
    PrimaryExp_EnumVal(const std::string &_val) : val(_val){}
    std::string name() { return "Enum Value:"; }
    void print(std::ostream& os, int level){
        os << indent(level) << val << std::endl;
    }
protected:
    std::string val;
};


#endif