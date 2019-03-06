#ifndef AST_EXPRESSION_HPP
#define AST_EXPRESSION_HPP

#include "ast_node.hpp"
#include <vector>
#include <string>

class Expression : public AST {};

//************************************************************
//----------------ARGUMENT EXPRESSION LIST--------------------
//************************************************************

class ArgumentExpressionList : public Expression {
public:
    ArgumentExpressionList(ArgumentExpressionList *_arg_expr_list, Expression *_expression) : arg_expr_list(_arg_expr_list), expression(_expression) {}
    ArgumentExpressionList(Expression *_expression) : arg_expr_list(NULL), expression(_expression) {}
    std::string name() { return "Argument Expression List:"; }
    void print(std::ostream &os, int level) {
        if (arg_expr_list != NULL)
            arg_expr_list->print(os, level);
        os << indent(level) << expression->name() << std::endl;
        expression->print(os, level+1);
    }

    virtual void print_py(std::ostream &os, PyContext &context){
        if (arg_expr_list != NULL) {
            arg_expr_list->print_py(os, context);
            os << ", ";
        }
        expression->print_py(os, context);
    }

protected:
    ArgumentExpressionList *arg_expr_list;
    Expression *expression;
};

//************************************************************
//------------------ASSIGNMENT EXPRESSION---------------------
//************************************************************

class Assignment : public Expression {
public:
    Assignment(Expression *_unary_expression, Expression *_assignment_expression, char _flag) : unary_expression(_unary_expression), assignment_expression(_assignment_expression), flag(_flag) {}
    std::string name() { return "Assignment:"; }
    void print(std::ostream& os, int level) {
        os << indent(level) << flag << std::endl;
        os << indent(level) << unary_expression->name() << std::endl;
        unary_expression->print(os, level+1);
        os << indent(level) << assignment_expression->name() << std::endl;
        assignment_expression->print(os, level+1);
    }

    virtual void print_py(std::ostream &os, PyContext &context){
        //TODO: WARNING: currently ignoring flag
        unary_expression->print_py(os, context);
        os << " = ";
        assignment_expression->print_py(os, context);
    }

protected:
    Expression *unary_expression, *assignment_expression;
    char flag;
};

//************************************************************
//-----------------CONDITIONAL EXPRESSION---------------------
//************************************************************

class ConditionalOp : public Expression {
public:
    ConditionalOp(Expression *_logical_or_expression, Expression *_expression, Expression *_cond_expression) : logical_or_expression(_logical_or_expression), expression(_expression), cond_expression(_cond_expression) {}
    std::string name() { return "Conditional:"; }
    void print(std::ostream& os, int level) {
        os << indent(level) << "Condition: " << logical_or_expression->name() << std::endl;
        logical_or_expression->print(os, level+1);
        os << indent(level) << "If true: " << expression->name() << std::endl;
        expression->print(os, level+1);
        os << indent(level) << "If false: " << cond_expression->name() << std::endl;
        cond_expression->print(os, level+1);
    }
protected:
    Expression *logical_or_expression, *expression, *cond_expression;
};

//************************************************************
//------------------LOGICAL OR EXPRESSION---------------------
//************************************************************

class LogicalOROp : public Expression {
public:
    LogicalOROp(Expression *_logical_or_expression, Expression *_logical_and_expression) : logical_or_expression(_logical_or_expression), logical_and_expression(_logical_and_expression) {}
    std::string name() { return "Logical OR:"; }
    void print(std::ostream& os, int level) {
        os << indent(level) << logical_or_expression->name() << std::endl;
        logical_or_expression->print(os, level+1);
        os << indent(level) << logical_and_expression->name() << std::endl;
        logical_and_expression->print(os, level+1);
    }

    virtual void print_py(std::ostream &os, PyContext &context){
        os << "(";
        logical_or_expression->print_py(os, context);
        os << " or ";
        logical_and_expression->print_py(os, context);
        os << ")";
    }

protected:
    Expression *logical_or_expression, *logical_and_expression;
};

//************************************************************
//------------------LOGICAL AND EXPRESSION--------------------
//************************************************************

class LogicalANDOp : public Expression {
public:
    LogicalANDOp(Expression *_logical_and_expression, Expression *_inclusive_or_expression) : logical_and_expression(_logical_and_expression), inclusive_or_expression(_inclusive_or_expression) {}
    std::string name() { return "Logical AND:"; }
    void print(std::ostream& os, int level) {
        os << indent(level) << logical_and_expression->name() << std::endl;
        logical_and_expression->print(os, level+1);
        os << indent(level) << inclusive_or_expression->name() << std::endl;
        inclusive_or_expression->print(os, level+1);
    }

    virtual void print_py(std::ostream &os, PyContext &context){
        os << "(";
        logical_and_expression->print_py(os, context);
        os << " and ";
        inclusive_or_expression->print_py(os, context);
        os << ")";
    }

protected:
    Expression *logical_and_expression, *inclusive_or_expression;
};

//************************************************************
//-----------------INCLUSIVE OR EXPRESSION--------------------
//************************************************************

class BitwiseInclusiveOROp : public Expression {
public:
    BitwiseInclusiveOROp(Expression *_inclusive_or_expression, Expression *_exclusive_or_expression) : inclusive_or_expression(_inclusive_or_expression), exclusive_or_expression(_exclusive_or_expression) {}
    std::string name() { return "Bitwise Inclusive OR:"; }
    void print(std::ostream& os, int level) {
        os << indent(level) << inclusive_or_expression->name() << std::endl;
        inclusive_or_expression->print(os, level+1);
        os << indent(level) << exclusive_or_expression->name() << std::endl;
        exclusive_or_expression->print(os, level+1);
    }
protected:
    Expression *inclusive_or_expression, *exclusive_or_expression;
};

//************************************************************
//-----------------EXCLUSIVE OR EXPRESSION--------------------
//************************************************************

class BitwiseExclusiveOROp : public Expression {
public:
    BitwiseExclusiveOROp(Expression *_exclusive_or_expression, Expression *_and_expression) : exclusive_or_expression(_exclusive_or_expression), and_expression(_and_expression) {}
    std::string name() { return "Bitwise Exclusive OR:"; }
    void print(std::ostream& os, int level) {
        os << indent(level) << exclusive_or_expression->name() << std::endl;
        exclusive_or_expression->print(os, level+1);
        os << indent(level) << and_expression->name() << std::endl;
        and_expression->print(os, level+1);
    }
protected:
    Expression *exclusive_or_expression, *and_expression;
};

//************************************************************
//----------------------AND EXPRESSION------------------------
//************************************************************

class BitwiseANDOp : public Expression {
public:
    BitwiseANDOp(Expression *_and_expression, Expression *_equality_expression) : and_expression(_and_expression), equality_expression(_equality_expression) {}
    std::string name() { return "Bitwise AND:"; }
    void print(std::ostream& os, int level) {
        os << indent(level) << and_expression->name() << std::endl;
        and_expression->print(os, level+1);
        os << indent(level) << equality_expression->name() << std::endl;
        equality_expression->print(os, level+1);
    }
protected:
    Expression *and_expression, *equality_expression;
};

//************************************************************
//-------------------EQUALITY EXPRESSION----------------------
//************************************************************

class EqualToOp : public Expression {
public:
    EqualToOp(Expression *_equality_expression, Expression *_relational_expression) : equality_expression(_equality_expression), relational_expression(_relational_expression) {}
    std::string name() { return "Equal To:"; }
    void print(std::ostream& os, int level) {
        os << indent(level) << equality_expression->name() << std::endl;
        equality_expression->print(os, level+1);
        os << indent(level) << relational_expression->name() << std::endl;
        relational_expression->print(os, level+1);
    }

    virtual void print_py(std::ostream &os, PyContext &context){
        os << "(";
        equality_expression->print_py(os, context);
        os << " == ";
        relational_expression->print_py(os, context);
        os << ")";
    }

protected:
    Expression *equality_expression, *relational_expression;
};

class NotEqualToOp : public Expression {
public:
    NotEqualToOp(Expression *_equality_expression, Expression *_relational_expression) : equality_expression(_equality_expression), relational_expression(_relational_expression) {}
    std::string name() { return "Not Equal To:"; }
    void print(std::ostream& os, int level) {
        os << indent(level) << equality_expression->name() << std::endl;
        equality_expression->print(os, level+1);
        os << indent(level) << relational_expression->name() << std::endl;
        relational_expression->print(os, level+1);
    }
protected:
    Expression *equality_expression, *relational_expression;
};

//************************************************************
//------------------RELATIONAL EXPRESSION---------------------
//************************************************************

class LessThanOp : public Expression {
public:
    LessThanOp(Expression *_relational_expression, Expression *_shift_expression) : relational_expression(_relational_expression), shift_expression(_shift_expression) {}
    std::string name() { return "Less Than:"; }
    void print(std::ostream& os, int level) {
        os << indent(level) << relational_expression->name() << std::endl;
        relational_expression->print(os, level+1);
        os << indent(level) << shift_expression->name() << std::endl;
        shift_expression->print(os, level+1);
    }

    virtual void print_py(std::ostream &os, PyContext &context){
        os << "(";
        relational_expression->print_py(os, context);
        os << " < ";
        shift_expression->print_py(os, context);
        os << ")";
    }

protected:
    Expression *relational_expression, *shift_expression;
};

class MoreThanOp : public Expression {
public:
    MoreThanOp(Expression *_relational_expression, Expression *_shift_expression) : relational_expression(_relational_expression), shift_expression(_shift_expression) {}
    std::string name() { return "More Than:"; }
    void print(std::ostream& os, int level) {
        os << indent(level) << relational_expression->name() << std::endl;
        relational_expression->print(os, level+1);
        os << indent(level) << shift_expression->name() << std::endl;
        shift_expression->print(os, level+1);
    }
protected:
    Expression *relational_expression, *shift_expression;
};

class LessThanEqualOp : public Expression {
public:
    LessThanEqualOp(Expression *_relational_expression, Expression *_shift_expression) : relational_expression(_relational_expression), shift_expression(_shift_expression) {}
    std::string name() { return "Less Than or Equal:"; }
    void print(std::ostream& os, int level) {
        os << indent(level) << relational_expression->name() << std::endl;
        relational_expression->print(os, level+1);
        os << indent(level) << shift_expression->name() << std::endl;
        shift_expression->print(os, level+1);
    }
protected:
    Expression *relational_expression, *shift_expression;
};

class MoreThanEqualOp : public Expression {
public:
    MoreThanEqualOp(Expression *_relational_expression, Expression *_shift_expression) : relational_expression(_relational_expression), shift_expression(_shift_expression) {}
    std::string name() { return "More Than or Equal:"; }
    void print(std::ostream& os, int level) {
        os << indent(level) << relational_expression->name() << std::endl;
        relational_expression->print(os, level+1);
        os << indent(level) << shift_expression->name() << std::endl;
        shift_expression->print(os, level+1);
    }
protected:
    Expression *relational_expression, *shift_expression;
};

//************************************************************
//--------------------SHIFT EXPRESSION------------------------
//************************************************************

class LeftShiftOp : public Expression {
public:
    LeftShiftOp(Expression *_shift_expression, Expression *_add_expression) : shift_expression(_shift_expression), add_expression(_add_expression) {}
    std::string name() { return "Left Shift:"; }
    void print(std::ostream& os, int level) {
        os << indent(level) << shift_expression->name() << std::endl;
        shift_expression->print(os, level+1);
        os << indent(level) << add_expression->name() << std::endl;
        add_expression->print(os, level+1);
    }
protected:
    Expression *shift_expression, *add_expression;
};

class RightShiftOp : public Expression {
public:
    RightShiftOp(Expression *_shift_expression, Expression *_add_expression) : shift_expression(_shift_expression), add_expression(_add_expression) {}
    std::string name() { return "Right Shift:"; }
    void print(std::ostream& os, int level) {
        os << indent(level) << shift_expression->name() << std::endl;
        shift_expression->print(os, level+1);
        os << indent(level) << add_expression->name() << std::endl;
        add_expression->print(os, level+1);
    }
protected:
    Expression *shift_expression, *add_expression;
};

//************************************************************
//------------------ADDITIVE EXPRESSION-----------------------
//************************************************************

class AddOp : public Expression {
public:
    AddOp(Expression *_add_expression, Expression *_mul_expression) : add_expression(_add_expression), mul_expression(_mul_expression) {}
    std::string name() { return "Add:"; }
    void print(std::ostream& os, int level) {
        os << indent(level) << add_expression->name() << std::endl;
        add_expression->print(os, level+1);
        os << indent(level) << mul_expression->name() << std::endl;
        mul_expression->print(os, level+1);
    }

    virtual void print_py(std::ostream &os, PyContext &context){
        os << "(";
        add_expression->print_py(os, context);
        os << "+";
        mul_expression->print_py(os, context);
        os << ")";
    }

protected:
    Expression *add_expression, *mul_expression;
};

class SubOp : public Expression {
public:
    SubOp(Expression *_add_expression, Expression *_mul_expression) : add_expression(_add_expression), mul_expression(_mul_expression) {}
    std::string name() { return "Sub:"; }
    void print(std::ostream& os, int level) {
        os << indent(level) << add_expression->name() << std::endl;
        add_expression->print(os, level+1);
        os << indent(level) << mul_expression->name() << std::endl;
        mul_expression->print(os, level+1);
    }

    virtual void print_py(std::ostream &os, PyContext &context){
        os << "(";
        add_expression->print_py(os, context);
        os << "-";
        mul_expression->print_py(os, context);
        os << ")";
    }

protected:
    Expression *add_expression, *mul_expression;
};

//************************************************************
//---------------MULTIPLICATIVE EXPRESSION--------------------
//************************************************************

class ModOp : public Expression {
public:
    ModOp(Expression *_mul_expression, Expression *_cast_expression) : mul_expression(_mul_expression), cast_expression(_cast_expression) {}
    std::string name() { return "Mod:"; }
    void print(std::ostream& os, int level) {
        os << indent(level) << mul_expression->name() << std::endl;
        mul_expression->print(os, level+1);
        os << indent(level) << cast_expression->name() << std::endl;
        cast_expression->print(os, level+1);
    }
protected:
    Expression *mul_expression, *cast_expression;
};

class DivideOp : public Expression {
public:
    DivideOp(Expression *_mul_expression, Expression *_cast_expression) : mul_expression(_mul_expression), cast_expression(_cast_expression) {}
    std::string name() { return "Divide:"; }
    void print(std::ostream& os, int level) {
        os << indent(level) << mul_expression->name() << std::endl;
        mul_expression->print(os, level+1);
        os << indent(level) << cast_expression->name() << std::endl;
        cast_expression->print(os, level+1);
    }
protected:
    Expression *mul_expression, *cast_expression;
};

class MultiplyOp : public Expression {
public:
    MultiplyOp(Expression *_mul_expression, Expression *_cast_expression) : mul_expression(_mul_expression), cast_expression(_cast_expression) {}
    std::string name() { return "Multiply:"; }
    void print(std::ostream& os, int level) {
        os << indent(level) << mul_expression->name() << std::endl;
        mul_expression->print(os, level+1);
        os << indent(level) << cast_expression->name() << std::endl;
        cast_expression->print(os, level+1);
    }

    virtual void print_py(std::ostream &os, PyContext &context){
        os << "(";
        mul_expression->print_py(os, context);
        os << "*";
        cast_expression->print_py(os, context);
        os << ")";
    }

protected:
    Expression *mul_expression, *cast_expression;
};

//************************************************************
//-----------------------UNARY--------------------------------
//************************************************************

class Unary_PrefixInc : public Expression {
public:
    Unary_PrefixInc(Expression *_cast_expr) : cast_expr(_cast_expr) {}
    std::string name() { return "Prefix Increment:"; }
    void print(std::ostream &os, int level) {
        os << indent(level) << cast_expr->name() << std::endl;
        cast_expr->print(os, level+1);
    }
protected:
    Expression *cast_expr;
};

class Unary_PrefixDec : public Expression {
public:
    Unary_PrefixDec(Expression *_cast_expr) : cast_expr(_cast_expr) {}
    std::string name() { return "Prefix Decrement:"; }
    void print(std::ostream &os, int level) {
        os << indent(level) << cast_expr->name() << std::endl;
        cast_expr->print(os, level+1);
    }
protected:
    Expression *cast_expr;
};

class Unary_SizeOfExpr : public Expression {
public:
    Unary_SizeOfExpr(Expression *_cast_expr) : cast_expr(_cast_expr) {}
    std::string name() { return "Size of:"; }
    void print(std::ostream &os, int level) {
        os << indent(level) << cast_expr->name() << std::endl;
        cast_expr->print(os, level+1);
    }
protected:
    Expression *cast_expr;
};

class Unary_Reference : public Expression {
public:
    Unary_Reference(Expression *_cast_expr) : cast_expr(_cast_expr) {}
    std::string name() { return "Fetch Reference:"; }
    void print(std::ostream &os, int level) {
        os << indent(level) << cast_expr->name() << std::endl;
        cast_expr->print(os, level+1);
    }
protected:
    Expression *cast_expr;
};

class Unary_Dereference : public Expression {
public:
    Unary_Dereference(Expression *_cast_expr) : cast_expr(_cast_expr) {}
    std::string name() { return "Dereference:"; }
    void print(std::ostream &os, int level) {
        os << indent(level) << cast_expr->name() << std::endl;
        cast_expr->print(os, level+1);
    }
protected:
    Expression *cast_expr;
};

class Unary_Negation : public Expression {
public:
    Unary_Negation(Expression *_cast_expr) : cast_expr(_cast_expr) {}
    std::string name() { return "Unary Negation:"; }
    void print(std::ostream &os, int level) {
        os << indent(level) << cast_expr->name() << std::endl;
        cast_expr->print(os, level+1);
    }

    virtual void print_py(std::ostream &os, PyContext &context){
        os << "(";
        os << "-";
        cast_expr->print_py(os, context);
        os << ")";
    }

protected:
    Expression *cast_expr;
};

class Unary_InvertOp : public Expression {
public:
    Unary_InvertOp(Expression *_cast_expr) : cast_expr(_cast_expr) {}
    std::string name() { return "Bitwise Inversion:"; }
    void print(std::ostream &os, int level) {
        os << indent(level) << cast_expr->name() << std::endl;
        cast_expr->print(os, level+1);
    }
protected:
    Expression *cast_expr;
};

class Unary_NotOp : public Expression {
public:
    Unary_NotOp(Expression *_cast_expr) : cast_expr(_cast_expr) {}
    std::string name() { return "Not:"; }
    void print(std::ostream &os, int level) {
        os << indent(level) << cast_expr->name() << std::endl;
        cast_expr->print(os, level+1);
    }
protected:
    Expression *cast_expr;
};

//************************************************************
//----------------------POSTFIX-------------------------------
//************************************************************

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

    virtual void print_py(std::ostream &os, PyContext &context){
        postfix->print_py(os, context);
        os << "(";
        if (argList != NULL)
            argList->print_py(os, context);
        os << ")";
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
    Postfix_DecOp(Expression *_postfix) : postfix(_postfix){}
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
    Postfix_IncOp(Expression *_postfix) : postfix(_postfix){}
    std::string name() { return "Post-assign increment:"; }
    void print(std::ostream& os, int level){
        os << indent(level) << postfix->name() << std::endl;
        postfix->print(os, level+1);
    }


protected:
    Expression *postfix;
};

//************************************************************
//----------------------PRIMARY-------------------------------
//************************************************************
class PrimaryExp_Identifier : public Expression {
public:
    PrimaryExp_Identifier(const std::string &_identifier) : identifier(_identifier){}
    std::string name() { return "Identifier:"; }
    void print(std::ostream& os, int level){
        os << indent(level) << identifier << std::endl;
    }

    virtual void print_py(std::ostream &os, PyContext &context){
        os << identifier;
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

    virtual void print_py(std::ostream &os, PyContext &context){
        os << (int)constant;
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

    virtual void print_py(std::ostream &os, PyContext &context){
        os << "\"" << string << "\"";
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