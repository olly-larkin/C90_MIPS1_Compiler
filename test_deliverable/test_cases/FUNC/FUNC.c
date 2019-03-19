
int func2(int num) {
    return num;
}

int func(int num) {
    int result = 5;
    result = func2(num - 1);
    return result;
}