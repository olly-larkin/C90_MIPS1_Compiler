
int func2(int num) {
    switch(num) {
        case 1: return 1;
        case 2: return 2;
        case 3: return 3;
        default: return 4;
    }
}

int func() {
    return func2(1) + func2(3) - func2(20);
}