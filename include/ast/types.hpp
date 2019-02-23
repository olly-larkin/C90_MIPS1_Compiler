#ifndef TYPES_HPP
#define TYPES_HPP

#include <iostream>
#include <vector>

enum Storage_Class_Specifier {
    Extern,
    Static,
    Auto,
    Register
};

enum Type_Specifier {
    Void,
    Char,
    Short,
    Int,
    Long,
    Float,
    Double,
    Signed,
    Unsigned,
    Typedef_T
};

enum Type_Qualifier {
    Const,
    Volatile,
};

class Type {
public:
    virtual std::string printStr() const = 0;
};

class BasicType : public Type {
public:
    BasicType() {}
    BasicType(const std::vector<Type_Qualifier>& t_q_, const std::vector<Storage_Class_Specifier>& s_c_s_, const std::vector<Type_Specifier>& t_s_)
        : t_q(t_q_), s_c_s(s_c_s_), t_s(t_s_)
        {}
    std::string printStr() const {
        std::string retStr = "";
        for(int i = 0; i < (int)t_q.size(); i++) {
            switch(t_q[i]) {
                case Const:
                    retStr += "const";
                    break;
                case Volatile:
                    retStr += "volatile";
                    break;
                default:;
            }
            retStr += " ";
        }
        for(int i = 0; i < (int)s_c_s.size(); i++) {
            switch(s_c_s[i]) {
                case Extern:
                    retStr += "extern";
                    break;
                case Static:
                    retStr += "static";
                    break;
                case Auto:
                    retStr += "auto";
                    break;
                case Register:
                    retStr += "register";
                    break;
                default:;
            }
            retStr += " ";
        }
        for(int i = 0; i < (int)t_s.size(); i++) {
            switch(t_s[i]) {
                case Void:
                    retStr += "void";
                    break;
                case Char:
                    retStr += "char";
                    break;
                case Short:
                    retStr += "short";
                    break;
                case Int:
                    retStr += "int";
                    break;
                case Long:
                    retStr += "long";
                    break;
                case Float:
                    retStr += "float";
                    break;
                case Double:
                    retStr += "double";
                    break;
                case Signed:
                    retStr += "signed";
                    break;
                case Unsigned:
                    retStr += "unsigned";
                    break;
                case Typedef_T:
                    retStr += "typedef_t";
                    break;
                default:;
            }
            retStr += " ";
        }
        return retStr;
    }
    void push_back_scs(Storage_Class_Specifier s_c_s_) { s_c_s.push_back(s_c_s_); }
    void push_back_ts(Type_Specifier t_s_) { t_s.push_back(t_s_); }
    void push_back_tq(Type_Qualifier t_q_) { t_q.push_back(t_q_); }
private:
    std::vector<Type_Qualifier> t_q;
    std::vector<Storage_Class_Specifier> s_c_s;
    std::vector<Type_Specifier> t_s;
};

class StructType : public Type {
public:
private:
};

class EnumType : public Type {
public:
private:
};

#endif