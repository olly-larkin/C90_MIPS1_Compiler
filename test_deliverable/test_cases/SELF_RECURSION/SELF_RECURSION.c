
int func(int num) {
    if (num == 0)
        return 0;
    int x = func(num - 1);
    return x;
}