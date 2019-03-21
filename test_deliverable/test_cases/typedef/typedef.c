
typedef int* test;

int func() {
	int x = 5;
	test a = &x;
	return *a;
}
