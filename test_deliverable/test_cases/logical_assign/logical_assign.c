int func(){ //OR
    int x = 0xA;
    x |= 0x5;
    return x;
}

int funk(){ //AND
    int x = 0xF0;
    x &= 0xF0;
    return x;
}

int fonc(){ //XOR
    int x = 0x0F;
    x ^= 0xF0;
    return x;
}