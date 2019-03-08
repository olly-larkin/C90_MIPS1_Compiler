#ifndef AST_BASE_CLASSES_HPP
#define AST_BASE_CLASSES_HPP

class BaseNode : public AST {
public:
protected:
};

class BaseList : public AST {
public:
    BaseList(BaseList *_list) : list(_list) {}
    virtual ~BaseList() {
        if (list != NULL)
            delete list;
    }
protected:
    BaseList *list;
};

class BaseExpression : public AST {
public:
protected:
};

class BaseExpressionList : public AST {
public:
    BaseExpressionList(BaseExpressionList *_list) : list(_list) {}
    virtual ~BaseExpressionList() {
        if (list != NULL)
            delete list;
    }
protected:
    BaseExpressionList *list;
};

#endif