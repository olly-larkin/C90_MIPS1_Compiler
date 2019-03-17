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

    int size() {
        if (list != NULL)
            return 1 + list->size();
        else 
            return 1;
    }

    BaseList* at(int i) {       // iterates from the back
        if (i == 0)
            return this;
        else if (list != NULL)
            return list->at(i-1);
        else
            return NULL;
    }

protected:
    BaseList *list;
};

class BaseExpression : public AST {
public:
    virtual double eval() { return 0; }
    struct offsetRet {
        int offset;
        std::string label;
        bool global;
    };
    virtual offsetRet offset(CompContext &context) { return {0, "", false}; }
protected:
};

class BaseExpressionList : public AST {
public:
    BaseExpressionList(BaseExpressionList *_list) : list(_list) {}
    virtual ~BaseExpressionList() {
        if (list != NULL)
            delete list;
    }

    int size() {
        if (list != NULL)
            return 1 + list->size();
        else 
            return 1;
    }

    BaseExpressionList* at(int i) {
        if (i == 0)
            return this;
        else if (list != NULL)
            return list->at(i-1);
        else
            return NULL;
    }

    virtual double eval() { return 0; }

protected:
    BaseExpressionList *list;
};

#endif