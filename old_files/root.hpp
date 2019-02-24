#ifndef ROOT_HPP
#define ROOT_HPP

#include <iostream>
#include <string>

class AST {
public:
    virtual ~AST() {}
    virtual void print(std::ostream& dst, int level) const = 0;
    virtual std::string name() = 0;
protected:
    static std::string multiStr(int num, const std::string& str) {
        if (num < 2)
            return str;
        else
            return multiStr(num-1, str) + str;
    }
};

#endif