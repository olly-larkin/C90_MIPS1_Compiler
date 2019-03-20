
//should increase until num2, unless num1 == num2, then i = 10
int func(int num1, int num2) {     
    int i = 0;
    while(i < 11) {
        if (i == num1)
            continue;
        if (i == num2)
            break;
        ++i;
    }
    return i;
}