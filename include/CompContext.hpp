#ifndef COMPCONTEXT_HPP
#define COMPCONTEXT_HPP

enum typeEnum {
    VOID_T,
    CHAR_T,
    SHORT_T,
    INT_T,
    LONG_T,
    FLOAT_T,
    DOUBLE_T,
    SIGNED_T,
    UNSIGNED_T
}; 

struct CompContext {

};

struct Instruction {
    std::string name;
    std::string arg1, arg2, arg3;
    long unsigned int number;
    enum { SSS, SSN, SN, SS, S, N, LS, E, L } printMethod;
};

#endif

