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
        address(destReg, context, instructions);
        instructions.push_back({"lw", regMap[destReg], regMap[destReg], "", 0, Instruction::LS});
    }

    void address(int destReg, CompContext &context, std::vector<Instruction> &instructions) {
        if (context.local(identifier)) {
            int spOffset = context.memUsed - context.varMap()[identifier].offset;
            instructions.push_back({"addi", regMap[destReg], regMap[$sp], "", spOffset, Instruction::SSN});     //local
        } else if (context.param(identifier)) {
            int offset;
            for(int i=0; i<context.currentFunc().params.size(); i++){
                if (context.currentFunc().params[i].first == identifier)
                    offset = i*-4;
            }
            int spOffset = context.memUsed - offset;
            instructions.push_back({"addi", regMap[destReg], regMap[$sp], "", spOffset, Instruction::SSN});     //param
        } else {
            instructions.push_back({"li", regMap[destReg], identifier, "", 0, Instruction::SS});                //global
        }
    }

    bool isPointer(CompContext &context) { 
        if (context.local(identifier)) 
            return (context.varMap()[identifier].type.pointerNum > 0);
        if (context.param(identifier)) {
            for (int i = 0; i < context.currentFunc().params.size(); ++i) {
                if (context.currentFunc().params[i].first == identifier)
                    return (context.currentFunc().params[i].second.pointerNum > 0);
            }
        }
        return (context.globals[identifier].pointerNum > 0);
    }

    std::string getIdentifier() { 
        return identifier; 
    }

protected:
    std::string identifier;
};

class PrimaryExprConstant : public BaseExpression { 
public:
    PrimaryExprConstant(double _constant) : constant(_constant) {}
    ~PrimaryExprConstant() {}

    void print(std::ostream &os, int level) {
        os << indent(level) << "Primary (Constant): " << constant << std::endl;
    }

    void printPy(std::ostream &os, PyContext &context) {
        os << (int)constant;
    }

    double eval() {
        return constant;
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        instructions.push_back({"li", regMap[destReg], "", "", (int)constant, Instruction::SN});
    }

protected:
    double constant;
};

class PrimaryExprStrLiteral : public BaseExpression {       //TODO: come back after char support
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
        address(destReg, context, instructions);
        instructions.push_back({"lw", regMap[destReg], regMap[destReg], "", 0, Instruction::LS});
    }

    void address(int destReg, CompContext &context, std::vector<Instruction> &instructions) {       // will only work with single dimention arrays
        int reg = context.chooseReg({destReg});
        context.pushToStack({reg}, instructions);
        index->generateMIPS(context, instructions, reg);
        instructions.push_back({"sll", regMap[reg], regMap[reg], "", 2, Instruction::SSN});         // will only work with int (or size 4 things)
        postfix->address(destReg, context, instructions);
        instructions.push_back({"sub", regMap[destReg], regMap[destReg], regMap[reg], 0, Instruction::SSS});
        context.pullFromStack({reg}, instructions);
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
        // TODO:
        // 1) get function name     //
        // 2) get function arg number (list size)   //
        // 3) store $fp to stack    //
        // 4) increase scope    //
        // 5) allocate space for arguments  //
        // 6) call arument list     //
        // 7) push into $4 - $7     //
        // 8) move $fp to $sp       //
        // 9) jal to label          //
        // 10) decrease the stack   //
        // 11) pull $fp from stack  //
        // 12) move $2 to destReg

        std::string funcName = postfix->getIdentifier();
        int argNum = (argList != NULL) ? argList->size() : 0;
        context.addComment(instructions, "Start of function call...");
        context.addComment(instructions, "Function name: " + funcName);
        context.addComment(instructions, "Destination reg: " + regMap[destReg]);
        context.addComment(instructions, "Argument number: " + std::to_string(argNum));
        if (destReg == $2)
            context.pushToStack({$fp}, instructions);
        else
            context.pushToStack({$2, $fp}, instructions);
        context.addScope(instructions);
        int allocate = (argNum < 4) ? -16 : -4 * argNum;
        context.memUsed -= allocate;
        instructions.push_back({"addi", regMap[$sp], regMap[$sp], "", allocate, Instruction::SSN});
        // if (argList != NULL) argList->generateMIPS(context, instructions);
        // instructions.push_back({"sw", regMap[$4], regMap[$sp], "", 0, Instruction::LS});
        // instructions.push_back({"sw", regMap[$5], regMap[$sp], "", 4, Instruction::LS});
        // instructions.push_back({"sw", regMap[$6], regMap[$sp], "", 8, Instruction::LS});
        // instructions.push_back({"sw", regMap[$7], regMap[$sp], "", 12, Instruction::LS});
        // instructions.push_back({"addi", regMap[$fp], regMap[$sp], "", 0, Instruction::SSN});
        // instructions.push_back({"jal", funcName, "", "", 0, Instruction::S});
        context.subScope(instructions);
        context.pullFromStack({$fp}, instructions);
        if (destReg != $2) {
            instructions.push_back({"addi", regMap[destReg], regMap[$2], "", 0, Instruction::SSN});
            context.pullFromStack({$2}, instructions);
        }
        context.addComment(instructions, "End of function call...");
    }

    bool isPointer(CompContext &context) {
        return context.currentFunc().retType.pointerNum > 0;
    }

protected:
    BaseExpression *postfix;
    BaseList *argList;
};

class PostfixDotOp : public BaseExpression {        //TODO: implement after structs
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

class PostfixArrowOp : public BaseExpression {      //TODO: implement after structs
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
        bool pointerMath = postfix->isPointer(context);
        int addrReg = context.chooseReg({destReg});
        int resultReg = context.chooseReg({destReg, addrReg});
        context.pushToStack({addrReg, resultReg}, instructions);
        postfix->address(addrReg, context, instructions);
        instructions.push_back({"lw", regMap[destReg], regMap[addrReg], "", 0, Instruction::LS});
        if (pointerMath)
            instructions.push_back({"addi", regMap[resultReg], regMap[destReg], "", -4, Instruction::SSN});
        else
            instructions.push_back({"addi", regMap[resultReg], regMap[destReg], "", -1, Instruction::SSN});
        instructions.push_back({"sw", regMap[resultReg], regMap[addrReg], "", 0, Instruction::LS});
        context.pullFromStack({resultReg, addrReg}, instructions);
    }

    bool isPointer(CompContext &context) { 
        return postfix->isPointer(context); 
    }

protected:
    BaseExpression *postfix;
};

class PostfixIncOp : public BaseExpression { 
public:
    PostfixIncOp(BaseExpression *_postfix) : expr(_postfix) {}
    ~PostfixIncOp() { delete expr; }

    void print(std::ostream &os, int level) {
        os << indent(level) << "Postfix Increment (++):" << std::endl;
        expr->print(os, level+1);
    }

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        bool pointerMath = expr->isPointer(context);
        int addrReg = context.chooseReg({destReg});
        int resultReg = context.chooseReg({destReg, addrReg});
        context.pushToStack({addrReg, resultReg}, instructions);
        expr->address(addrReg, context, instructions);
        instructions.push_back({"lw", regMap[destReg], regMap[addrReg], "", 0, Instruction::LS});
        if (pointerMath)
            instructions.push_back({"addi", regMap[resultReg], regMap[destReg], "", 4, Instruction::SSN});
        else
            instructions.push_back({"addi", regMap[resultReg], regMap[destReg], "", 1, Instruction::SSN});
        instructions.push_back({"sw", regMap[resultReg], regMap[addrReg], "", 0, Instruction::LS});
        context.pullFromStack({resultReg, addrReg}, instructions);
    }

    bool isPointer(CompContext &context) { 
        return expr->isPointer(context); 
    }

protected:
    BaseExpression *expr;
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
        bool pointerMath = expr->isPointer(context);
        int addrReg = context.chooseReg({destReg});
        context.pushToStack({addrReg}, instructions);

        expr->address(addrReg, context, instructions);
        instructions.push_back({"lw", regMap[destReg], regMap[addrReg], "", 0, Instruction::LS});
        if (pointerMath)
            instructions.push_back({"addiu", regMap[destReg], regMap[destReg], "", -4, Instruction::SSN});
        else
            instructions.push_back({"addiu", regMap[destReg], regMap[destReg], "", -1, Instruction::SSN});
        instructions.push_back({"sw", regMap[destReg], regMap[addrReg], "", 0, Instruction::LS});

        context.pullFromStack({addrReg}, instructions);
    }

    bool isPointer(CompContext &context) { 
        return expr->isPointer(context); 
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
        bool pointerMath = expr->isPointer(context);
        int addrReg = context.chooseReg({destReg});
        context.pushToStack({addrReg}, instructions);

        expr->address(addrReg, context, instructions);
        instructions.push_back({"lw", regMap[destReg], regMap[addrReg], "", 0, Instruction::LS});
        if (pointerMath)
            instructions.push_back({"addiu", regMap[destReg], regMap[destReg], "", 4, Instruction::SSN});
        else
            instructions.push_back({"addiu", regMap[destReg], regMap[destReg], "", 1, Instruction::SSN});
        instructions.push_back({"sw", regMap[destReg], regMap[addrReg], "", 0, Instruction::LS});

        context.pullFromStack({addrReg}, instructions);
    }

    bool isPointer(CompContext &context) { 
        return expr->isPointer(context); 
    }

protected:
    BaseExpression *expr;
};

class SizeOfExpr : public BaseExpression {      //TODO: sizeof
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

class SizeOfType : public BaseExpression {      //TODO: sizeof
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
       expr->address(destReg, context, instructions);
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
        expr->generateMIPS(context, instructions, destReg);
        instructions.push_back({"lw", regMap[destReg], regMap[destReg], "", 0, Instruction::SSN});
    }

    void address(int destReg, CompContext &context, std::vector<Instruction> &instructions) {
        expr->generateMIPS(context, instructions, destReg);
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
        expr->generateMIPS(context, instructions, destReg);
        instructions.push_back({"not", regMap[destReg], regMap[destReg], "", 0, Instruction::SS});
        instructions.push_back({"addiu", regMap[destReg], regMap[destReg], "", 1, Instruction::SSN});
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
        expr->generateMIPS(context, instructions, destReg);
        instructions.push_back({"not", regMap[destReg], regMap[destReg], "", 0, Instruction::SS});
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

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        //TODO: signed/unsigned slt
        expr->generateMIPS(context, instructions, destReg);
        instructions.push_back({"slti", regMap[destReg], regMap[destReg], "", 1, Instruction::SSS});
        //andi char casting?
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

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        int op1 = context.chooseReg({destReg});
        int op2 = context.chooseReg({destReg, op1});
        
        context.pushToStack({op1, op2}, instructions);
        expr1->generateMIPS(context, instructions, op1);
        expr2->generateMIPS(context, instructions, op2);

        instructions.push_back({"div", regMap[op1], regMap[op2], "", 0, Instruction::SS});
        instructions.push_back({"mfhi", regMap[destReg], "", "", 0, Instruction::S});
        context.pullFromStack({op2,op1}, instructions);
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

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        int op1 = context.chooseReg({destReg});
        int op2 = context.chooseReg({destReg, op1});
        
        context.pushToStack({op1, op2}, instructions);
        expr1->generateMIPS(context, instructions, op1);
        expr2->generateMIPS(context, instructions, op2);

        instructions.push_back({"div", regMap[op1], regMap[op2], "", 0, Instruction::SS});
        instructions.push_back({"mflo", regMap[destReg], "", "", 0, Instruction::S});
        context.pullFromStack({op2,op1}, instructions);
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

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        int op1 = context.chooseReg({destReg});
        int op2 = context.chooseReg({destReg, op1});
        
        context.pushToStack({op1, op2}, instructions);
        expr1->generateMIPS(context, instructions, op1);
        expr2->generateMIPS(context, instructions, op2);

        instructions.push_back({"mult", regMap[op1], regMap[op2], "", 0, Instruction::SS});
        instructions.push_back({"mflo", regMap[destReg], "", "", 0, Instruction::S});
        context.pullFromStack({op2,op1}, instructions);
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

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        int op = context.chooseReg({destReg});
        
        context.pushToStack({op}, instructions);
        expr1->generateMIPS(context, instructions, destReg);
        expr2->generateMIPS(context, instructions, op);

        if (expr1->isPointer(context) && !expr2->isPointer(context)) {

            instructions.push_back({"sll", regMap[op], regMap[op], "", 2, Instruction::SSN});
        } else if (!expr1->isPointer(context) && expr2->isPointer(context)) {
            instructions.push_back({"sll", regMap[destReg], regMap[destReg], "", 2, Instruction::SSN});
        }

        instructions.push_back({"addu", regMap[destReg], regMap[destReg], regMap[op], 0, Instruction::SSS});
        context.pullFromStack({op}, instructions);
    }

    bool isPointer(CompContext &context) { 
        return expr1->isPointer(context) || expr2->isPointer(context);
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

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        int op = context.chooseReg({destReg});
        
        context.pushToStack({op}, instructions);
        expr1->generateMIPS(context, instructions, destReg);
        expr2->generateMIPS(context, instructions, op);

        if (expr1->isPointer(context) && !expr2->isPointer(context)) {
            instructions.push_back({"sll", regMap[op], regMap[op], "", 2, Instruction::SSN});
        } else if (!expr1->isPointer(context) && expr2->isPointer(context)) {
            instructions.push_back({"sll", regMap[destReg], regMap[destReg], "", 2, Instruction::SSN});
        }

        instructions.push_back({"sub", regMap[destReg], regMap[destReg], regMap[op], 0, Instruction::SSS});
        context.pullFromStack({op}, instructions);
    }

    bool isPointer(CompContext &context) { 
        return expr1->isPointer(context) || expr2->isPointer(context);
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

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        int op1 = context.chooseReg({destReg});
        int op2 = context.chooseReg({destReg, op1});
        
        context.pushToStack({op1, op2}, instructions);
        expr1->generateMIPS(context, instructions, op1);
        expr2->generateMIPS(context, instructions, op2);

        instructions.push_back({"sllv", regMap[destReg], regMap[op1], regMap[op2], 0, Instruction::SSS});
        context.pullFromStack({op2,op1}, instructions);
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

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        int op1 = context.chooseReg({destReg});
        int op2 = context.chooseReg({destReg, op1});
        
        context.pushToStack({op1, op2}, instructions);
        expr1->generateMIPS(context, instructions, op1);
        expr2->generateMIPS(context, instructions, op2);
        //TODO: SRA, or SRL?
        instructions.push_back({"srav", regMap[destReg], regMap[op1], regMap[op2], 0, Instruction::SSS});
        context.pullFromStack({op2,op1}, instructions);
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

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) { //TODO: CHECK
        int op1 = context.chooseReg({destReg});
        int op2 = context.chooseReg({destReg, op1});
        context.pushToStack({op1,op2}, instructions);
        expr1->generateMIPS(context, instructions, op1);
        expr2->generateMIPS(context, instructions, op2);
        std::string skipper = context.makeALabel("skip");

        instructions.push_back({"addi", regMap[destReg], regMap[$0],"", 0, Instruction::SSN});              //assign 0 by default
        instructions.push_back({"sub", regMap[op1], regMap[op1], regMap[op2], 0, Instruction::SSS});        //sub op2 from op1
        instructions.push_back({"bgez", regMap[op1], skipper, "", 0, Instruction::SS});                     //if difference is not negative, op1 is greater
        //branch delay slot nop
        instructions.push_back({"addi", regMap[destReg], regMap[$0],"", 1, Instruction::SSN});              //gets skipped if branch was true
        instructions.push_back({"irrelevant", skipper, "", "", 0, Instruction::L});

        context.pullFromStack({op2,op1}, instructions);
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

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) { //TODO: CHECK
        int op1 = context.chooseReg({destReg});
        int op2 = context.chooseReg({destReg, op1});
        context.pushToStack({op1,op2}, instructions);
        expr1->generateMIPS(context, instructions, op1);
        expr2->generateMIPS(context, instructions, op2);
        std::string skipper = context.makeALabel("skip");

        instructions.push_back({"addi", regMap[destReg], regMap[$0],"", 0, Instruction::SSN});              //assign 0 by default
        instructions.push_back({"sub", regMap[op1], regMap[op1], regMap[op2], 0, Instruction::SSS});        //sub op2 from op1
        instructions.push_back({"blez", regMap[op1], skipper, "", 0, Instruction::SS});                     //if difference is not positive, op1 is smaller
        //branch delay slot nop
        instructions.push_back({"addi", regMap[destReg], regMap[$0],"", 1, Instruction::SSN});              //gets skipped if branch was true
        instructions.push_back({"irrelevant", skipper, "", "", 0, Instruction::L});

        context.pullFromStack({op2,op1}, instructions);
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

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) { //TODO: CHECK
        int op1 = context.chooseReg({destReg});
        int op2 = context.chooseReg({destReg, op1});
        context.pushToStack({op1,op2}, instructions);
        expr1->generateMIPS(context, instructions, op1);
        expr2->generateMIPS(context, instructions, op2);
        std::string skipper = context.makeALabel("skip");

        instructions.push_back({"addi", regMap[destReg], regMap[$0],"", 0, Instruction::SSN});              //assign 0 by default
        instructions.push_back({"sub", regMap[op1], regMap[op1], regMap[op2], 0, Instruction::SSS});        //sub op2 from op1
        instructions.push_back({"bgtz", regMap[op1], skipper, "", 0, Instruction::SS});                     //if difference is positive, op1 is larger
        //branch delay slot nop
        instructions.push_back({"addi", regMap[destReg], regMap[$0],"", 1, Instruction::SSN});              //gets skipped if branch was true
        instructions.push_back({"irrelevant", skipper, "", "", 0, Instruction::L});

        context.pullFromStack({op2,op1}, instructions);
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
    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        int op1 = context.chooseReg({destReg});
        int op2 = context.chooseReg({destReg, op1});
        context.pushToStack({op1,op2}, instructions);
        expr1->generateMIPS(context, instructions, op1);
        expr2->generateMIPS(context, instructions, op2);
        std::string skipper = context.makeALabel("skip");

        instructions.push_back({"addi", regMap[destReg], regMap[$0],"", 0, Instruction::SSN});              //assign 0 by default
        instructions.push_back({"sub", regMap[op1], regMap[op1], regMap[op2], 0, Instruction::SSS});        //sub op2 from op1
        instructions.push_back({"bltz", regMap[op1], skipper, "", 0, Instruction::SS});                     //if difference is negative, op1 is smaller
        //branch delay slot nop
        instructions.push_back({"addi", regMap[destReg], regMap[$0],"", 1, Instruction::SSN});              //gets skipped if branch was true
        instructions.push_back({"irrelevant", skipper, "", "", 0, Instruction::L});

        context.pullFromStack({op2,op1}, instructions);
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

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        int op1 = context.chooseReg({destReg});
        int op2 = context.chooseReg({destReg, op1});
        if (expr1 != NULL && expr2 != NULL) {
            context.pushToStack({op1,op2}, instructions);
            expr1->generateMIPS(context, instructions, op1);
            expr2->generateMIPS(context, instructions, op2);
            std::string skipper = context.makeALabel("skip");

            instructions.push_back({"addi", regMap[destReg], regMap[$0], "", 0, Instruction::SSN});     //0 into destreg by default
            instructions.push_back({"bne", regMap[op1], regMap[op2], skipper, 0, Instruction::SSN});    //if not equal, we shouldn't set to 1
            //branch delay slot nop
            instructions.push_back({"addi", regMap[destReg], regMap[$0],"", 1, Instruction::SSN});      //gets skipped if branch was true
            instructions.push_back({"irrelevant", skipper, "", "", 0, Instruction::L});                 //skips to this label

            context.pullFromStack({op2,op1}, instructions);
        }
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

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) { //TODO: Check

        //signed, unsigned comparison?
        int op1 = context.chooseReg({destReg});
        int op2 = context.chooseReg({destReg, op1});
        if (expr1 != NULL && expr2 != NULL) {
            context.pushToStack({op1,op2}, instructions);
            expr1->generateMIPS(context, instructions, op1);
            expr2->generateMIPS(context, instructions, op2);
            std::string skipper = context.makeALabel("skip");

            instructions.push_back({"addi", regMap[destReg], regMap[$0], "", 0, Instruction::SSN});     //0 into destreg by default
            instructions.push_back({"beq", regMap[op1], regMap[op2], skipper, 0, Instruction::SSN});    //if equal, we shouldn't set to 1
            //branch delay slot nop
            instructions.push_back({"addi", regMap[destReg], regMap[$0],"", 1, Instruction::SSN});      //gets skipped if branch was true
            instructions.push_back({"irrelevant", skipper, "", "", 0, Instruction::L});                 //skips to this label

            context.pullFromStack({op2,op1}, instructions);
        }
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

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        int op1 = context.chooseReg({destReg});
        int op2 = context.chooseReg({destReg, op1});
        context.pushToStack({op1,op2}, instructions);
        expr1->generateMIPS(context, instructions, op1);
        expr2->generateMIPS(context, instructions, op2);
        //and destreg, op1, op2
        instructions.push_back({"and", regMap[destReg], regMap[op1], regMap[op2], 0, Instruction::SSS});
        context.pullFromStack({op2,op1}, instructions);
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

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        int op1 = context.chooseReg({destReg});
        int op2 = context.chooseReg({destReg, op1});
        if (expr1 != NULL && expr2 != NULL) {
            context.pushToStack({op1, op2}, instructions);
            expr1->generateMIPS(context, instructions, op1);
            expr2->generateMIPS(context, instructions, op2);

            //and destreg, op1, op2
            instructions.push_back({"xor", regMap[destReg], regMap[op1], regMap[op2], 0, Instruction::SSS});

            context.pullFromStack({op2,op1}, instructions);
        }
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

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        //evaluate expr1 and 2
        //OR into destreg
        int op1 = context.chooseReg({destReg});
        int op2 = context.chooseReg({destReg, op1});
        if (expr1 != NULL && expr2 != NULL) {
            context.pushToStack({op1, op2}, instructions);
            expr1->generateMIPS(context, instructions, op1);
            expr2->generateMIPS(context, instructions, op2);

            //and destreg, op1, op2
            instructions.push_back({"or", regMap[destReg], regMap[op1], regMap[op2], 0, Instruction::SSS});
            context.pullFromStack({op2,op1}, instructions);
        }
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

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) { 
        //evaluate expr1 and 2
        //1 into destreg if either operand is positive?
        int op1 = context.chooseReg({destReg});
        int op2 = context.chooseReg({destReg, op1});
        if (expr1 != NULL && expr2 != NULL) {
            context.pushToStack({op1,op2}, instructions);
            expr1->generateMIPS(context, instructions, op1);
            expr2->generateMIPS(context, instructions, op2);

            //slt op1, $0, op1
            instructions.push_back({"slt", regMap[op1], "$0", regMap[op1], 0, Instruction::SSS});
            //slt op2, $0, op2
            instructions.push_back({"slt", regMap[op2], "$0", regMap[op2], 0, Instruction::SSS});
            //and destreg, op1, op2
            instructions.push_back({"and", regMap[destReg], regMap[op1], regMap[op2], 0, Instruction::SSS});

            context.pullFromStack({op2,op1}, instructions);
        }
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

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) { //TODO: SHORT CIRCUITING
        //evaluate expr1 and 2
        //1 into destreg if either operand is positive?
        int op1 = context.chooseReg({destReg});         
        int op2 = context.chooseReg({destReg, op1});
        if (expr1 != NULL && expr2 != NULL) {
            context.pushToStack({op1,op2}, instructions);
            expr1->generateMIPS(context, instructions, op1);
            expr2->generateMIPS(context, instructions, op2);

            //slt destReg, $0, op1
            instructions.push_back({"slt", regMap[op1], regMap[$0], regMap[op1], 0, Instruction::SSS});
            //slt destReg, $0, op2
            instructions.push_back({"slt", regMap[op2], regMap[$0], regMap[op2], 0, Instruction::SSS});
            //slt destReg, $0, op2
            instructions.push_back({"or", regMap[destReg], regMap[op1], regMap[op2], 0, Instruction::SSS});

            context.pullFromStack({op2,op1}, instructions);
        }
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

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) { 
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

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0) {
        int addrHolder = context.chooseReg({destReg});
        context.pushToStack({addrHolder}, instructions);

        expr1->address(addrHolder, context, instructions);
        expr2->generateMIPS(context, instructions, destReg);
        instructions.push_back({"sw", regMap[destReg], regMap[addrHolder], "", 0, Instruction::LS});

        context.pullFromStack({addrHolder}, instructions);
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

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0){
        int addrHolder = context.chooseReg({destReg});              //hold address of LHS
        int RHS = context.chooseReg({destReg, addrHolder});         //holds value of RHS

        context.pushToStack({addrHolder, RHS}, instructions);
        expr1->address(addrHolder, context, instructions);
        expr1->generateMIPS(context, instructions, destReg);
        expr2->generateMIPS(context, instructions, RHS);

        if(expr1->isPointer(context) && !expr2->isPointer(context)){
            instructions.push_back({"sll", regMap[RHS], regMap[RHS], "", 4, Instruction::SSN});
        }
        instructions.push_back({"add", regMap[destReg], regMap[destReg], regMap[RHS], 0, Instruction::SSS});
        instructions.push_back({"sw", regMap[destReg], regMap[addrHolder], "", 0, Instruction::LS});
        context.pullFromStack({RHS, addrHolder}, instructions);
    }

    bool isPointer(CompContext &context){
        return expr1->isPointer(context) || expr2->isPointer(context);
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

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0){
        int addrHolder = context.chooseReg({destReg});              //hold address of LHS
        int RHS = context.chooseReg({destReg, addrHolder});         //holds value of RHS

        context.pushToStack({addrHolder, RHS}, instructions);
        expr1->address(addrHolder, context, instructions);
        expr1->generateMIPS(context, instructions, destReg);
        expr2->generateMIPS(context, instructions, RHS);

        if(expr1->isPointer(context) && !expr2->isPointer(context)){
            instructions.push_back({"sll", regMap[RHS], regMap[RHS], "", 4, Instruction::SSN});
        }
        instructions.push_back({"sub", regMap[destReg], regMap[destReg], regMap[RHS], 0, Instruction::SSS});
        instructions.push_back({"sw", regMap[destReg], regMap[addrHolder], "", 0, Instruction::LS});
        context.pullFromStack({RHS, addrHolder}, instructions);
    }

    bool isPointer(CompContext &context){
        return expr1->isPointer(context) || expr2->isPointer(context);
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

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0){
        int addrHolder = context.chooseReg({destReg});              //hold address of LHS
        int RHS = context.chooseReg({destReg, addrHolder});         //holds value of RHS

        context.pushToStack({addrHolder, RHS}, instructions);
        expr1->address(addrHolder, context, instructions);
        expr1->generateMIPS(context, instructions, destReg);
        expr2->generateMIPS(context, instructions, RHS);

        instructions.push_back({"mul", regMap[destReg], regMap[RHS], "", 0, Instruction::SSS});
        instructions.push_back({"mflo", regMap[destReg], "", "", 0, Instruction::S});
        instructions.push_back({"sw", regMap[destReg], regMap[addrHolder], "", 0, Instruction::LS});
        context.pullFromStack({RHS, addrHolder}, instructions);
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

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0){
        int addrHolder = context.chooseReg({destReg});              //hold address of LHS
        int RHS = context.chooseReg({destReg, addrHolder});         //holds value of RHS

        context.pushToStack({addrHolder, RHS}, instructions);
        expr1->address(addrHolder, context, instructions);
        expr1->generateMIPS(context, instructions, destReg);
        expr2->generateMIPS(context, instructions, RHS);

        instructions.push_back({"div", regMap[destReg], regMap[RHS], "", 0, Instruction::SSS});
        instructions.push_back({"mflo", regMap[destReg], "", "", 0, Instruction::S});
        instructions.push_back({"sw", regMap[destReg], regMap[addrHolder], "", 0, Instruction::LS});
        context.pullFromStack({RHS, addrHolder}, instructions);
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

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0){
        int addrHolder = context.chooseReg({destReg});              //hold address of LHS
        int RHS = context.chooseReg({destReg, addrHolder});         //holds value of RHS

        context.pushToStack({addrHolder, RHS}, instructions);
        expr1->address(addrHolder, context, instructions);
        expr1->generateMIPS(context, instructions, destReg);
        expr2->generateMIPS(context, instructions, RHS);

        instructions.push_back({"div", regMap[destReg], regMap[RHS], "", 0, Instruction::SSS});
        instructions.push_back({"mfhi", regMap[destReg], "", "", 0, Instruction::S});
        instructions.push_back({"sw", regMap[destReg], regMap[addrHolder], "", 0, Instruction::LS});
        context.pullFromStack({RHS, addrHolder}, instructions);
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

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0){
        int addrHolder = context.chooseReg({destReg});              //hold address of LHS
        int RHS = context.chooseReg({destReg, addrHolder});         //holds value of RHS

        context.pushToStack({addrHolder, RHS}, instructions);
        expr1->address(addrHolder, context, instructions);
        expr1->generateMIPS(context, instructions, destReg);
        expr2->generateMIPS(context, instructions, RHS);

        instructions.push_back({"sllv", regMap[destReg], regMap[destReg], regMap[RHS], 0, Instruction::SSS});
        instructions.push_back({"sw", regMap[destReg], regMap[addrHolder], "", 0, Instruction::LS});
        context.pullFromStack({RHS, addrHolder}, instructions);
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

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0){
        int addrHolder = context.chooseReg({destReg});              //hold address of LHS
        int RHS = context.chooseReg({destReg, addrHolder});         //holds value of RHS

        context.pushToStack({addrHolder, RHS}, instructions);
        expr1->address(addrHolder, context, instructions);
        expr1->generateMIPS(context, instructions, destReg);
        expr2->generateMIPS(context, instructions, RHS);

        instructions.push_back({"srav", regMap[destReg], regMap[destReg], regMap[RHS], 0, Instruction::SSS});
        instructions.push_back({"sw", regMap[destReg], regMap[addrHolder], "", 0, Instruction::LS});
        context.pullFromStack({RHS, addrHolder}, instructions);
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

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0){
        int addrHolder = context.chooseReg({destReg});              //hold address of LHS
        int RHS = context.chooseReg({destReg, addrHolder});         //holds value of RHS

        context.pushToStack({addrHolder, RHS}, instructions);
        expr1->address(addrHolder, context, instructions);
        expr1->generateMIPS(context, instructions, destReg);
        expr2->generateMIPS(context, instructions, RHS);

        instructions.push_back({"and", regMap[destReg], regMap[destReg], regMap[RHS], 0, Instruction::SSS});
        instructions.push_back({"sw", regMap[destReg], regMap[addrHolder], "", 0, Instruction::LS});
        context.pullFromStack({RHS, addrHolder}, instructions);
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

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0){
        int addrHolder = context.chooseReg({destReg});              //hold address of LHS
        int RHS = context.chooseReg({destReg, addrHolder});         //holds value of RHS

        context.pushToStack({addrHolder, RHS}, instructions);
        expr1->address(addrHolder, context, instructions);
        expr1->generateMIPS(context, instructions, destReg);
        expr2->generateMIPS(context, instructions, RHS);

        instructions.push_back({"or", regMap[destReg], regMap[destReg], regMap[RHS], 0, Instruction::SSS});
        instructions.push_back({"sw", regMap[destReg], regMap[addrHolder], "", 0, Instruction::LS});
        context.pullFromStack({RHS, addrHolder}, instructions);
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

    void generateMIPS(CompContext &context, std::vector<Instruction> &instructions, char destReg = 0){
        int addrHolder = context.chooseReg({destReg});              //hold address of LHS
        int RHS = context.chooseReg({destReg, addrHolder});         //holds value of RHS

        context.pushToStack({addrHolder, RHS}, instructions);
        expr1->address(addrHolder, context, instructions);
        expr1->generateMIPS(context, instructions, destReg);
        expr2->generateMIPS(context, instructions, RHS);

        instructions.push_back({"xor", regMap[destReg], regMap[destReg], regMap[RHS], 0, Instruction::SSS});
        instructions.push_back({"sw", regMap[destReg], regMap[addrHolder], "", 0, Instruction::LS});
        context.pullFromStack({RHS, addrHolder}, instructions);
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
        int tempReg = context.chooseReg({destReg});
        context.pushToStack({tempReg}, instructions);
        int offset = context.funcCallFlags().argNum * 4;
        context.funcCallFlags().argNum++;
        expr->generateMIPS(context, instructions, tempReg);
        instructions.push_back({"sw", regMap[tempReg], regMap[$sp], "", offset, Instruction::LS});
        context.pullFromStack({tempReg}, instructions);
    }

protected:
    BaseExpression *expr;
};

#endif