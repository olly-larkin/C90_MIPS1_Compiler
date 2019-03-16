#ifndef AST_EXPRESSIONS_HPP
#define AST_EXPRESSIONS_HPP

//************************************************************
//----------------------PRIMARY-------------------------------
//************************************************************

class PrimaryExprIdentifier : public BaseExpression {
public:
    PrimaryExprIdentifier(const std::string &_identifier) : identifier(_identifier) {}
    ~PrimaryExprIdentifier() {}

    void print(std::ostream &os, int level) {
        os << indent(level) << "Primary (Identifier): " << identifier << std::endl;
    }

    void printPy(std::ostream &os, PyContext &context) {
        os << identifier;
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        if (context.functionCall()) {
            context.currentFunc = identifier;
            //TODO: may need more
        } else {
            //TODO: needs doing
        }
    }

protected:
    std::string identifier;
};

class PrimaryExprConstant : public BaseExpression {     //MIPS DONE..?
public:
    PrimaryExprConstant(double _constant) : constant(_constant) {}
    ~PrimaryExprConstant() {}

    void print(std::ostream &os, int level) {
        os << indent(level) << "Primary (Constant): " << constant << std::endl;
    }

    void printPy(std::ostream &os, PyContext &context) {
        os << (int)constant;
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        instructions.push_back({"addi", regMap[destReg], regMap[$0], "", (int)constant, Instruction::SSN});
        //TODO: might need to change int casting or creating new primaries
    }

protected:
    double constant;
};

class PrimaryExprStrLiteral : public BaseExpression {
public:
    PrimaryExprStrLiteral(const std::string &_literal) : literal(_literal) {}
    ~PrimaryExprStrLiteral() {}

    void print(std::ostream &os, int level) {
        os << indent(level) << "Primary (String Literal): " << literal << std::endl;
    }

    void printPy(std::ostream &os, PyContext &context) {
        os << literal;
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        //oh god
    }

protected:
    std::string literal;
};

//************************************************************
//----------------------POSTFIX-------------------------------
//************************************************************

class PostfixArrIndex : public BaseExpression {
public:
    PostfixArrIndex(BaseExpression *_postfix, BaseExpression *_index) : postfix(_postfix), index(_index) {}
    ~PostfixArrIndex() {
        delete postfix;
        delete index;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Array Index:" << std::endl;
        os << indent(level+1) << "Array: " << std::endl;
        postfix->print(os, level+2);
        os << indent(level+1) << "Index: " << std::endl;
        index->print(os, level+2);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        //check variable map
        //return desired value via stack offset into destreg?
    }

protected:
    BaseExpression *postfix, *index;
};

class PostfixFuncCall : public BaseExpression {
public:
    PostfixFuncCall(BaseExpression *_postfix, BaseList *_argList) : postfix(_postfix), argList(_argList) {}
    ~PostfixFuncCall() {
        delete postfix;
        if (argList != NULL) delete argList;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Function Call:" << std::endl;
        postfix->print(os, level+1);
        if (argList != NULL) {
            os << indent(level+1) << "Argument List:" << std::endl;
            argList->print(os, level+2);
        }
    }

    void printPy(std::ostream &os, PyContext &context) {
        postfix->printPy(os, context);
        os << "(";
        if (argList != NULL)
            argList->printPy(os, context);
        os << ")";
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        context.funcCallStackPush(instructions);
        context.functionCall() = true;
        postfix->generateMIPS(context, instructions);   // should set currentFunc
        // make $a0 current SP (for function args)
        instructions.push_back({"addi", regMap[$a0], regMap[$sp], "", 0, Instruction::LS});
        argList->generateMIPS(context, instructions);   // should update reg 4 and 
        context.functionCall() = false;
        instructions.push_back({"jal", context.currentFunc, "", "", 0, Instruction::S});
        context.funcCallStackPull(instructions);
        // TODO: probs wont work... fix it
    }

protected:
    BaseExpression *postfix;
    BaseList *argList;
};

class PostfixDotOp : public BaseExpression {
public:
    PostfixDotOp(BaseExpression *_postfix, const std::string &_identifier) : postfix(_postfix), identifier(_identifier) {}
    ~PostfixDotOp() { delete postfix; }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Dot Operator (.):" << std::endl;
        postfix->print(os, level+1);
        os << indent(level+1) << "Identifier: " << identifier << std::endl;
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        //jesus fuck
    }
protected:
    BaseExpression *postfix;
    std::string identifier;
};

class PostfixArrowOp : public BaseExpression {
public:
    PostfixArrowOp(BaseExpression *_postfix, const std::string &_identifier) : postfix(_postfix), identifier(_identifier) {}
    ~PostfixArrowOp() { delete postfix; }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Arrow Operator (->):" << std::endl;
        postfix->print(os, level+1);
        os << indent(level+1) << "Identifier: " << identifier << std::endl;
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        //oh help
    }
protected:
    BaseExpression *postfix;
    std::string identifier;
};

class PostfixDecOp : public BaseExpression {
public:
    PostfixDecOp(BaseExpression *_postfix) : postfix(_postfix) {}
    ~PostfixDecOp() { delete postfix; }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Postfix Decrement (--):" << std::endl;
        postfix->print(os, level+1);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        //check variable map
        //take value into destreg
        //subtract 1 into tempReg
        //store tempreg back to location
    }

protected:
    BaseExpression *postfix;
};

class PostfixIncOp : public BaseExpression {
public:
    PostfixIncOp(BaseExpression *_postfix) : postfix(_postfix) {}
    ~PostfixIncOp() { delete postfix; }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Postfix Incremeent (++):" << std::endl;
        postfix->print(os, level+1);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        //check variable map
        //take value into destreg
        //add 1 into tempReg
        //store tempreg back to location
    }

protected:
    BaseExpression *postfix;
};

//************************************************************
//-----------------------UNARY--------------------------------
//************************************************************

class PrefixDecOp : public BaseExpression {
public:
    PrefixDecOp(BaseExpression *_expr) : expr(_expr) {}
    ~PrefixDecOp() { delete expr; }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Prefix Decrement (--):" << std::endl;
        expr->print(os, level+1);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        //check variable map
        //take value into destreg
        //subtract 1
        //store destreg back to location
    }

protected:
    BaseExpression *expr;
};

class PrefixIncOp : public BaseExpression {
public:
    PrefixIncOp(BaseExpression *_expr) : expr(_expr) {}
    ~PrefixIncOp() { delete expr; }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Prefix Increment (++):" << std::endl;
        expr->print(os, level+1);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        //check variable map
        //take value into destreg
        //add 1
        //store destreg back to location
    }

protected:
    BaseExpression *expr;
};

class SizeOfExpr : public BaseExpression {
public:
    SizeOfExpr(BaseExpression *_expr) : expr(_expr) {}
    ~SizeOfExpr() { delete expr; }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Size Of (Expr):" << std::endl;
        expr->print(os, level+1);
    } 

protected:
    BaseExpression *expr;
};

class SizeOfType : public BaseExpression {
public:
    SizeOfType(BaseNode *_type) : type(_type) {}
    ~SizeOfType() { delete type; }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Size Of (Type):" << std::endl;
        type->print(os, level+1);
    } 

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        //fuck if I know
    }

protected:
    BaseNode *type;
};

class ReferenceOp : public BaseExpression {
public:
    ReferenceOp(BaseExpression *_expr) : expr(_expr) {}
    ~ReferenceOp() { delete expr; }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Reference Operator (&):" << std::endl;
        expr->print(os, level+1);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        //return a logical address: frame pointer + frame offset?
    }

protected:
    BaseExpression *expr;
};

class DereferenceOp : public BaseExpression {
public:
    DereferenceOp(BaseExpression *_expr) : expr(_expr) {}
    ~DereferenceOp() { delete expr; }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Dereference Operator (*):" << std::endl;
        expr->print(os, level+1);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        //interpret a logical address: frame pointer + frame offset, fetch data?
    }

protected:
    BaseExpression *expr;
};

class NegationOp : public BaseExpression {
public:
    NegationOp(BaseExpression *_expr) : expr(_expr) {}
    ~NegationOp() { delete expr; }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Unary Negation Operator (-):" << std::endl;
        expr->print(os, level+1);
    }

    void printPy(std::ostream &os, PyContext &context) {
        os << "(-";
        expr->printPy(os, context);
        os << ")";
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        //evaluate what's inside
        //2's complement the destreg
    }

protected:
    BaseExpression *expr;
};

class InvertOp : public BaseExpression {
public:
    InvertOp(BaseExpression *_expr) : expr(_expr) {}
    ~InvertOp() { delete expr; }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Unary Inversion Operator (~):" << std::endl;
        expr->print(os, level+1);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        //evaluate what's inside
        //bitwise inversion?
    }
protected:
    BaseExpression *expr;
};

class NotOp : public BaseExpression {
public:
    NotOp(BaseExpression *_expr) : expr(_expr) {}
    ~NotOp() { delete expr; }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Unary Not Operator (!):" << std::endl;
        expr->print(os, level+1);
    }

protected:
    BaseExpression *expr;
};

//************************************************************
//---------------MULTIPLICATIVE EXPRESSION--------------------
//************************************************************

class ModOp : public BaseExpression {
public:
    ModOp(BaseExpression *_expr1, BaseExpression *_expr2) : expr1(_expr1), expr2(_expr2) {}
    ~ModOp() { 
        delete expr1;
        delete expr2; 
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Mod Operator (%):" << std::endl;
        expr1->print(os, level+1);
        expr2->print(os, level+1);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) { //TODO: implement
        //evaluate op1 and 2
        //divide into HI and LO
        //put LO(?) into destreg
    }
protected:
    BaseExpression *expr1, *expr2;
};

class DivideOp : public BaseExpression {
public:
    DivideOp(BaseExpression *_expr1, BaseExpression *_expr2) : expr1(_expr1), expr2(_expr2) {}
    ~DivideOp() { 
        delete expr1;
        delete expr2; 
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Divide Operator (/):" << std::endl;
        expr1->print(os, level+1);
        expr2->print(os, level+1);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) { //TODO: implement
        //evaluate op1 and 2
        //divide into HI and LO
        //put HI(?) into destreg
    }

protected:
    BaseExpression *expr1, *expr2;
};

class MultiplyOp : public BaseExpression {
public:
    MultiplyOp(BaseExpression *_expr1, BaseExpression *_expr2) : expr1(_expr1), expr2(_expr2) {}
    ~MultiplyOp() { 
        delete expr1;
        delete expr2; 
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Multiply Operator (*):" << std::endl;
        expr1->print(os, level+1);
        expr2->print(os, level+1);
    }

    void printPy(std::ostream &os, PyContext &context) {
        os << "(";
        expr1->printPy(os, context);
        os << "*";
        expr2->printPy(os, context);
        os << ")";
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) { //TODO: implement
        //evaluate op1 and 2
        //mul into HI and LO
        //put LO(?) into destreg(s)
    }

protected:
    BaseExpression *expr1, *expr2;
};

//************************************************************
//------------------ADDITIVE EXPRESSION-----------------------
//************************************************************

class AddOp : public BaseExpression {
public:
    AddOp(BaseExpression *_expr1, BaseExpression *_expr2) : expr1(_expr1), expr2(_expr2) {}
    ~AddOp() { 
        delete expr1;
        delete expr2; 
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Add Operator (+):" << std::endl;
        expr1->print(os, level+1);
        expr2->print(os, level+1);
    }

    void printPy(std::ostream &os, PyContext &context) {
        os << "(";
        expr1->printPy(os, context);
        os << "+";
        expr2->printPy(os, context);
        os << ")";
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) { //TODO: implement
        //evaluate op1 and 2
        //add into destreg
        //overflow?
    }

protected:
    BaseExpression *expr1, *expr2;
};

class SubOp : public BaseExpression {
public:
    SubOp(BaseExpression *_expr1, BaseExpression *_expr2) : expr1(_expr1), expr2(_expr2) {}
    ~SubOp() { 
        delete expr1;
        delete expr2; 
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Sub Operator (-):" << std::endl;
        expr1->print(os, level+1);
        expr2->print(os, level+1);
    }

    void printPy(std::ostream &os, PyContext &context) {
        os << "(";
        expr1->printPy(os, context);
        os << "-";
        expr2->printPy(os, context);
        os << ")";
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) { //TODO: implement
        //evaluate op1 and 2
        //sub into destreg
        //overflow?
    }

protected:
    BaseExpression *expr1, *expr2;
};

//************************************************************
//--------------------SHIFT EXPRESSION------------------------
//************************************************************

class LeftShiftOp : public BaseExpression {
public:
    LeftShiftOp(BaseExpression *_expr1, BaseExpression *_expr2) : expr1(_expr1), expr2(_expr2) {}
    ~LeftShiftOp() { 
        delete expr1;
        delete expr2; 
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Left Shift Operator (<<):" << std::endl;
        expr1->print(os, level+1);
        expr2->print(os, level+1);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) { //TODO: implement
        //evaluate op1 and 2
        //lsl into destreg
        //overflow?
    }

protected:
    BaseExpression *expr1, *expr2;
};

class RightShiftOp : public BaseExpression {
public:
    RightShiftOp(BaseExpression *_expr1, BaseExpression *_expr2) : expr1(_expr1), expr2(_expr2) {}
    ~RightShiftOp() { 
        delete expr1;
        delete expr2; 
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Rigth Shift Operator (>>):" << std::endl;
        expr1->print(os, level+1);
        expr2->print(os, level+1);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) { //TODO: implement
        //evaluate op1 and 2
        //asr into destreg
        //overflow?
    }

protected:
    BaseExpression *expr1, *expr2;
};

//************************************************************
//------------------RELATIONAL EXPRESSION---------------------
//************************************************************

class LessThanOp : public BaseExpression {
public:
    LessThanOp(BaseExpression *_expr1, BaseExpression *_expr2) : expr1(_expr1), expr2(_expr2) {}
    ~LessThanOp() { 
        delete expr1;
        delete expr2; 
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Less Than Operator (<):" << std::endl;
        expr1->print(os, level+1);
        expr2->print(os, level+1);
    }

    void printPy(std::ostream &os, PyContext &context) {
        os << "(";
        expr1->printPy(os, context);
        os << " < ";
        expr2->printPy(os, context);
        os << ")";
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) { //TODO: implement
        //evaluate op1 and 2
        //slt into destreg
        //signed, unsigned comparison?
    }

protected:
    BaseExpression *expr1, *expr2;
};

class MoreThanOp : public BaseExpression {
public:
    MoreThanOp(BaseExpression *_expr1, BaseExpression *_expr2) : expr1(_expr1), expr2(_expr2) {}
    ~MoreThanOp() { 
        delete expr1;
        delete expr2; 
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "More Than Operator (>):" << std::endl;
        expr1->print(os, level+1);
        expr2->print(os, level+1);
    }

    void printPy(std::ostream &os, PyContext &context) {
        os << "(";
        expr1->printPy(os, context);
        os << " > ";
        expr2->printPy(os, context);
        os << ")";
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) { //TODO: implement
        //evaluate op1 and 2
        //slt the other way into destreg
        //signed, unsigned comparison?
    }

protected:
    BaseExpression *expr1, *expr2;
};

class LessThanEqualToOp : public BaseExpression {
public:
    LessThanEqualToOp(BaseExpression *_expr1, BaseExpression *_expr2) : expr1(_expr1), expr2(_expr2) {}
    ~LessThanEqualToOp() { 
        delete expr1;
        delete expr2; 
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Less Than Or Equal To Operator (<=):" << std::endl;
        expr1->print(os, level+1);
        expr2->print(os, level+1);
    }

protected:
    BaseExpression *expr1, *expr2;
};

class MoreThanEqualToOp : public BaseExpression {
public:
    MoreThanEqualToOp(BaseExpression *_expr1, BaseExpression *_expr2) : expr1(_expr1), expr2(_expr2) {}
    ~MoreThanEqualToOp() { 
        delete expr1;
        delete expr2; 
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "More Than Or Equal To Operator (>=):" << std::endl;
        expr1->print(os, level+1);
        expr2->print(os, level+1);
    }

protected:
    BaseExpression *expr1, *expr2;
};

//************************************************************
//-------------------EQUALITY EXPRESSION----------------------
//************************************************************

class EqualToOp : public BaseExpression {
public:
    EqualToOp(BaseExpression *_expr1, BaseExpression *_expr2) : expr1(_expr1), expr2(_expr2) {}
    ~EqualToOp() { 
        delete expr1;
        delete expr2; 
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Equal To Operator (==):" << std::endl;
        expr1->print(os, level+1);
        expr2->print(os, level+1);
    }

    void printPy(std::ostream &os, PyContext &context) {
        os << "(";
        expr1->printPy(os, context);
        os << " == ";
        expr2->printPy(os, context);
        os << ")";
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) { //TODO: implement
        //evaluate expr1 and 2
        //bne, and if no branch mov 1 into destreg
        //signed, unsigned comparison?
    }

protected:
    BaseExpression *expr1, *expr2;
};

class NotEqualToOp : public BaseExpression {
public:
    NotEqualToOp(BaseExpression *_expr1, BaseExpression *_expr2) : expr1(_expr1), expr2(_expr2) {}
    ~NotEqualToOp() { 
        delete expr1;
        delete expr2; 
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Not Equal To Operator (!=):" << std::endl;
        expr1->print(os, level+1);
        expr2->print(os, level+1);
    }

    void printPy(std::ostream &os, PyContext &context) {
        os << "(";
        expr1->printPy(os, context);
        os << " != ";
        expr2->printPy(os, context);
        os << ")";
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) { //TODO: implement
        //evaluate expr1 and 2
        //beq, and if no branch mov 1 into destreg
        //signed, unsigned comparison?
    }

protected:
    BaseExpression *expr1, *expr2;
};

//************************************************************
//----------------------AND EXPRESSION------------------------
//************************************************************

class BitwiseANDOp : public BaseExpression {
public:
    BitwiseANDOp(BaseExpression *_expr1, BaseExpression *_expr2) : expr1(_expr1), expr2(_expr2) {}
    ~BitwiseANDOp() { 
        delete expr1;
        delete expr2; 
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Bitwise AND Operator (&):" << std::endl;
        expr1->print(os, level+1);
        expr2->print(os, level+1);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) { //TODO: implement
        //evaluate expr1 and 2
        //AND into destreg
    }

protected:
    BaseExpression *expr1, *expr2;
};

//************************************************************
//-----------------EXCLUSIVE OR EXPRESSION--------------------
//************************************************************

class BitwiseExclusiveOROp : public BaseExpression {
public:
    BitwiseExclusiveOROp(BaseExpression *_expr1, BaseExpression *_expr2) : expr1(_expr1), expr2(_expr2) {}
    ~BitwiseExclusiveOROp() { 
        delete expr1;
        delete expr2; 
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Bitwise Exclusive OR Operator (^):" << std::endl;
        expr1->print(os, level+1);
        expr2->print(os, level+1);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) { //TODO: implement
        //evaluate expr1 and 2
        //XOR into destreg
    }

protected:
    BaseExpression *expr1, *expr2;
};

//************************************************************
//-----------------INCLUSIVE OR EXPRESSION--------------------
//************************************************************

class BitwiseInclusiveOROp : public BaseExpression {
public:
    BitwiseInclusiveOROp(BaseExpression *_expr1, BaseExpression *_expr2) : expr1(_expr1), expr2(_expr2) {}
    ~BitwiseInclusiveOROp() { 
        delete expr1;
        delete expr2; 
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Bitwise Inclusive OR Operator (|):" << std::endl;
        expr1->print(os, level+1);
        expr2->print(os, level+1);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) { //TODO: implement
        //evaluate expr1 and 2
        //OR into destreg
    }

protected:
    BaseExpression *expr1, *expr2;
};

//************************************************************
//------------------LOGICAL AND EXPRESSION--------------------
//************************************************************

class LogicalANDOp : public BaseExpression {
public:
    LogicalANDOp(BaseExpression *_expr1, BaseExpression *_expr2) : expr1(_expr1), expr2(_expr2) {}
    ~LogicalANDOp() { 
        delete expr1;
        delete expr2; 
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Logical AND Operator (&&):" << std::endl;
        expr1->print(os, level+1);
        expr2->print(os, level+1);
    }

    void printPy(std::ostream &os, PyContext &context) {
        os << "(";
        expr1->printPy(os, context);
        os << " and ";
        expr2->printPy(os, context);
        os << ")";
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) { //TODO: implement
        //evaluate expr1 and 2
        //1 into destreg if both operands are positive?
    }

protected:
    BaseExpression *expr1, *expr2;
};

//************************************************************
//------------------LOGICAL OR EXPRESSION---------------------
//************************************************************

class LogicalOROp : public BaseExpression {
public:
    LogicalOROp(BaseExpression *_expr1, BaseExpression *_expr2) : expr1(_expr1), expr2(_expr2) {}
    ~LogicalOROp() { 
        delete expr1;
        delete expr2; 
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Logical OR Operator (||):" << std::endl;
        expr1->print(os, level+1);
        expr2->print(os, level+1);
    }

    void printPy(std::ostream &os, PyContext &context) {
        os << "(";
        expr1->printPy(os, context);
        os << " or ";
        expr2->printPy(os, context);
        os << ")";
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) { //TODO: implement
        //evaluate expr1 and 2
        //1 into destreg if either operand is positive?
    }

protected:
    BaseExpression *expr1, *expr2;
};

//************************************************************
//-----------------CONDITIONAL EXPRESSION---------------------
//************************************************************

class ConditionalOp : public BaseExpression {
public:
    ConditionalOp(BaseExpression *_expr1, BaseExpression *_expr2, BaseExpression *_expr3) : expr1(_expr1), expr2(_expr2), expr3(_expr3) {}
    ~ConditionalOp() { 
        delete expr1;
        delete expr2; 
        delete expr3;
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Conditional Expression ( ? : ):" << std::endl;
        os << indent(level+1) << "Condition:" << std::endl;
        expr1->print(os, level+2);
        os << indent(level+1) << "If True:" << std::endl;
        expr2->print(os, level+2);
        os << indent(level+1) << "If False:" << std::endl;
        expr3->print(os, level+2);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) { //TODO: implement
        //evaluate ternary condition
        //branch to 1st label if true
        //branch to 2nd if false
        //generate first label and code with a jump to the end label
        //generate second label and code
    }

protected:
    BaseExpression *expr1, *expr2, *expr3;
};

//************************************************************
//------------------ASSIGNMENT EXPRESSION---------------------
//************************************************************

class Assignment : public BaseExpression {
public:
    Assignment(BaseExpression *_expr1, BaseExpression *_expr2) : expr1(_expr1), expr2(_expr2) {}
    ~Assignment() { 
        delete expr1;
        delete expr2; 
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Assignment (=):" << std::endl;
        expr1->print(os, level+1);
        expr2->print(os, level+1);
    }

    void printPy(std::ostream &os, PyContext &context) {
        expr1->printPy(os, context);
        os << " = ";
        expr2->printPy(os, context);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) { //TODO: implement
        //evaluate RHS
        //check variable map
        //if present, go to stack offset and change value
        //else put a new value on the stack offset
    }

protected:
    BaseExpression *expr1, *expr2;
};

class AddAssignment : public BaseExpression {
public:
    AddAssignment(BaseExpression *_expr1, BaseExpression *_expr2) : expr1(_expr1), expr2(_expr2) {}
    ~AddAssignment() { 
        delete expr1;
        delete expr2; 
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Add Assignment (+=):" << std::endl;
        expr1->print(os, level+1);
        expr2->print(os, level+1);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) { //TODO: implement
        //evaluate OP1,2
        //add and put into OP1's stack location? (overflow?)
    }

protected:
    BaseExpression *expr1, *expr2;
};

class SubAssignment : public BaseExpression {
public:
    SubAssignment(BaseExpression *_expr1, BaseExpression *_expr2) : expr1(_expr1), expr2(_expr2) {}
    ~SubAssignment() { 
        delete expr1;
        delete expr2; 
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Sub Assignment (-=):" << std::endl;
        expr1->print(os, level+1);
        expr2->print(os, level+1);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) { //TODO: implement
        //evaluate OP1,2
        //sub and put into OP1's stack location? (overflow?)
    }

protected:
    BaseExpression *expr1, *expr2;
};

class MulAssignment : public BaseExpression {
public:
    MulAssignment(BaseExpression *_expr1, BaseExpression *_expr2) : expr1(_expr1), expr2(_expr2) {}
    ~MulAssignment() { 
        delete expr1;
        delete expr2; 
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Multiply Assignment (*=):" << std::endl;
        expr1->print(os, level+1);
        expr2->print(os, level+1);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) { //TODO: implement
        //evaluate OP1,2
        //mul and put into OP1's stack location? (overflow?)
    }

protected:
    BaseExpression *expr1, *expr2;
};

class DivAssignment : public BaseExpression {
public:
    DivAssignment(BaseExpression *_expr1, BaseExpression *_expr2) : expr1(_expr1), expr2(_expr2) {}
    ~DivAssignment() { 
        delete expr1;
        delete expr2; 
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Divide Assignment (/=):" << std::endl;
        expr1->print(os, level+1);
        expr2->print(os, level+1);
    }

protected:
    BaseExpression *expr1, *expr2;
};

class ModAssignment : public BaseExpression {
public:
    ModAssignment(BaseExpression *_expr1, BaseExpression *_expr2) : expr1(_expr1), expr2(_expr2) {}
    ~ModAssignment() { 
        delete expr1;
        delete expr2; 
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Mod Assignment (%=):" << std::endl;
        expr1->print(os, level+1);
        expr2->print(os, level+1);
    }

protected:
    BaseExpression *expr1, *expr2;
};

class LeftShiftAssignment : public BaseExpression {
public:
    LeftShiftAssignment(BaseExpression *_expr1, BaseExpression *_expr2) : expr1(_expr1), expr2(_expr2) {}
    ~LeftShiftAssignment() { 
        delete expr1;
        delete expr2; 
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Left Shift Assignment (<<=):" << std::endl;
        expr1->print(os, level+1);
        expr2->print(os, level+1);
    }

protected:
    BaseExpression *expr1, *expr2;
};

class RightShiftAssignment : public BaseExpression {
public:
    RightShiftAssignment(BaseExpression *_expr1, BaseExpression *_expr2) : expr1(_expr1), expr2(_expr2) {}
    ~RightShiftAssignment() { 
        delete expr1;
        delete expr2; 
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Rigth Shift Assignment (>>=):" << std::endl;
        expr1->print(os, level+1);
        expr2->print(os, level+1);
    }

protected:
    BaseExpression *expr1, *expr2;
};

class BitwiseANDAssignment : public BaseExpression {
public:
    BitwiseANDAssignment(BaseExpression *_expr1, BaseExpression *_expr2) : expr1(_expr1), expr2(_expr2) {}
    ~BitwiseANDAssignment() { 
        delete expr1;
        delete expr2; 
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Bitwise AND Assignment (&=):" << std::endl;
        expr1->print(os, level+1);
        expr2->print(os, level+1);
    }

protected:
    BaseExpression *expr1, *expr2;
};

class BitwiseORAssignment : public BaseExpression {
public:
    BitwiseORAssignment(BaseExpression *_expr1, BaseExpression *_expr2) : expr1(_expr1), expr2(_expr2) {}
    ~BitwiseORAssignment() { 
        delete expr1;
        delete expr2; 
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Bitwise OR Assignment (|=):" << std::endl;
        expr1->print(os, level+1);
        expr2->print(os, level+1);
    }

protected:
    BaseExpression *expr1, *expr2;
};

class BitwiseXORAssignment : public BaseExpression {
public:
    BitwiseXORAssignment(BaseExpression *_expr1, BaseExpression *_expr2) : expr1(_expr1), expr2(_expr2) {}
    ~BitwiseXORAssignment() { 
        delete expr1;
        delete expr2; 
    }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Bitwise XOR Assignment (^=):" << std::endl;
        expr1->print(os, level+1);
        expr2->print(os, level+1);
    }

protected:
    BaseExpression *expr1, *expr2;
};

//************************************************************
//----------------ARGUMENT EXPRESSION LIST--------------------
//************************************************************

class ArgumentExprList : public BaseList {
public:
    ArgumentExprList(BaseList *_list, BaseExpression *_expr) : BaseList(_list), expr(_expr) {}
    ~ArgumentExprList() {
        if (list != NULL)
            delete list;
        delete expr;
    }

    void print(std::ostream &os, int level) {
        if (list != NULL)
            list->print(os, level);
        expr->print(os, level);
    }

    void printPy(std::ostream &os, PyContext &context) {
        if (list != NULL) {
            list->printPy(os, context);
            os << ", ";
        }
        expr->printPy(os, context);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        //TODO: add each argument onto stack and context
    }

protected:
    BaseExpression *expr;
};

#endif