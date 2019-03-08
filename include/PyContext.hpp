#ifndef PYCONTEXT_HPP
#define PYCONTEXT_HPP

struct PyContext{
    int scope_level = 0;

    bool globalDec = false;
    bool declaration = false;

    std::vector<std::string> globals;

    std::string indentPy(){
        std::string temp;
        for(int i=0; i<scope_level; i++)
            temp += "\t";
        return temp;
    }

    void addScope(){
        scope_level++;
    }

    void addScopeFunc(std::ostream &os) {
        addScope();
        for(int i=0; i<(int)globals.size(); i++){
            os << indentPy() << "global " << globals[i] << std::endl;
        }
    }

    void subScope(){
        scope_level--;
    }
};

#endif