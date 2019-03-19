
int func2() {
    return 1;
}

int func() {
    int result = 5;
    result = func2();
    return result;
}