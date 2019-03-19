
int func(int num) {
    if (num == 0)
        return 0;
    return func(num - 1);
}