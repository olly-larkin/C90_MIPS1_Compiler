#include "ast.hpp"
#include <iostream>

std::string print_CType(CType val) {
    switch(val) {
        case BOOL:      return "bool";
        case CHAR:      return "char";
        case DOUBLE:    return "double";
        case FLOAT:     return "float";
        case INT:       return "int";
        case LONG:      return "long";
        case REGISTER:  return "register";
        case SHORT:     return "short";
        case SIGNED:    return "signed";
        case UNSIGNED:  return "unsigned";
        case VOID:      return "void";
        default:        return "error";
    }
}