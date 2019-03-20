int positive_check(){
    int op1 = 0xA, op2 = 0x5;
    return (op1 | op2) + (0 | 0);
}

int negative_check(){
    int op1 = 0xff, op2 = 0;
    return (op1 & op2) + (op1 | op2);
}
//TODO: short circuiting checks with pointers