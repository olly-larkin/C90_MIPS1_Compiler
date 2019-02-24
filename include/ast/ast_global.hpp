#ifndef AST_GLOBAL_HPP
#define AST_GLOBAL_HPP

#include <vector>

#include "root.hpp"

class TopLevel : public AST {};

class Global : public AST {
public:
    virtual void print(std::ostream& dst, int level) const {
        for(auto i = branches.begin(); i != branches.end(); ++i) {
            dst << multiStr(level, "\t") << (*i)->name() << std::endl;
            (*i)->print(dst,level+1);
        }
    }
    virtual std::string name() { return "Global"; }
    void push_back(TopLevel* branch) { branches.push_back(branch); }
    Global() {}
    Global(TopLevel* branch) : branches({branch}) {} 
protected:
    std::vector<TopLevel*> branches;
};

#endif