#ifndef LEXCONTEXT_HPP
#define LEXCONTEXT_HPP

#include <iostream>
#include <vector>

struct LexContext {

    struct info {
        std::vector<std::string> typeDef;
        bool typeDefActive = false;
        bool declarationActive = false;
    };

    std::vector<info> stack = {{}};

    int scopeLevel = 0;
    bool typeDefed(const std::string& str) {
        for(int i = 0; i < (int)stack.back().typeDef.size(); i++) {
            if (stack.back().typeDef[i] == str)
                return true;
        }
        return false;
    }
    bool findAndDestroy(const std::string& str) {
        for(auto i = stack.back().typeDef.begin(); i != stack.back().typeDef.end(); ++i) {
            if (*i == str) {
                stack.back().typeDef.erase(i);
                return true;
            }
        }
        return false;
    }

    void addScope() {
        scopeLevel++;
        stack.push_back(stack.back());
    }
    void subScope() {
        scopeLevel--;
        stack.pop_back();
    }

    std::string currentName;

    bool& declarationActive() { return stack.back().declarationActive; }
    bool& typeDefActive() { return stack.back().typeDefActive; }

    void addTypeDef(const std::string& str) {
        stack.back().typeDef.push_back(str);
    }
};

#endif