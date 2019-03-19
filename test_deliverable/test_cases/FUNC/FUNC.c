
int func2() {
    return 1;
}

int func() {
    int result = 5;
    result = 1 - func2();
    return result;
}