#include <stdio.h>

typedef int (*fp)(int, int);

int add(int a, int b)
{
    printf("%d\n", a+b);
    return a+b;
}

int sub(int a, int b)
{
    printf("%d\n", a - b);
    return a-b;
}
int main(void)
{
    int (*fp1) (int, int);
    fp1 = add;
    fp a = add;
    a = sub;
    a(1,2);
    fp1(1,2);
    return 0;
}